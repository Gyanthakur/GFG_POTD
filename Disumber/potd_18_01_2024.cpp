#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
       const int INF = INT_MAX;
        
        // Create an array to represent the coverage of each position
        int coverage[n];
        for (int i = 0; i < n; ++i) {
            coverage[i] = -1;  // Initialize coverage to -1 (not covered)
        }

        // Populate the coverage array based on the sprinkler ranges
        for (int i = 0; i < n; ++i) {
            if (gallery[i] != -1) {
                int left = std::max(0, i - gallery[i]);
                int right = std::min(n - 1, i + gallery[i]);
                for (int j = left; j <= right; ++j) {
                    coverage[j] = std::max(coverage[j], right);
                }
            }
        }

        // Count the number of sprinklers needed
        int count = 0;
        int curr_end = -1;

        for (int i = 0; i < n; ++i) {
            if (coverage[i] == -1) {
                return -1;  // It's not possible to cover the entire gallery
            }

            if (i > curr_end) {
                ++count;
                curr_end = coverage[i];
            }
        }

        return count; // code here
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
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}