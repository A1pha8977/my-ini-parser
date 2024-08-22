#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct linked_list {
        int size;
        void *e;
        struct linked_list *next;
};

struct linked_list *new_linked_list(const int size, const void *e);

void get_element(const struct linked_list *this, void *dst);

void add(struct linked_list *this, const void *e, int size);

void insert(struct linked_list *this, const void *e, int size);

void remove_next(struct linked_list *this, void (*freer)(void *));

void deep_free(struct linked_list *this, void (*freer)(void *));


#endif //LINKEDLIST_H
