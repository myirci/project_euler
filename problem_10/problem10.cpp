//07/09/2012 - Murat Yirci
#include <iostream>
#include <vector>
using namespace std;
int main() {
	bool prime = true;
	unsigned long long sum = 0;
	vector<unsigned int> primes;
	vector<unsigned int>::iterator it;
	for(unsigned int i = 2; i < 2000000; ++i) {
		for(it = primes.begin(); it != primes.end(); ++it) {
			if(i % *it == 0) {
				prime = false;
				break;
			}
		}
		if(prime) {
			primes.push_back(i);
			sum += i;
		}
		prime = true;
	}
	cout << "Sum: " << sum << endl;
	return 0;
}
