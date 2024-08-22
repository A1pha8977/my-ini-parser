#ifndef INI_PARSER_H
#define INI_PARSER_H

#include "linked-list/linked_list.h"

struct ini {
        char *name;
        struct linked_list *sections;
};

struct section {
        char *name;
        struct linked_list *keys;
};

struct key {
        char *name;
        char *value;
};



#endif //INI_PARSER_H
