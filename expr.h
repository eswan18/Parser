struct expr {
	expr_t kind;
	struct expr *left;
	struct expr *right;
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char *string_literal;
};

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_POW,
	EXPR_LT,
	EXPR_LE,
	EXPR_GT,
	EXPR_GE,
	EXPR_EQ,
	EXPR_NE,
	EXPR_INTEGER_LITERAL,
	EXPR_STRING_LITERAL
} expr_t;
