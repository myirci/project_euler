// 06/09/2012 - Murat Yirci
#include <iostream>
#include "utility_template_functions.hpp"
using namespace std;

void my_solution() {
    int sum = 0;
	for(int i = 3; i < 1000; ++i)
		if((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	cout << "sum: " << sum << endl;
}

void better_solution() {

    unsigned long long int sum =
            sum_divisible_by(static_cast<unsigned int>(3), static_cast<unsigned int>(999)) +
            sum_divisible_by(static_cast<unsigned int>(5), static_cast<unsigned int>(999)) -
            sum_divisible_by(static_cast<unsigned int>(15), static_cast<unsigned int>(999));
	cout << "sum: " << sum << endl;
}

int main() {
	// my_solution();
	better_solution();
	return 0;
}

// Answer: 233168
