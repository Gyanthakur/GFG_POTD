#include <bits/stdc++.h>
using namespace std;

int main()
{
	return 0;
}

class Solution
{
public:
	unordered_map<int, pair<int, int>> mp;
	vector<int> arr;

	long long mine(int ind, int curr, vector<vector<long long>> &dp)
	{
		if (ind == arr.size())
			return (long long)abs(curr);

		if (ind != 0)
		{
			if (curr == mp[arr[ind - 1]].first && dp[ind][0] != -1)
				return dp[ind][0];
			else if (curr == mp[arr[ind - 1]].second && dp[ind][1] != -1)
				return dp[ind][1];
		}

		long long temp;

		if (curr > mp[arr[ind]].first && curr < mp[arr[ind]].second)
			temp = min(2 * (long long)mp[arr[ind]].second - (long long)curr - (long long)mp[arr[ind]].first + mine(ind + 1, mp[arr[ind]].first, dp),
					   (long long)curr - 2 * (long long)mp[arr[ind]].first + (long long)mp[arr[ind]].second + mine(ind + 1, mp[arr[ind]].second, dp));
		else if (curr >= mp[arr[ind]].second)
			temp = curr - mp[arr[ind]].first + mine(ind + 1, mp[arr[ind]].first, dp);
		else
			temp = mp[arr[ind]].second - curr + mine(ind + 1, mp[arr[ind]].second, dp);

		if (ind == 0)
			return temp;

		if (curr == mp[arr[ind - 1]].first)
			return dp[ind][0] = temp;
		return dp[ind][1] = temp;
	}

	long long minTime(int n, vector<int> &locations, vector<int> &types)
	{
		int m = 2;
		vector<vector<long long>> dp(n, vector<long long>(m, (long long)-1));
		for (int i = 0; i < n; i++)
			mp[types[i]] = {1e9, -1e9};

		for (int i = 0; i < n; i++)
			mp[types[i]] = {min(mp[types[i]].first, locations[i]),
							max(mp[types[i]].second, locations[i])};

		for (auto it : mp)
			arr.push_back(it.first);
		sort(arr.begin(), arr.end());
		return mine(0, 0, dp);
	}
};