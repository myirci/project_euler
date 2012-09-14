#include <iostream>

using namespace std;

bool found(unsigned long long  num);

int main() {

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
