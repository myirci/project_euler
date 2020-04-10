#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<uint64_t> collatz_sequence(uint64_t n)
{
    vector<uint64_t> seq{n};
    while(n != 1)
    {
        n = (n % 2 == 0) ? n/2 : 3*n + 1;
        seq.push_back(n);
    }
    return seq;
}

uint64_t collatz_sequence_length(uint64_t n)
{
    uint64_t seq_lenght{1};
    while(n != 1)
    {
        n = (n % 2 == 0) ? n/2 : 3*n + 1;
        ++seq_lenght;
    }
    return seq_lenght;
}

int main()
{
    uint64_t max_length{0}, max_start{0};

    for(uint64_t i = 999999; i > 0; i--)
    {
        uint64_t c = collatz_sequence_length(i);
        if(max_length < c)
        {
            max_length = c;
            max_start = i;
        }
    }

    cout << "Max start : " << max_start << endl;
    cout << "Max length: " << max_length << endl;

}
