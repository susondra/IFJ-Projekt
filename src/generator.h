#include <stdbool.h>
#include "types.h"

#ifndef _GENERATOR_H
#define _GENERATOR_H

bool gen_header();

bool gen_main_start();

bool gen_main_end();

bool gen_label(const char *function_id, int label_depth, int label_index);

bool gen_function_start();

bool gen_function_end();

bool gen_call(const char *function_id);

bool gen_if_start(const char *function_id);

bool gen_if_else();

bool gen_if_end();

bool gen_while_start();

bool gen_while_end();

bool gen_operation(operation op);

bool gen_stack_operation(stack_operation st_op);

#endif