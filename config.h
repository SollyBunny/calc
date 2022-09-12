#ifndef CONFIG_H
#define CONFIG_H
#include "include.h"

#ifndef PRECISION
	#define PRECISION 100
#endif

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

mpf_t pi;
void setup() {

	mpf_t out;
	mpf_init(out);
	mpf_t in;
	mpf_init_set_ui(in, 8);
	mpf_log2(out, in);
	gmp_printf("Log2 of 8: %Ff\n", out);

	varadd("pi", NUMBER, NULL);
	mpf_pi(vars[0].v.number);
	
	/*mpf_t deg;
	mpf_init(deg);
	mpf_pi(deg);
	mpf_ui_div(deg, 180, deg);
	varadd("deg", PRENUMBER, deg);*/
	
	operatoradd(MUL, &o_mul);
	operatoradd(DIV, &o_div);
	operatoradd(ADD, &o_add);
	operatoradd(SUB, &o_sub);
	operatoradd(EXP, &o_exp);
	
}

#endif

