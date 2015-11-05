#include <stdlib.h>
#include "type.h"

struct type *type_create(type_kind_t kind, struct param_list *params, struct type *subtype) {
	struct type *type = malloc(sizeof(struct type));
	type -> kind = kind;
	type -> params = params;
	type -> subtype = subtype;
	return type;
}

/*Still to be implemented*/
void type_print(struct type *t) {
	
}
