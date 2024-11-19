#include <stdio.h>

#include "dynamic_string.h"
#include "types.h"
#include "generator.h"
#include "built_in_function.h"

Dynamic_string dyn_str;
operation op;
stack_operation st_op;
const char *function_id = "skibidi";
int label_depth = 1;
int label_index = 22;

#define MAX_DIGITS 40

#define ADD_LINE(_line)                                        \
    if (!dynamic_string_add_const_str(&dyn_str, ("\n" _line))) \
    return false

#define ADD_TOLINE(_to)                               \
    if (!dynamic_string_add_const_str(&dyn_str, _to)) \
    return false

#define ADD_INT(_to)             \
    do                           \
    {                            \
        char str[MAX_DIGITS];    \
        sprintf(str, "%d", _to); \
        ADD_TOLINE(str);         \
    } while (0)

bool gen_header()
{
    ADD_LINE("#Start of the program");
    ADD_LINE(".IFJCode24");

    ADD_LINE("DEFVAR GF@%temp1");
    ADD_LINE("DEFVAR GF@%temp2");
    ADD_LINE("DEFVAR GF@%temp3");

    ADD_LINE("DEFVAR GF@%exp_result");

    ADD_LINE("JUMP $main");

    return true;
}

bool gen_main_start()
{
    ADD_LINE("\n#Main start");
    ADD_LINE("LABEL $main");
    ADD_LINE("CREATEFRAME");
    ADD_LINE("PUSHFRAME");
    return true;
}

bool gen_main_end()
{
    ADD_LINE("\n#Main end");
    ADD_LINE("POPFRAME");
    ADD_LINE("CLEARS");
    return true;
}

bool gen_built_in_function()
{
    ADD_LINE(FUNCTION_READ_STR);
    ADD_LINE(FUNCTION_READ_I32);
    ADD_LINE(FUNCTION_READ_F64);
    ADD_LINE(FUNCTION_WRITE);
    ADD_LINE(FUNCTION_I2F);
    ADD_LINE(FUNCTION_F2I);
    ADD_LINE(FUNCTION_STRING);
    ADD_LINE(FUNCTION_LENGTH);
    ADD_LINE(FUNCTION_CONCAT);
    ADD_LINE(FUNCTION_SUBSTRING);
    ADD_LINE(FUNCTION_STRCMP);
    ADD_LINE(FUNCTION_ORD);
    ADD_LINE(FUNCTION_CHR);
    return true;
}

bool gen_label(const char *function_id, int label_depth, int label_index)
{
    ADD_LINE("LABEL $");
    ADD_TOLINE(function_id);
    ADD_TOLINE("%");
    ADD_INT(label_depth);
    ADD_TOLINE("%");
    ADD_INT(label_index);
    ADD_TOLINE("\n");

    return true;
}

bool gen_function_start()
{
    ADD_LINE("#Function start");
    ADD_TOLINE("LABEL $");
    ADD_TOLINE(function_id);
    ADD_TOLINE("\n");
    ADD_LINE("PUSHFRAME");
    return true;
}

bool gen_function_end()
{
    ADD_LINE("#Function end");
    ADD_LINE("POPFRAME");
    ADD_LINE("RETURN");
    ADD_LINE("CLEARS");
    return true;
}

bool gen_call(const char *function_id)
{
    ADD_LINE("CALL $");
    ADD_TOLINE(function_id);
    ADD_TOLINE("\n");
    return true;
}

bool gen_if_start(const char *function_id)
{
    ADD_LINE("\n#If start");
    ADD_TOLINE("JUMPIFNEQ $");
    ADD_TOLINE(function_id);
    ADD_LINE(" GF%exp_result bool@true\n");

    return true;
}

bool gen_if_else()
{
    return true;
}

bool gen_if_end()
{
    ADD_LINE("\n#If end");

    return true;
}

bool gen_operation(operation op)
{
    switch (op)
    {
    case PLUS:
        ADD_LINE("ADD");
        break;

    case MINUS:
        ADD_LINE("SUB");
        break;

    case TIMES:
        ADD_LINE("MUL");
        break;

    case DIVIDE:
        ADD_LINE("DIV");
        break;

    case IDIV:
        ADD_LINE("IDIV");
        break;

    case EQUAL:
        ADD_LINE("EQ");
        break;

    case NOTEQUAL:
        ADD_LINE("EQ");
        ADD_LINE("NOT");
        break;

    case LESS:
        ADD_LINE("LT");
        break;

    case GREATER:
        ADD_LINE("GT");
        break;

    case LESSOREQUAL:

        break;

    case GREATEROREQUAL:

        break;

    default:
        break;
    }

    return true;
}

bool gen_stack_operation(stack_operation st_op)
{
    switch (st_op)
    {
    case S_PLUS:
        ADD_LINE("ADDS");
        break;

    case S_MINUS:
        ADD_LINE("SUBS");
        break;

    case S_TIMES:
        ADD_LINE("MULS");
        break;

    case S_DIVIDE:
        ADD_LINE("DIVS");
        break;

    case S_IDIV:
        ADD_LINE("IDIVS");
        break;

    case S_EQUAL:
        ADD_LINE("EQS");
        break;

    case S_NOTEQUAL:
        ADD_LINE("EQS");
        ADD_LINE("NOTS");
        break;

    case S_LESS:
        ADD_LINE("LTS");
        break;

    case S_GREATER:
        ADD_LINE("GTS");
        break;

    case S_LESSOREQUAL:
        ADD_LINE("POPS GF@tmp_2");
        ADD_LINE("POPS GF@tmp_1");
        ADD_LINE("PUSHS GF@tmp_2");
        ADD_LINE("PUSHS GF@tmp_1");
        ADD_LINE("LTS");
        ADD_LINE("PUSHS GF@tmp_2");
        ADD_LINE("PUSHS GF@tmp_1");
        ADD_LINE("EQS");
        ADD_LINE("ORS");
        break;

    case S_GREATEROREQUAL:
        ADD_LINE("POPS GF@tmp_op1");
        ADD_LINE("POPS GF@tmp_op2");
        ADD_LINE("PUSHS GF@tmp_op2");
        ADD_LINE("PUSHS GF@tmp_op1");
        ADD_LINE("GTS");
        ADD_LINE("PUSHS GF@tmp_op2");
        ADD_LINE("PUSHS GF@tmp_op1");
        ADD_LINE("EQS");
        ADD_LINE("ORS");
        break;

    default:
        break;
    }

    return true;
}
