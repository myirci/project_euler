// 06/09/2012 - Murat Yirci
#include <iostream>
using namespace std;
int main(void) {
	unsigned long sum1 = 0;
	for(int i = 1; i <= 100; ++i)
		sum1 += i*i;
	unsigned long sum2 = (100*101)/2;
	sum2 *= sum2;
	cout << sum2 - sum1 << endl;
	return 0;
}
