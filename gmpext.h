/*
	This library contains functions which are missing in GMP
	This is so we can use trig functions, pi and exponents with high precision
	:)
*/

#include <gmp.h>

#ifndef PRECISION
	#define PRECISION 100
#endif

void mpf_pi(mpf_t pi) {
	unsigned long int m;
	mpf_t j, exp, part;
	mpf_init_set_ui(exp, 1);
	mpf_init(j);
	mpf_init(part);
	for (unsigned long int i = 0; i < PRECISION; ++i) {
		m = 8 * i + 1;
		mpf_set_ui(part, 4);
		mpf_div_ui(part, part, m);
		m = 8 * i + 4;
		mpf_set_ui(j, 2);
		mpf_div_ui(j, j, m);
		mpf_sub(part, part, j);
		m = 8 * i + 5;
		mpf_set_ui(j, 1);
		mpf_div_ui(j, j, m);
		mpf_sub(part, part, j);
		m = 8 * i + 6;
		mpf_set_ui(j, 1);
		mpf_div_ui(j, j, m);
		mpf_sub(part, part, j);
		mpf_div(part, part, exp);
		mpf_mul_ui(exp, exp, 16);
		mpf_add(pi, pi, part);
	}
	mpf_clear(exp);
	mpf_clear(part);
}

void mpf_sin(mpf_t angle) {
	unsigned long int denom;
	mpf_t out, angpow, part;
	mpf_init_set(out, angle);
	mpf_init_set(angpow, angle);
	mpf_init_set(part, angle);
	mpf_mul(angpow, angpow, angpow);
	for (unsigned long int i = 1; i < PRECISION; ++i) {
		denom = 2 * i * (2 * i + 1);
		mpf_neg(part, part);
		mpf_mul(part, part, angpow);
		mpf_div_ui(part, part, denom);
		mpf_add(out, out, part);
	}
	mpf_set(angle, out);
	mpf_clear(out);
	mpf_clear(angpow);
	mpf_clear(part);
}

void mpf_log2(mpf_t op, mpf_t in) {
	mpf_init_set_ui(op, 0);
	unsigned long m;
	mpf_t part;
	mpf_init(part);
	mpf_t intemp;
	mpf_init(intemp);
	m = 2;
	for (unsigned int i = 0; i < PRECISION; ++i) {
		mpf_set(intemp, in);
		while (mpf_cmp_ui(intemp, 2) > 0 && mpf_cmp_ui(in, 4) < 0) {
			mpf_mul(intemp, intemp, intemp);
			m *= 2;
		}
		mpf_set_ui(part, 2);
		mpf_pow_ui(part, part, m);
		mpf_ui_div(part, 1, part);
		mpf_add(op, op, part);
		mpf_div_ui(in, in, 2);
	}
}
