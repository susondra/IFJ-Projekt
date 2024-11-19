/*






*/

/*
ze standartního vstupu načte jeden řádek ukončený odřádkováním
 nebo koncem souboru (EOF). Vrátí načtený řetězec
 bez symbolu konce řádku, při špatném formátu vrátí null
@return []u8 nebo nil@nil
*/
#define FUNCTION_READ_STR                                \
    "\n # Built-in function ifj_readstr"                 \
    "\n LABEL $ifj_readstr"                              \
    "\n PUSHFRAME"                                       \
    "\n DEFVAR LF@retval"                                \
    "\n MOVE LF@retval nil@nil"                          \
    "\n DEFVAR LF@input"                                 \
    "\n DEFVAR LF@type"                                  \
    "\n READ LF@input string"                            \
    "\n TYPE LF@type LF@input"                           \
    "\n JUMPIFNEQ ifj_readstr_end LF@type string@string" \
    "\n MOVE LF@retval LF@input"                         \
    "\n LABEL ifj_readstr_end"                           \
    "\n POPFRAME"                                        \
    "\n RETURN"

/*
#define FUNCTION_READ_STR                                    \
    "\n # Built-in function ifj_readstr"                    \
    "\n LABEL $ifj_readstr"                                  \
    "\n PUSHFRAME"                                           \
    "\n DEFVAR LF@retval"                                    \
    "\n MOVE LF@retval nil@nil"                              \
    "\n DEFVAR LF@input"                                     \
    "\n DEFVAR LF@type"                                      \
    "\n READ LF@input string"                                \
    "\n TYPE LF@type LF@input"                               \
    "\n JUMPIFNEQ ifj_readstr_end LF@type string@string"     \
    "\n DEFVAR LF@strlen"                                    \
    "\n STRLEN LF@strlen LF@input"                           \
    "\n SUB LF@strlen LF@strlen int@1"                       \
    "\n DEFVAR LF@last_char"                                 \
    "\n GETCHAR LF@last_char LF@input LF@strlen"             \
    "\n JUMPIFNEQ ifj_readstr_insert LF@last_char string@\n" \
    "\n CREATEFRAME"                                         \
    "\n DEFVAR TF@%1"                                        \
    "\n DEFVAR TF@%2"                                        \
    "\n DEFVAR TF@%3"                                        \
    "\n MOVE TF@%1 LF@input"                                 \
    "\n MOVE TF@%2 int@0"                                    \
    "\n MOVE TF@%3 LF@strlen"                                \
    "\n CALL ifj_substring"                                  \
    "\n MOVE LF@input TF@retval"                             \
    "\n LABEL ifj_readstr_insert"                            \
    "\n MOVE LF@retval LF@input"                             \
    "\n LABEL ifj_readstr_end"                               \
    "\n POPFRAME"                                            \
    "\n RETURN"
*/
/*
ze standartního vstupu načte jeden řádek ukončený odřádkováním
 nebo koncem souboru (EOF). Vrátí celočíselnou hodnotu
 pokud byla na vstupu platná (neprázdná) f64/i32 hodnota
 (pokud f64, převede na i32 odříznutím desetinné části),
 jinak vrátí null
@return i32 nebo nil@nil
*/
#define FUNCTION_READ_I32                             \
    "\n # Built-in function ifj_readi32"              \
    "\n LABEL $ifj_readi32"                           \
    "\n PUSHFRAME"                                    \
    "\n DEFVAR LF@retval"                             \
    "\n MOVE LF@retval nil@nil"                       \
    "\n DEFVAR LF@input"                              \
    "\n DEFVAR LF@type"                               \
    "\n READ LF@input int"                            \
    "\n TYPE LF@type LF@input"                        \
    "\n JUMPIFNEQ ifj_readi32_end LF@type string@int" \
    "\n MOVE LF@retval LF@input"                      \
    "\n LABEL ifj_readi32_end"                        \
    "\n POPFRAME"                                     \
    "\n RETURN"

/*
ze standartního vstupu načte jeden řádek ukončený odřádkováním
 nebo koncem souboru (EOF). Vrátí desetinnou hodnotu
 pokud byla na vstupu platná (neprázdná) f64 hodnota,
 jinak vrátí null
@return f64 nebo nil@nil
*/
#define FUNCTION_READ_F64                               \
    "\n # Built-in function ifj_readf64"                \
    "\n LABEL $ifj_readf64"                             \
    "\n PUSHFRAME"                                      \
    "\n DEFVAR LF@retval"                               \
    "\n MOVE LF@retval nil@nil"                         \
    "\n DEFVAR LF@input"                                \
    "\n DEFVAR LF@type"                                 \
    "\n READ LF@input float"                            \
    "\n TYPE LF@type LF@input"                          \
    "\n JUMPIFNEQ ifj_readf64_end LF@type string@float" \
    "\n MOVE LF@retval LF@input"                        \
    "\n LABEL ifj_readf64_end"                          \
    "\n POPFRAME"                                       \
    "\n RETURN"

/*
vypíše hodnotu termu na standartní výstup ihned
 a bez žádných oddělovačů dle typu v patřičném formátu.
 Hodnota termu typu i32 bude vytištěna pomocí '%d',
 hodnota termu typu f64 pak pomocí '%a'. Hod
 nota null je tištěna jako literál "null"
@param term je typu (int, float, []u8, nil)
@return void
*/
#define FUNCTION_WRITE                              \
    "\n # Built-in function ifj_write"              \
    "\n LABEL $ifj_write"                           \
    "\n PUSHFRAME"                                  \
    "\n DEFVAR LF@param"                            \
    "\n MOVE LF@param LF@%1"                        \
    "\n DEFVAR LF@type"                             \
    "\n TYPE LF@type LF@param"                      \
    "\n JUMPIFEQ ifj_write_null LF@type string@nil" \
    "\n WRITE LF@input"                             \
    "\n JUMP write_end"                             \
    "\n LABEL ifj_write_null"                       \
    "\n WRITE string@null"                          \
    "\n LABEL ifj_write_end"                        \
    "\n POPFRAME"                                   \
    "\n RETURN"

/*
@param term celočíselná hodnota - typ i32
@return vrátí hodnotu celočíselného termu konvertovanou
 na desetinné číslo
*/
#define FUNCTION_I2F                              \
    "\n # Built-in function ifj_i2f"              \
    "\n LABEL $ifj_i2f"                           \
    "\n PUSHFRAME"                                \
    "\n DEFVAR LF@param"                          \
    "\n MOVE LF@param LF@%1"                      \
    "\n DEFVAR LF@retval"                         \
    "\n MOVE LF@retval nil@nil"                   \
    "\n DEFVAR LF@type"                           \
    "\n TYPE LF@type LF@param"                    \
    "\n JUMPIFNEQ ifj_i2f_end LF@type string@int" \
    "\n INT2FLOAT LF@retval LF@param"             \
    "\n LABEL ifj_i2f_end"                        \
    "\n POPFRAME"                                 \
    "\n RETURN"

/*
@param term desetinná hodnota - typ f64
@return vrátí hodnotu desetinného termu konvertovanou
 na celé číslo, a to oříznutím desetinné části
*/
#define FUNCTION_F2I                                \
    "\n # Built-in function ifj_f2i"                \
    "\n LABEL $ifj_f2i"                             \
    "\n PUSHFRAME"                                  \
    "\n DEFVAR LF@param"                            \
    "\n MOVE LF@param LF@%1"                        \
    "\n DEFVAR LF@retval"                           \
    "\n MOVE LF@retval nil@nil"                     \
    "\n DEFVAR LF@type"                             \
    "\n TYPE LF@type LF@param"                      \
    "\n JUMPIFNEQ ifj_f2i_end LF@type string@float" \
    "\n INT2FLOAT LF@retval LF@param"               \
    "\n LABEL ifj_f2i_end"                          \
    "\n POPFRAME"                                   \
    "\n RETURN"

/*
@param term (je řetězový literál nebo řez)
@return řez - typ []u8
*/
#define FUNCTION_STRING                                 \
    "\n # Built-in function ifj_string"                 \
    "\n LABEL $ifj_string"                              \
    "\n PUSHFRAME"                                      \
    "\n DEFVAR LF@param"                                \
    "\n DEFVAR LF@retval"                               \
    "\n DEFVAR LF@type"                                 \
    "\n MOVE LF@param LF@%1"                            \
    "\n TYPE LF@type LF@parm"                           \
    "\n JUMPIFNEQ ifj_string_end LF@type string@string" \
    "\n MOVE LF@retval LF@param"                        \
    "\n LABEL ifj_string_end"                           \
    "\n POPFRAME"                                       \
    "\n RETURN"

/*
@param s řez - typ []u8
@return vrátí délku řezu - typ i32
*/
#define FUNCTION_LENGTH                                 \
    "\n # Built-in function ifj_length"                 \
    "\n LABEL $ifj_length"                              \
    "\n PUSHFRAME"                                      \
    "\n DEFVAR LF@retval"                               \
    "\n DEFVAR LF@param"                                \
    "\n DEFVAR LF@type"                                 \
    "\n MOVE LF@param TF@%1"                            \
    "\n TYPE LF@type LF@param"                          \
    "\n JUMPIFNEQ ifj_length_end LF@type string@string" \
    "\n STRLEN LF@retval LF@param"                      \
    "\n LABEL ifj_length_end"                           \
    "\n POPFRAME"                                       \
    "\n RETURN"

/*
@param s1 řez
@param s2 řez, který bude následovat ten první
@return vrátí konkatenaci (spojení) řezů
*/
#define FUNCTION_CONCAT                                 \
    "\n # Built-in function ifj_concat"                 \
    "\n LABEL $ifj_concat"                              \
    "\n PUSHFRAME"                                      \
    "\n DEFVAR LF@param1"                               \
    "\n DEFVAR LF@param2"                               \
    "\n DEFVAR LF@retval"                               \
    "\n DEFVAR LF@type"                                 \
    "\n MOVE LF@param1 TF@%1"                           \
    "\n MOVE LF@param2 TF@%2l"                          \
    "\n TYPE LF@type LF@param1"                         \
    "\n JUMPIFNEQ ifj_concat_end LF@type string@string" \
    "\n TYPE LF@type LF@param2"                         \
    "\n JUMPIFNEQ ifj_concat_end LF@type string@string" \
    "\n CONCAT LF@retval LF@param1 LF@param2"           \
    "\n LABEL ifj_concat_end"                           \
    "\n POPFRAME"                                       \
    "\n RETURN"

/*
@param s řez pole znaků - typ []u8
@param i index začátku podřetězce - typ i32
@param j index za posledním znakem podřetězce v  - typ i32
@return podřez z vloženého řezu (s[i] - s[j-1])
*/
#define FUNCTION_SUBSTRING                                    \
    "\n # Built-in function ifj_substring"                    \
    "\n LABEL $ifj_substring"                                 \
    "\n PUSHFRAME"                                            \
    "\n DEFVAR LF@param1"                                     \
    "\n DEFVAR LF@param2"                                     \
    "\n DEFVAR LF@param3"                                     \
    "\n DEFVAR LF@retval"                                     \
    "\n DEFVAR LF@type"                                       \
    "\n DEFVAR LF@is_greater"                                 \
    "\n DEFVAR LF@char"                                       \
    "\n MOVE LF@retval string@"                               \
    "\n MOVE LF@param1 TF@%1"                                 \
    "\n MOVE LF@param2 LF@%2"                                 \
    "\n MOVE LF@param3 LF@%3"                                 \
    "\n TYPE LF@type LF@param1"                               \
    "\n JUMPIFNEQ ifj_substring_end LF@type string@string"    \
    "\n TYPE LF@type LF@param2"                               \
    "\n JUMPIFNEQ ifj_substring_end LF@type string@int"       \
    "\n TYPE LF@type LF@param3"                               \
    "\n JUMPIFNEQ ifj_substring_end LF@type string@int"       \
    "\n GT LF@is_grater LF@param2 int@0"                      \
    "\n JUMPIFEQ ifj_substring_null LF@is_greater bool@false" \
    "\n GT LF@is_grater LF@param3 int@0"                      \
    "\n JUMPIFEQ ifj_substring_null LF@is_greater bool@false" \
    "\n GT LF@is_grater LF@param2 LF@param3"                  \
    "\n JUMPIFEQ ifj_substring_null LF@is_greater bool@true"  \
    "\n DEFVAR LF@strlen"                                     \
    "\n CREATEFRAME"                                          \
    "\n DEFVAR TF@%1"                                         \
    "\n MOVE TF@%1 LF@param1"                                 \
    "\n CALL $ifj_strlen"                                     \
    "\n MOVE LF@strlen TF@retval"                             \
    "\n GT LF@is_greater LF@param2 LF@strlen"                 \
    "\n DEFVAR LF@is_EQ_GT"                                   \
    "\n EQ LF@is_EQ_GT LF@param2 LF@strlen"                   \
    "\n OR LF@is_EQ_GT LF@is_EQ_GT LF@is_greater"             \
    "\n JUMPIFEQ ifj_substring_null LF@is_EQ_GT bool@true"    \
    "\n GT LF@is_grater LF@param3 LF@strlen"                  \
    "\n JUMPIFEQ ifj_substring_null LF@is_greater bool@true"  \
    "\n LABEL ifj_substring_loop"                             \
    "\n JUMPIFEQ ifj_substring_end LF@param2 LF@param3"       \
    "\n GETCHAR LF@char LF@param1 LF@param2"                  \
    "\n CONCAT LF@retval LF@retval LF@char"                   \
    "\n ADD LF@param2 LF@param2 int@1"                        \
    "\n JUMP ifj_substring_loop"                              \
    "\n LABEL ifj_substring_null"                             \
    "\n MOVE LF@retval nil@nil"                               \
    "\n LABEL ifj_substring_end"                              \
    "\n POPFRAME"                                             \
    "\n RETURN"

/*
porovná 2 řezy polí znaků
@param s1 řez pole znaků - typ []u8
@param s2 řez pole znaků - typ []u8
@return vrátí (-1) pokud je s1 menší než s2, (1) pokud je s1 větší, (0) pokud se rovnají - typ i32
*/
#define FUNCTION_STRCMP                                 \
    "\n # Built-in function ifj_strcmp"                 \
    "\n LABEL $ifj_strcmp"                              \
    "\n PUSHFRAME"                                      \
    "\n DEFVAR LF@retval"                               \
    "\n DEFVAR LF@param1"                               \
    "\n DEFVAR LF@param2"                               \
    "\n DEFVAR LF@char1"                                \
    "\n DEFVAR LF@char2"                                \
    "\n DEFVAR LF@type"                                 \
    "\n DEFVAR LF@index"                                \
    "\n DEFVAR LF@strlen1"                              \
    "\n DEFVAR LF@strlen2"                              \
    "\n DEFVAR LF@bool"                                 \
    "\n MOVE LF@index int@0"                            \
    "\n MOVE LF@param1 TF@%1"                           \
    "\n MOVE LF@param2 TF@%2"                           \
    "\n CREATEFRAME"                                    \
    "\n DEFVAR TF@%1"                                   \
    "\n MOVE TF@%1 LF@param1"                           \
    "\n CALL $ifj_strlen"                               \
    "\n MOVE LF@strlen1 TF@retval"                      \
    "\n CREATEFRAME"                                    \
    "\n MOVE TF@%1 LF@param2"                           \
    "\n CALL $ifj_strlen"                               \
    "\n MOVE LF@strlen2 TF@retval"                      \
    "\n TYPE LF@type LF@param1"                         \
    "\n JUMPIFNEQ ifj_strcmp_end LF@type string@string" \
    "\n TYPE LF@type LF@param2"                         \
    "\n JUMPIFNEQ ifj_strcmp_end LF@type string@string" \
    "\n LABEL ifj_strcmp_loop"                          \
    "\n JUMPIFEQ ifj_strcmp_less LF@index LF@strlen1"   \
    "\n JUMPIFEQ ifj_strcmp_more LF@index LF@strlen2"   \
    "\n GETCHAR LF@char1 LF@param1 LF@index"            \
    "\n GETCHAR LF@char2 LF@param2 LF@index"            \
    "\n LT LF@bool LF@char1 LF@char2"                   \
    "\n JUMPIFEQ ifj_strcmp_less LF@bool bool@true"     \
    "\n GT LF@bool LF@char1 LF@char2"                   \
    "\n JUMPIFEQ ifj_strcmp_more LF@bool bool@true"     \
    "\n ADD LF@index LF@index int@1"                    \
    "\n JUMP ifj_strcmp_loop"                           \
    "\n LABEL ifj_strcmp_less"                          \
    "\n JUMPIFEQ ifj_strcmp_equal LF@index LF@strlen2"  \
    "\n MOVE LF@retval int@-1"                          \
    "\n JUMP ifj_strcmp_end"                            \
    "\n LABEL ifj_strcmp_more"                          \
    "\n MOVE LF@retval int@1"                           \
    "\n JUMP ifj_strcmp_end"                            \
    "\n LABEL ifj_strcmp_equal"                         \
    "\n MOVE LF@retval int@0"                           \
    "\n LABEL ifj_strcmp_end"                           \
    "\n POPFRAME"                                       \
    "\n RETURN"

/*
?je dobře že index musí být meší jak strlen?
*/
/*
Převede i-tý znak v řezu na ordinální hodnotu podle ASCII tabulky
@param s1 řez pole znaků - typ []u8
@param i index - typ i32
@return ordinální hodnota (ASCII) - typ i32
*/
#define FUNCTION_ORD                                 \
    "\n # Built-in function ifj_ord"                 \
    "\n LABEL $ifj_ord"                              \
    "\n PUSHFRAME"                                   \
    "\n DEFVAR LF@retval"                            \
    "\n DEFVAR LF@param1"                            \
    "\n DEFVAR LF@param2"                            \
    "\n DEFVAR LF@strlen"                            \
    "\n DEFVAR LF@bool"                              \
    "\n DEFVAR LF@type"                              \
    "\n MOVE LF@param1 TF@%1"                        \
    "\n MOVE LF@param2 LF@%2"                        \
    "\n MOVE LF@retval int@0"                        \
    "\n TYPE LF@type LF@param1"                      \
    "\n JUMPIFNEQ ifj_ord_end LF@type string@string" \
    "\n JUMPIFNEQ ifj_ord_end LF@param1 string@"     \
    "\n CREATEFRAME"                                 \
    "\n MOVE TF@%1 LF@param1"                        \
    "\n CALL $ifj_strlen"                            \
    "\n MOVE LF@strlen TF@retval"                    \
    "\n LT LF@bool LF@param2 LF@strlen"              \
    "\n JUMPIFEQ ifj_ord_end LF@bool bool@false"     \
    "\n STRI2INT LF@retval LF@param1 LF@param2"      \
    "\n LABEL ifj_ord_end"                           \
    "\n POPFRAME"                                    \
    "\n RETURN"

/*
Převede celočíselnou hodnotu na znak podle ASCII tabulky
@param i typ i32
@return []u8 jednoznakový řez se znakem
*/
#define FUNCTION_CHR                 \
    "\n # Built-in function ifj_chr" \
    "\n LABEL $ifj_chr"              \
    "\n PUSHFRAME"                   \
    "\n DEFVAR LF@retval"            \
    "\n DEFVAR LF@param"             \
    "\n MOVE LF@param LF@%1"         \
    "\n INT2CHAR LF@retval LF@param" \
    "\n LABEL ifj_chr_end"           \
    "\n POPFRAME"                    \
    "\n RETURN"
