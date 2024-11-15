/*






*/

#define FUNCTION_READ_STR

/*
Vytvoří hlavičku funkce
(label,pushframe)
@param function_id název začínající funkce
*/
bool generate_function_start(char *function_id)
{
    ADD_CODE("\n# Start of function ");
    ADD_CODE(function_id);
    ADD_CODE("\n");

    ADD_CODE("LABEL $");
    ADD_CODE(function_id);
    ADD_CODE("\n");
    ADD_INST("PUSHFRAME");

    return true;
}

/*
Vytvoří závěr funkce
(label,pushframe)
@param function_id název končící funkce
*/
bool generate_function_end(char *function_id)
{
    ADD_CODE("# End of function ");
    ADD_CODE(function_id);
    ADD_CODE("\n");

    ADD_INST("POPFRAME");
    ADD_INST("RETURN");

    return true;
}

/*

*/
pub fn ifj.readstr() ? [] u8 {

};

/*

*/
pub fn ifj.readstr() ? i32{

                       };
