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
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length())
           return false;
        s1+=s1;
        return (s1.find(s2)!=-1)?true:false;
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