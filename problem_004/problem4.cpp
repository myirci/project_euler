// 06/09/2012 - Murat Yirci
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_palindrom(const int num);

using namespace std;
int main(void) {
	vector<int> palindroms;
	for(int i = 999; i >= 100; --i) {
		for(int j = 999; j >= 100; --j) {
			if(is_palindrom(i*j)) {
				palindroms.push_back(i*j);
			}
		}
	}
	vector<int>::iterator it = max_element(palindroms.begin(), palindroms.end());
	cout << *it << endl;
	return 0;
}

bool is_palindrom(const int num) {
	int num1 = num;
	vector<int> digits;
	do{
		digits.push_back(num1 % 10);
		num1 = num1 / 10;
	}while(num1 != 0);
	
	int num2 = 0;
	int s = digits.size();
	for(int i = 0; i < s; ++i) {
		num2 += pow(10, (s-1-i)) * digits[i];
	}
	
	if(num == num2) {
		return true;
	}
	return false;
}
