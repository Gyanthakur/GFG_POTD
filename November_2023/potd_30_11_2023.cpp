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
    int minimumStep(int n){
        //complete the function here
        int edge=0;
        while(n!=1)
        {
            if(n%3==0)
            {
                n=n/3;
                edge++;
            }
            else
            {
                n--;
                edge++;
            }
        }
        return edge;
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