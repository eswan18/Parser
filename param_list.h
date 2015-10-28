struct param_list {
	char *name;
	struct type *type;
	struct symbol *symbol;
	struct param_list *next;
};
