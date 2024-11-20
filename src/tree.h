#ifndef TREE_H
#define TREE_H

extern char *filename;

extern Dynamic_string dyn_str;

typedef enum
{
    TYPE_NONE,
    TYPE_VOID,
    TYPE_U8,
    TYPE_I32,
    TYPE_F64,
    TYPE_U8_NULL,
    TYPE_I32_NULL,
    TYPE_F64_NULL,
} TYPE;

typedef enum
{
    VAR_TYPE,
    CONST_TYPE,
} VariableType;

typedef enum
{
    OP_PLUS,          // +
    OP_MINUS,         // -
    OP_STAR,          // *
    OP_SLASH,         // /
    OP_IDIV,          // / celočíselné
    OP_EQUAL,         // ==
    OP_NOT_EQUAL,     // !=
    OP_LESS,          // <
    OP_GREATER,       // >
    OP_LESS_EQUAL,    // <=
    OP_GREATER_EQUAL, // >=
} OPERATOR_TYPE;

/*

nevím zda je potřeba*/
typedef enum
{
    S_OP_PLUS,          // +
    S_OP_MINUS,         // -
    S_OP_STAR,          // *
    S_OP_SLASH,         // /
    S_OP_IDIV,          // / celočíselné
    S_OP_EQUAL,         // ==
    S_OP_NOT_EQUAL,     // !=
    S_OP_LESS,          // <
    S_OP_GREATER,       // >
    S_OP_LESS_EQUAL,    // <=
    S_OP_GREATER_EQUAL, // >=
} S_OPERATOR_TYPE;

typedef enum
{
    NODE_MAIN,
    NODE_FUNCTION,
    NODE_PARAMETER,
    NODE_VARIABLE_DECLARATION,
    NODE_VARIABLE_INITIALIZATION,
    NODE_EXPRESSION,
    NODE_IF,
    NODE_IF_BODY,
    NODE_ELSE_BODY,
    NODE_WHILE,
    NODE_CONDITION,
    NODE_RETURN,
    NODE_CALL,
    NODE_FACTOR,
} NodeType;

typedef struct FunctionNode
{
    char *id;
    TYPE return_type;
    struct Node *params; // Parameters list
} F_DEF;

typedef struct ParameterNode
{
    char *id;
    TYPE type;
} PARAMS_IN;

typedef struct VariableDeclarationNode
{
    char *id;
    TYPE type;
    VariableType var_type;
    struct Node *expression;
    struct Node *call;
} VAR_DEC;

typedef struct IfNode
{
    struct Node *condition; // Condition for the `if` statement
    struct Node *exp_null;
    struct Node *id_null;
    unsigned int cnt;
} IF;

typedef struct Ifbody
{
    unsigned int cnt;
} IF_BODY;

typedef struct ElseBody
{
    unsigned int cnt;
} ELSE_BODY;

typedef struct WhileNode
{
    struct Node *condition; // Condition for the `while` loop
    struct Node *exp_null;
    struct Node *id_null;
    unsigned int cnt;
} WHILE;

typedef struct ReturnNode
{
    struct Node *expression; // Expression to be returned
} RETURN;

typedef struct CallNode
{
    char *id;
    bool isBuildin;
    struct Node *args; // Arguments list
} CALL;

typedef struct ConditionNode
{
    struct Node *leftExpression;  // Left part of the condition
    OPERATOR_TYPE operator;       // Comparison operator (e.g., `==`, `<`, `>=`)
    struct Node *rightExpression; // Right part of the condition (optional)
} CONDITION;

typedef struct ExpressionNode
{
    struct Node *leftExpression;  // Left-hand term
    OPERATOR_TYPE operator;       // Operator (`+` or `-`)
    struct Node *rightExpression; // Right-hand term (optional)
} EXPRESSION;

typedef struct FactorNode
{
    TYPE factorType;
    char *id;
    union
    {
        int i32;
        double f64;
        char *u8;
    } value;
} FACTOR;

typedef struct Node
{
    NodeType type;         // Type of the node
    struct Node *sibling;  // Pointer to the next sibling
    struct Node *children; // Pointer to the next children
    union
    {
        F_DEF function;            // Function Node
        PARAMS_IN parameter;       // Parameter Node
        VAR_DEC varDecl;           // Variable Declaration Node
        IF ifNode;                 // If Node
        IF_BODY ifBody;            // If body Node
        ELSE_BODY elseBody;        // Else body Node
        WHILE whileNode;           // While Node
        RETURN returnNode;         // Return Node
        CALL callNode;             // Function Call Node
        CONDITION conditionNode;   // Condition Node
        EXPRESSION expressionNode; // Expression Node
        FACTOR factorNode;         // Factor Node
    } data;
} Node;

#endif // TREE_H