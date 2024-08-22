#include "LinkedList/LinkedList.h"

#include <stdlib.h>
#include <string.h>

struct linked_list *linked_list_init();

void *safe_malloc(size_t size);

struct linked_list *linked_list_init() {
        struct linked_list *linked_list = safe_malloc(sizeof(struct linked_list));
        linked_list->size = sizeof(void *);
        linked_list->e = NULL;
        linked_list->next = NULL;
        return linked_list;
}

struct linked_list *new_linked_list(const int size, const void *e) {
        struct linked_list *linked_list = safe_malloc(sizeof(struct linked_list));
        linked_list->size = size;
        linked_list->e = safe_malloc(size);
        memcpy(linked_list->e, e, size);
        linked_list->next = NULL;
        return linked_list;
}

void get_element(const struct linked_list *this, void *dst) {
        if (this == NULL || dst == NULL) exit(EXIT_FAILURE);
        memcpy(dst, this->e, this->size);
}

void add(struct linked_list *this, const void *e, const int size) {
        if (this == NULL || e == NULL || size <= 0) exit(EXIT_FAILURE);
        while (this->next != NULL) {
                this = this->next;
        }
        this->next = new_linked_list(size, e);
}

void insert(struct linked_list *this, const void *e, const int size) {
        if (this == NULL || e == NULL || size <= 0) exit(EXIT_FAILURE);
        struct linked_list *linked_list = new_linked_list(size, e);
        linked_list->next = this->next;
        this->next = linked_list;
}

void remove_next(struct linked_list *this, void (*freer)(void *)) {
        if (this == NULL) exit(EXIT_FAILURE);
        struct linked_list *tmp = this->next;
        this->next = this->next->next;
        if (freer == NULL) free(tmp->e);
        else freer(tmp->e);
        free(tmp);
}

void deep_free(struct linked_list *this, void (*freer)(void *)) {
        while (this != NULL) {
                struct linked_list *tmp = this->next;
                if (freer == NULL) free(this->e);
                else freer(this->e);
                free(this);
                this = tmp;
        }
}

void *safe_malloc(const size_t size) {
        void *p = malloc(size);
        if (p == NULL) exit(EXIT_FAILURE);
        return p;
}
