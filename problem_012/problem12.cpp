#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Let sDiv be the funtion that returns the set of divisors for a given number
// Let s1 = sDiv(a) and s2 = sDiv(b)
// Then, s3 = sDiv(a*b) = unique values of (s1 x s2)

// Let tn denote the nth triangle number
// tn = n*(n+1)/2;

uint64_t brute_force_count_num_divisors(uint64_t num) {

    if(num == 1)
    {
        return 1;
    }

    uint64_t count{2};
    for(uint64_t i = 2; i < num; ++i)
    {
        if(num % i == 0)
        {
            ++count;
        }
    }
    return count;
}

vector<uint64_t> divisors(uint64_t num)
{
    vector<uint64_t> ret{1};

    if(num == 1)
    {
        return ret;
    }

    for(uint64_t i = 2; i <= num; ++i)
    {
        if(num % i == 0)
        {
            ret.push_back(i);
        }
    }
    return ret;
}

uint64_t num_divisors(const vector<uint64_t>& v1, const vector<uint64_t>& v2)
{
    unordered_set<uint64_t> set;
    for(auto it1 = v1.begin(); it1 != v1.end(); it1++)
    {
        for(auto it2 = v2.begin(); it2 != v2.end(); it2++)
        {
            set.insert((*it1) * (*it2));
        }
    }
    return set.size();
}

int main() {

    vector<uint64_t> v1,v2;
    for(uint64_t i = 2; i < 20000; i++)
    {
        auto pairs = i % 2 == 0 ? make_pair(i/2, i+1) : make_pair((i+1)/2, i);
        v1 = divisors(pairs.first);
        v2 = divisors(pairs.second);
        auto num_div = num_divisors(v1,v2);
        if(num_div > 500)
        {
            cout <<"Triangular number: " << i*(i+1)/2 << endl;
            cout <<"Number of divisors: " << num_div << endl;
        }
    }

    cout << "No solution" << endl;

    return 0;
}
