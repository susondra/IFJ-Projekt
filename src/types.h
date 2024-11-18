#ifndef TYPES_H
#define TYPES_H

extern const char *function_id;
extern int label_depth;
extern int label_index;
extern char *filename;

typedef struct
{
    int value;
    char type;
} Data;

typedef enum
{
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    IDIV,
    EQUAL,
    NOTEQUAL,
    LESS,
    GREATER,
    LESSOREQUAL,
    GREATEROREQUAL
} operation;

extern operation op;

typedef enum
{
    S_PLUS,
    S_MINUS,
    S_TIMES,
    S_DIVIDE,
    S_IDIV,
    S_EQUAL,
    S_NOTEQUAL,
    S_LESS,
    S_GREATER,
    S_LESSOREQUAL,
    S_GREATEROREQUAL
} stack_operation;

extern stack_operation st_op;

extern Dynamic_string dyn_str;

#endif