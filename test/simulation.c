#include <stdio.h>
#include "dynamic_string.h"
#include "generator.h"
#include "types.h"

int main()
{

    if (!dynamic_string_init(&dyn_str, filename))
    {
        return 1;
    }

    gen_header();

    gen_main_start();
    gen_main_end();

    gen_function_start();
    gen_function_end();

    op = PLUS;

    gen_operation(op);

    op = MINUS;

    gen_operation(op);

    op = TIMES;

    gen_operation(op);

    gen_label(function_id, label_depth, label_index);

    gen_if_start(function_id);

    dynamic_string_write_to_file(&dyn_str, filename);

    /*dynamic_string_print(&dyn_str);*/

    return 0;
}
