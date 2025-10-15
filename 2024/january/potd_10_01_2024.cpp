#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
		// Complete the function
		unordered_map<int, int> m;
		int ans = 0, sum = 0;
		m[0] = -1;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			int r = sum % k;
			if (r < 0)
				r += k;
			if (m.find(r) == m.end())
				m[r] = i;
			else
				ans = max(ans, i - m[r]);
		}
		return ans;
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