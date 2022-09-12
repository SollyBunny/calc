#ifndef VAR_H
#define VAR_H
#include "include.h"

Variable *vars = NULL;
unsigned int varalloc = 0;

// Free var's data
void varfree(unsigned int i) {
	switch (vars[i].type) {
		case NUMBER:
			mpf_clear(vars[i].v.number);
			break;
	}
}

// Add a var
void varadd(const char *str, unsigned int type, void *value) {
	unsigned int i;
	if (varalloc == 0) {
		varalloc = 16;
		vars = malloc(sizeof(vars[0]) * varalloc);
		for (i = 0; i < varalloc; ++i) {
			vars[i].type = NUL;
		}
		i = 0;
	} else { // find open space
		for (; i < varalloc && vars[i].type == NUL; ++i);
		if (i == varalloc) {
			vars = realloc(vars, sizeof(vars[0]) * varalloc * 2);
			for (i = varalloc; i < varalloc * 2; ++i) {
				vars[i].type = NUL;
			}
			i = varalloc;
			varalloc *= 2;
			
		}
	}
	vars[i].hash = hash(str);
	vars[i].type = type;
	switch (type) {
		case NUMBER:
			if (value == NULL) {
				mpf_init(vars[i].v.number);
			} else {
				mpf_init_set_str(vars[i].v.number, (const char*)value, 10);
			}
			break;
		default:
			die("Unknown variable type");
	}
}

#endif
