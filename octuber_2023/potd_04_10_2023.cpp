// class Solution
// {
// public:
#include <bits/stdc++.h>
using namespace std;
int romanToDecimal(string &str)
{
    // code here
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int i;
    int ans = m[str[0]];
    for (i = 1; i < str.size(); i++)
    {
        if (m[str[i - 1]] < m[str[i]])
        {
            ans += abs(m[str[i - 1]] - m[str[i]]) - m[str[i - 1]];
        }
        else
        {
            ans += m[str[i]];
        }
    }
    return ans;
}
int main()
{
    // Solution solution;
    string romanNumeral = "MCMXCIV"; // Example Roman numeral (1994)
    int decimalValue = romanToDecimal(romanNumeral);
    cout << "Decimal value: " << decimalValue << endl;
    return 0;
}