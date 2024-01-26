#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
struct Item{
    int value;
    int weight;
};


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr,arr+n, [] (Item &a, Item &b){
           return (double)a.value/a.weight>(double)b.value/b.weight; 
        });
        double ans =0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight <= w)
            {
                ans += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                ans += arr[i].value *((double)w/arr[i].weight);
                break;
            }
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