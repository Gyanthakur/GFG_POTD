#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>ans;
            int n = txt.size();
            int m = pat.size();
            for(int i=0;i<n;i++)
            {
                int x=i;
                for(int j=0;j<m;j++)
                {
                    if(txt[x] == pat[j])
                        x++;
                    else
                        break;
                }
                if(x-i == m)
                    ans.push_back(i+1);
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
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}