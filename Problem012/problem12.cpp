#include <iostream>
#include <limits>

using namespace std;

bool found(unsigned long long  num);

long long barrier1 = numeric_limits<unsigned long long>::max() / 4; 

int main() {
	
	cout << "Numeric limits for unsigned long long: " << endl;
	cout << "Min: " << numeric_limits<unsigned long long>::min() << endl;
	cout << "Max: " << numeric_limits<unsigned long long>::max() << endl;
	  
    unsigned long long tri_num = 1;
    unsigned long long i = 1;

    do {
        ++i;
        tri_num += i;
    }while(!found(tri_num));

    cout << "Solution: " << tri_num << endl;

    return 0;
}

bool found(unsigned long long num) {
    
    if(num >= barrier1) {
		cout << "Barrier-1 is reached: " << barrier1 << endl;
	}
    int count = 2;
    for(unsigned long long  i = 2; i < num; ++i) {
        if(num % i == 0) {
            ++count;
        }
    }
    if(count > 500) {
        return true;
    }
    
    
    return false;
}
