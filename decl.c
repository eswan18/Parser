#include <stdlib.h>
#include "decl.h"
#include <string.h>

struct decl *decl_create(char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next) {
	struct decl *decl = malloc(sizeof(struct decl));
	char *n = malloc(sizeof(char) * 256);
	strcpy(n,name);
	decl -> name = n;
	decl -> type = t;
	decl -> value = v;
	decl -> code = c;
	decl -> next = next;
	return decl;
}

/*Still to be implemented*/
void decl_print(struct decl *d, int indent) {
}
