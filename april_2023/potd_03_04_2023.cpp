#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int xmod11(string x)
    {
        long long int od = 0, ev = 0;
        for (int i = 0; i < x.length(); i++)
        {
            if (i % 2 == 0)
                od += (x[i] - '0');
            else
                ev += (x[i] - '0');
        }
        long long int diff = (od - ev) % 11;
        if (x.length() % 2 == 0)
            return abs(diff - 11) % 11;
        return diff;
    }
};