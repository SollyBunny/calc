#include "include.h"

void __attribute__((noreturn)) die(const char msg[]) {
	printf("Error: %s\n", msg);
	exit(1);
}

long hash(const char *str) {
	long out = 0;
	while (*str != '\0') {
		ADDHASH(out, *str);
		++str;
	}
	return out;
}

int main(int argc, char *argv[]) {
	// check args
		if (argc == 1) {
			printf("Usage: %s [EXPRESSION]\n", argv[0]);
			exit(0);
		}
	// stitch strings together
		char *string;
		size_t size = 1;
		for (int i = 1; i < argc; ++i) {
			unsigned int m = 0;
			while (argv[i][m] != '\0') ++m;
			size += m;
		}
		string = malloc(size);
		for (int i = 1; i < argc; ++i) {
			unsigned int m = 0;
			while (argv[i][m] != '\0') {
				*string = argv[i][m];
				++string;
				++m;
			};
		}
		*string = '\0';
		string -= size - 1;
		printf("'%s' (%lu)\n", string, size);
	// setup
		mpf_set_default_prec(PRECISION);
		varsetup();
	// tokenize
		Token *t = NULL;
		tokenize(0, string, &t);
		free(string);
		printf("Tokenized: ");
		tokenprint(t);
		tokenparse(&t);
		printf("Parsed: ");
		tokenprint(t);
	// free stuff
		Token *tnew;
		do {
			tnew = t->last;
			tokenfree(t);
			t = tnew;
		} while (t != NULL);
		for (unsigned int i = 0; i < varalloc; ++i) varfree(i);
		free(vars);
	return 0;	

}
