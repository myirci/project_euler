// 07/09/2012 - Murat Yirci
#include <iostream>
using namespace std;
int main(void) {
  int a = 0;
  int b = 0;
  int c = 0;
  for(a = 1; a < 1000; ++a) {
    for(b = 2; b < 1000; ++b) {
      for(c = 3; c < 1000; ++c) {
        if(c > b && b > a && (a+b+c) == 1000 && (a*a + b*b) == c*c) {
          cout << "a:" << a << " b: " << b << " c: " << c << " a*b*c = " << a*b*c << endl;  
        }
      }
    }
  }
}
