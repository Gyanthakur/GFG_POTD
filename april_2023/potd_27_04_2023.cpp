#include <bits/stdc++.h>
using namespace std;

int main()
{
	return 0;
}

class Solution
{
public:
	int n;
	vector<vector<int>> tree;
	void update(int idx, char ch, string &s)
	{
		tree[n + idx][ch - 'a']++;
		tree[n + idx][s[idx] - 'a']--;
		s[idx] = ch;

		for (int i = (n + idx) / 2; i >= 1; i /= 2)
		{
			vector<int> c(26);
			for (int j = 0; j < 26; j++)
				c[j] = tree[2 * i][j] + tree[2 * i + 1][j];
			tree[i] = c;
		}
	}

	vector<int> helper(int node, int low, int high, int l, int r)
	{

		if (l > high || r < low)
		{
			vector<int> curr(26);
			return curr;
		}
		if (l <= low && r >= high)
			return tree[node];

		int mid = (low + high) >> 1;
		vector<int> left = helper(2 * node, low, mid, l, r);
		vector<int> right = helper(2 * node + 1, mid + 1, high, l, r);
		vector<int> curr(26);
		for (int i = 0; i < 26; i++)
			curr[i] = left[i] + right[i];
		return curr;
	}

	vector<char> easyTask(int len, string s, int q, vector<vector<string>> &queries)
	{
		n = len;
		while (__builtin_popcount(n) != 1)
			n++;
		tree.resize(2 * n, vector<int>(26));
		for (int i = 0; i < len; i++)
		{
			vector<int> freq(26);
			freq[s[i] - 'a']++;
			tree[n + i] = freq;
		}

		for (int i = n - 1; i >= 1; i--)
		{
			vector<int> c(26);
			for (int j = 0; j < 26; j++)
				c[j] = tree[2 * i][j] + tree[2 * i + 1][j];
			tree[i] = c;
		}

		vector<char> ans;
		for (auto &query : queries)
		{
			if (query[0] == "1")
			{
				int idx = stoi(query[1]);
				char ch = query[2][0];
				update(idx, ch, s);
			}
			else
			{
				int l = stoi(query[1]), r = stoi(query[2]), k = stoi(query[3]);
				vector<int> queryans = helper(1, 0, n - 1, l, r);
				int cnt = 0;
				for (int i = 25; i >= 0; i--)
				{
					cnt += queryans[i];
					if (cnt >= k)
					{
						ans.push_back('a' + i);
						break;
					}
				}
			}
		}

		return ans;
	}
};