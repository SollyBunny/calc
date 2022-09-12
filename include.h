
#ifndef INCLUDE_H
#define INCLUDE_H

#include <gmp.h>

#include <stdio.h>
#include <stdlib.h>

enum { 
	NUL,
	OPERATOR, NUMBER, VARIABLE,
	ADD, SUB, MUL, DIV, MOD, EXP,
};
enum {
	B2  = 2,
	B8  = 8,
	B16 = 16,
};

struct Token {
	struct Token *next;
	unsigned int type;
	union {
		unsigned int operator;
		mpf_t        number;
		long         variable;
	} v;
};
typedef struct Token Token;

typedef struct {
	long hash;
	unsigned int type;
	union {
		mpf_t number;
	} v;
} Variable;
extern Variable *variables;

typedef struct {
	unsigned int op;
	void (*func)(mpf_t x, mpf_t y);
} Operator;
extern Operator *operators;

extern void __attribute__((noreturn)) die(const char msg[]);
#define ADDHASH(v, t) (v) = (t) + ((v) << 6) + ((v) << 16) - (v)
extern long hash(const char *str);

extern Variable *vars;
extern void      varfree(unsigned int i);
extern void      varadd(const char *str, unsigned int type, void *value);

extern Operator *operators;
extern unsigned int operatorsused;
extern void operatoradd(unsigned int op, void (*func)(mpf_t x, mpf_t y));

extern void tokenprint(Token *t, unsigned int all);
extern void tokenfree(Token *t);
extern void tokenadd(Token **t, unsigned int type, void *arg1, void *arg2);
extern void tokenize(unsigned int depth, char *string, Token **t);
extern void tokenparse(Token **t);

extern void setup();

#include "gmpext.h"
#include "config.h"
#include "var.h"
#include "token.h"
#include "operator.h"

#endif
