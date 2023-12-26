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
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
        int n = a.size(), m = a[0].size();
        vector<vector<int>> res;
        vector<int> coordinates(4, -1);
        int max_area = 0;
        for (int l = 0; l < m; l++) {
            vector<int> sum(n, 0);
            for (int r = l; r < m; r++) {
                for (int i = 0; i < n; i++) {
                    sum[i] += a[i][r];
                }
                set<pair<int, int>> st = {make_pair(0, -1)};
                int run_sum = 0;
                for (int i = 0; i < n; i++) {
                    run_sum += sum[i];
                    auto it = st.lower_bound({run_sum, -1});
                    if (it != st.end() and it -> first == run_sum) {
                        if ((r - l + 1) * (i - it -> second) > max_area) {
                            max_area = (r - l + 1) * (i - it -> second);
                            coordinates = {it -> second + 1, l, i, r};
                        }
                    }
                    st.insert({run_sum, i});
                }
            }
        }
        
        if (max_area == 0) return res;
        for (int i = coordinates[0]; i <= coordinates[2]; i++) {
            vector<int> curr;
            for (int j = coordinates[1]; j <= coordinates[3]; j++) {
                curr.push_back(a[i][j]);
            }
            res.push_back(curr);
        }
        return res;
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