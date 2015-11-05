#include <stdlib.h>
#include "stmt.h"

struct stmt *stmt_create(stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body) {
	struct stmt *stmt = malloc(sizeof(struct stmt));
	stmt -> kind = kind;
	stmt -> init_expr = init_expr;
	stmt -> expr = e;
	stmt -> next_expr = next_expr;
	stmt -> body = body;
	stmt -> else_body = else_body;
	return stmt;
}

/*Still to be implemented*/
void stmt_print(struct stmt *s, int indent) {
}
