#ifndef OPERATOR_H
#define OPERATOR_H

#include "include.h"

Operator *operators = NULL;
unsigned int operatorsused = 0;
unsigned int operatorsalloc = 0;

void operatoradd(unsigned int op, void (*func)(mpf_t x, mpf_t y)) {
	if (operatorsused == 0) {
		operatorsalloc = 8;
		operators = malloc(operatorsalloc * sizeof(operators[0]));
	} else if (operatorsused > operatorsalloc) {
		operatorsalloc *= 2;
		operators = realloc(operators, operatorsalloc * sizeof(operators[0]));
	}
	operators[operatorsused].op   = op;
	operators[operatorsused].func = func;
	++operatorsused;
}

#endif