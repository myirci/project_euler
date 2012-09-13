// 06/09/2012 - Murat Yirci
#include <iostream>

using namespace std;

void fibonacci(int prev, int curr);

int main(void) {
	int prev = 1;
	int curr = 2;
	fibonacci(prev, curr);
	return 0;
}

void fibonacci(int prev, int curr) {
		static int sum = 0;
		int next = prev + curr;
		cout << prev << " ";	
		prev = curr;
		if(prev % 2 == 0)
			sum += prev;
		if(curr > 4000000) {
			cout << "\n: Sum: " << sum << endl;
			return;
		}
		fibonacci(prev, next);
}
