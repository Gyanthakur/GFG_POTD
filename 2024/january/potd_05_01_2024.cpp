#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
// #define int long long
long long t;

class Solution
{
public:
	int TotalWays(int n)
	{
		// Code here
		long long int mod = 1e9 + 7;
		if (n == 1)
			return 4;
		if (n == 2)
			return 9;
		int previous_two = 2, previous_one = 3, current = 0;
		for (int i = 3; i <= n; i++)
		{
			current = (previous_two + previous_one + mod) % mod;
			previous_two = previous_one;
			previous_one = current;
		}
		long long total = ((current % mod) * (current % mod)) % mod;
		return total;
	}
};

void solution()
{
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		solution();
		cout << endl;
	}
	return 0;
}