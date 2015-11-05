#include <stdlib.h>
#include "type.h"

struct type *type_create(type_kind_t kind, struct param_list *params, struct type *subtype) {
	printf("TYPE_CREATE\n");
	struct type *type = malloc(sizeof(struct type));
	type -> kind = kind;
	type -> params = params;
	type -> subtype = subtype;
	return type;
}

/*Still to be implemented*/
void type_print(struct type *t) {
	printf("TYPE_PRINT\n");
	if(!t)
		return;
	switch(t->kind) {
		case TYPE_BOOLEAN:
			printf("boolean");
			break;
		case TYPE_CHARACTER:
			printf("character");
			break;
		case TYPE_INTEGER:
			printf("integer");
			break;
		case TYPE_STRING:
			printf("string");
			break;
		case TYPE_ARRAY:
			break;
		case TYPE_FUNCTION:
			break;
		case TYPE_VOID:
			printf("void");
			break;
	}
}
