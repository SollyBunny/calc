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
int varadd(const char *str, unsigned int type, void *value) {
	unsigned int i;
	if (varalloc == 0) {
		i = 0;
		varalloc = 16;
		vars = malloc(sizeof(vars[0]) * varalloc);
	} else { // find open space
		for (; i < varalloc && vars[i].used == 0; ++i);
		if (i == varalloc) {
			varalloc *= 2;
			vars = realloc(vars, sizeof(vars[0]) * varalloc);
		}
	}
	vars[i].used = 1;
	vars[i].hash = hash(str);
	vars[i].type = type;
	switch (type) {
		case NUMBER:
			mpf_init_set_str(vars[i].v.number, (const char*)value, 10);
			break;
		default:
			die("Unknown variable type");
	}
}

#endif
