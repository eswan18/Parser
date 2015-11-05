#include <stdlib.h>
#include "decl.h"
#include <string.h>

struct decl *decl_create(char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next) {
	printf("DECL_CREATE\n");
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
	printf("DECL_PRINT\n");
	if(!d)
		return;
	printf("\n");
	int i;
	for(i=0;i<indent;i++)
		printf("\t");
	printf("here 1\n");
	printf("%s: ",d->name);
	printf("here 2\n");
	type_print(d->type);
	if(d->value) {
		printf("=");
		expr_print(d->value);
	}
	if(d->code) {
		printf("= {");
		stmt_print(d->code,indent+1);
		for(i=0;i<indent;i++)
			printf("\t");
		printf("}");
	}
	decl_print(d->next,indent);
}
