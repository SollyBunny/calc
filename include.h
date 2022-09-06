
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
	struct Token *last;
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
Variable *variables;

extern void __attribute__((noreturn)) die(const char msg[]);
#define ADDHASH(v, t) (v) = (t) + ((v) << 6) + ((v) << 16) - (v)
extern long hash(const char *str);

extern Variable *vars;
extern void varfree(unsigned int i);
extern int  varadd(const char *str, unsigned int type, void *value);
extern void varsetup();

void tokenprint(Token *t);
void tokenfree(Token *t);
void tokenadd(Token **t, unsigned int type, void *arg1, void *arg2);
void tokenize(unsigned int depth, char *string, Token **t);
void tokenparse(Token **t);

#include "config.h"
#include "var.h"
#include "token.h"

#endif
