#include<bits/stdc++.h>
using namespace std;

int equalSum(int n, vector<int> &a)
{
    int sume =0;
    int sumf=0;
    for(auto it : a)
    sume+=it;
    for(int i=0;i<n;i++)
    {
        sumf+=a[i];
        if(sumf==sume)return i+1;
        sume-=a[i];
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans=equalSum(n,a);
    cout<<ans<<endl;

return 0;
}