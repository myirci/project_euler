// 06/09/2012 - Murat Yirci
#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for(int i = 3; i < 1000; ++i)
		if((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	cout << "sum: " << sum << endl;
	return 0;
}