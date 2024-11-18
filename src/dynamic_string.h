#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *str;       // Pointer to the dynamically allocated string
    size_t length;   // Current length of the string
    size_t capacity; // Current capacity of the allocated memory
} Dynamic_string;

bool dynamic_string_init(Dynamic_string *dyn_str);

bool dynamic_string_resize(Dynamic_string *dyn_str, size_t new_capacity);

bool dynamic_string_add_char(Dynamic_string *dyn_str, char c);

bool dynamic_string_add_const_str(Dynamic_string *dyn_str, const char *src);

void dynamic_string_clear(Dynamic_string *dyn_str);

void dynamic_string_free(Dynamic_string *dyn_str);

void dynamic_string_print();