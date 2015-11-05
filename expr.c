#include <stdlib.h>
#include "expr.h"
#include <string.h>

struct expr *expr_create( expr_t kind, struct expr *left, struct expr *right ) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = kind;
	expr -> left = left;
	expr -> right = right;
	return expr;
}

struct expr *expr_create_name( const char *n ) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = EXPR_NAME;
	char *name = malloc(sizeof(char) * 256);
	strcpy(name, n);
	expr -> name = name;
	return expr;
}

struct expr *expr_create_boolean_literal( int c ) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = EXPR_BOOLEAN_LITERAL;
	expr -> literal_value = c;
	return expr;
}

struct expr * expr_create_integer_literal( int c ) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = EXPR_INTEGER_LITERAL;
	expr -> literal_value = c;
	return expr;
}

struct expr * expr_create_character_literal( int c) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = EXPR_CHARACTER_LITERAL;
	expr -> literal_value = c;
	return expr;
}

struct expr * expr_create_string_literal( const char *str ) {
	struct expr *expr = malloc(sizeof(struct expr));
	expr -> kind = EXPR_STRING_LITERAL;
	char *s = malloc(sizeof(char) * 256);
	strcpy(s,str);
	expr -> string_literal = s;
	return expr;
}

/*Still to be implemented*/
void expr_print(struct expr *e) {
}
