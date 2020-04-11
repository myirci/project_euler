#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>


using namespace std;

vector<uint8_t> num_to_vector(uint64_t num)
{
    vector<uint8_t> vec;
    do
    {
        vec.push_back(num % 10);
        num = num/10;
    }
    while(num != 0);
    return vec;
}

vector<uint8_t> multiply(const vector<uint8_t>& v1, const vector<uint8_t>& v2)
{

    return vector<uint8_t>{};
}

int main()
{
    // div_t d = div(1000,63);

    uint64_t pow2_63 = static_cast<uint64_t>(pow(2,63));
    auto v1 = num_to_vector(pow2_63);

    cout << pow2_63 << endl;
    for_each(v1.begin(), v1.end(), [](uint8_t i){cout << static_cast<int>(i);});
    cout << endl;


    //uint64_t pow2_rem = static_cast<uint64_t>(pow(2,d.rem));


}
