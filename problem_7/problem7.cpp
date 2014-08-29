//06/09/2012 - Murat Yirci
#include <iostream>
#include <vector>
using namespace std;
bool is_prime(unsigned long num);
int main() {
	int count = 10001;
	unsigned long prime;
	for(unsigned long i = 2; count > 0; ++i) {
		if(is_prime(i)) {
			count--;
			prime = i;
		}
	}
	cout << "10001st prime: " << prime << endl;
	return 0;
}

bool is_prime(unsigned long num) {
	static vector<unsigned long> primes;
	vector<unsigned long>::iterator it;
	for(it = primes.begin(); it != primes.end(); ++it) {
		if(num % *it == 0) {
			return false;
		}
	}
	primes.push_back(num);
	return true;
}
