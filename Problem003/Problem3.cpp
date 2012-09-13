// 06/09/2012 - Murat Yirci
// You need to have GMP library to build from source.
#include <iostream>
#include <stdio.h>
#include <gmp.h>
using namespace std;
int main(void) {
	
	mpz_t num;
	mpz_init_set_str(num, "600851475143", 10);
	mpz_t i;
	for(mpz_init_set_ui(i,2); mpz_cmp(num,i) >= 0; mpz_add_ui(i, i, 1)) {
		if(mpz_divisible_p(num, i) != 0) {
			mpz_tdiv_q(num, num, i);
			mpz_out_str(stdout, 10, i);
			cout << endl;
			mpz_sub_ui(i, i, 1);
		}
	}
	mpz_clear(i);
	mpz_clear(num);
	return 0;
}
