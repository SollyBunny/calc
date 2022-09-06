build:
	gcc main.c -o "=" -g3 -lgmp
	./=

static:
	gcc main.c ./gmp/libgmp.a  -o "=" -g3 -I./gmp/
	./=

