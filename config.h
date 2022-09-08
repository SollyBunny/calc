#ifndef CONFIG_H
#define CONFIG_H
#include "include.h"

#define PRECISION 100

void o_mul(mpf_t x, mpf_t y) {
	mpf_mul(x, y, x);
}
void o_div(mpf_t x, mpf_t y) {
	mpf_div(x, y, x);
}
void o_add(mpf_t x, mpf_t y) {
	mpf_add(x, y, x);
}
void o_sub(mpf_t x, mpf_t y) {
	mpf_sub(x, y, x);
}
void o_mod(mpf_t x, mpf_t y) {
	while (mpf_cmp(y, x) >= 0) {
		mpf_sub(y, y, x);
	}
	mpf_set(x, y);
}
void o_exp(mpf_t x, mpf_t y) {
	while (mpf_cmp_ui(y, 0) >= 0) {
		mpf_sub(y, y, x);
	}
	mpf_set(x, y);
}

void setup() {
	varadd("x", NUMBER, "30");
	operatoradd(MUL, &o_mul);
	operatoradd(DIV, &o_div);
	operatoradd(ADD, &o_add);
	operatoradd(SUB, &o_sub);
	operatoradd(EXP, &o_exp);
}

#endif

