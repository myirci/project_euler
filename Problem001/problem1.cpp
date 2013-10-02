// 06/09/2012 - Murat Yirci
#include <iostream>
#include "../Utility/utility_functions.hpp"
using namespace std;

void my_solution() {
	int sum = 0;
	for(int i = 3; i < 1000; ++i)
		if((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	cout << "sum: " << sum << endl;
}

void better_solution() {
	unsigned int sum = sum_divisible_by(999, 3) + sum_divisible_by(999, 5) - sum_divisible_by(999, 15);
	cout << "sum: " << sum << endl;
}

int main() {
	// my_solution();
	better_solution();
	return 0;
}

// The answer is: 233168
