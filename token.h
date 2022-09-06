#ifndef TOKEN_H
#define TOKEN_H
#include "include.h"

// Print all tokens before token t
void tokenprint(Token *t) {
	printf("Tokens:");
	if (t == NULL) {
		printf("\n	None\n");
		return;
	}
	unsigned int i = 1;
	do {
		printf("\n	%d: ", i);
		switch (t->type) {
			case OPERATOR:
				printf("Operator '");
				switch (t->v.operator) {
					case ADD: putchar('+'); break;
					case SUB: putchar('-'); break;
					case MUL: putchar('*'); break;
					case DIV: putchar('/'); break;
					case MOD: putchar('%'); break;
					case EXP: putchar('^'); break;
					default:  putchar('?'); break;
				}
				putchar('\'');
				break;
			case NUMBER:
				gmp_printf("Number: %Ff", t->v.number);
				//printf("Number: ");
				//mpf_out_str(stdout, 10, 10, t->v.number);
				break;
			case VARIABLE:
				printf("Variable: %ld (hash)", t->v.variable);
				break;
		}
		t = t->last;
		++i;
	} while (t != NULL);
	putchar('\n');
}

// Free a token and it's data
void tokenfree(Token *t) {
	if (t == NULL) return;
	if (t->type == NUMBER) {
		mpf_clear(t->v.number);
	}
	free(t);
}

// Add a token after token t with type and args
void tokenadd(Token **t, unsigned int type, void *arg1, void *arg2) {
	if (*t == NULL) {
		*t = malloc(sizeof(**t));
		(*t)->last = NULL;
	} else {
		(*t)->next = malloc(sizeof(**t));
		(*t)->next->last = (*t);
		(*t) = (*t)->next;
	}
	(*t)->next = NULL;
	(*t)->type = type;
	switch (type) {
		case NUMBER:
			mpf_init_set_str((*t)->v.number, (const char*)arg1, (unsigned int)(long)arg2);
			break;
		case OPERATOR:
			(*t)->v.operator = (unsigned int)(long)arg1;
			break;
		case VARIABLE:
			(*t)->v.variable = (long)arg1;
			break;
	}
}

void tokenize(unsigned int depth, char *string, Token **t) {
	if (depth > 20) exit(2);
	char *start = string;
	long decimal = 0;
	unsigned int type = NUL;
	unsigned int base = 10;
	unsigned int tokentype = NUL;
	#define CHECKTYPE(x) if (tokentype == NUL) tokentype = x; else if (tokentype != x) die("Invalid char (1)");
	while (1) {

		switch (*string) {
			case '+': type = ADD; goto l_parse_token;
			case '-': type = SUB; goto l_parse_token;
			case '*': type = MUL; goto l_parse_token;
			case '/': type = DIV; goto l_parse_token;
			case '\0': type = 0; l_parse_token:
				if (tokentype == VARIABLE) {
					tokenadd(t, VARIABLE, (void *)decimal, NULL);
				} else if (tokentype == NUL || tokentype == NUMBER) {
					tokentype = NUMBER;
					*string = '\0'; // make sure addtoken parser knows when to stop
					tokenadd(t, NUMBER, start, (void *)(long)base);
				}
				if (type == 0) goto l_parse_stop;
				tokenadd(t, OPERATOR, (void *)(long)type, NULL);
				start = string + 1;
				decimal = 0;
				tokentype = NUL;
				break;
			case '.':
			case ',':
				CHECKTYPE(NUMBER);
				if (decimal != 0) die("Too many decimal points in number");
				decimal = 1;
				break;
			case '0' ... '9':
				if (tokentype == NUL) {
					tokentype = NUMBER;
				} else if (tokentype == VARIABLE) {
					ADDHASH(decimal, *string);
				}
				break;
			case 'b': case 'B': base = B2;  goto l_parse_base;
			case 'o': case 'O': base = B8;  goto l_parse_base;
			case 'x': case 'X': base = B16; l_parse_base:
				if (tokentype == NUL || tokentype == VARIABLE) {
					tokentype = VARIABLE; 
					ADDHASH(decimal, *string);
				} else if (*(string - 1) != '0') {
					die("Invalid char (2)");
				} else {
					tokentype = NUMBER;
					start = string + 1;
				}
				break;
			case 'a':
			case 'c' ... 'f':
			case 'A':
			case 'C' ... 'F':
				printf("Type: %d\n", tokentype);
				if (tokentype == NUL || tokentype == VARIABLE) {
					tokentype = VARIABLE;
					ADDHASH(decimal, *string);
				} else if (tokentype == NUMBER) {
					if (base <= 10) die("Cannot use a-f in not hex numbers");
				}
				break;
			case 'g' ... 'n':
			case 'p' ... 'w':
			case 'y' ... 'z':
			case 'G' ... 'N':
			case 'P' ... 'W':
			case 'Y' ... 'Z':
				if (tokentype == NUL || tokentype == VARIABLE) {
					tokentype = VARIABLE;
					ADDHASH(decimal, *string);
				} else die("Invalid char (3)");
				break;
			default:
				die("Invalid char (3)");
		}
		++string;
	}
	l_parse_stop:
	return;
}

void tokenparse(Token **t) {
	if (*t == NULL) return;
	Token *i = *t;
	do {
		if (i->type != VARIABLE) continue;
		for (unsigned int m = 0; m < varalloc; ++m) {
			if (vars[m].type == NUL) continue;
			if (vars[m].hash != i->v.variable) continue;
			if (vars[m].type == NUMBER) {
				i->type = NUMBER;
				mpf_init(i->v.number);
				mpf_set(i->v.number, vars[m].v.number);
				goto l_parse_good;
			}
		}
		die("Invalid variable");
		l_parse_good: continue; // stop old gcc error
	} while ((i = i->last) != NULL);

	Token *m;
	i = *t;
	if (i->last == NULL || i->last->last == NULL) return;
	while (1) {	
		if (i->type == NUMBER && i->last->type == OPERATOR && i->last->last->type == NUMBER && i->last->v.operator == MUL ) {
			mpf_mul(i->v.number, i->v.number, i->last->last->v.number);
			m = i->last->last->last;
			tokenfree(i->last->last);
			tokenfree(i->last);
			if (m == NULL || m->last == NULL) return;
			i = m->last;
		} else i = i->last;
		if (i->last->last == NULL) break;
	}
}

#endif
