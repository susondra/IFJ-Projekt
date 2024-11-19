#include <stdio.h>
#include "src/dynamic_string.h"
#include "src/generator.h"
#include "src/types.h"

int main()
{

    if (!dynamic_string_init(&dyn_str, filename))
    {
        return 1;
    }

    gen_header();
    gen_built_in_function();

    gen_main_start();
    gen_main_end();
    /*
    st_op = S_PLUS;

    gen_stack_operation(st_op);

    st_op = S_MINUS;

    gen_stack_operation(st_op);

    st_op = S_TIMES;

    gen_stack_operation(st_op);
*/
    gen_label(function_id, label_depth, label_index);

    dynamic_string_write_to_file(&dyn_str, filename);

    /*dynamic_string_print(&dyn_str);*/

    return 0;
}
