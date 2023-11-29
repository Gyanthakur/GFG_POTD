#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution { 

public: 

    int isEulerCircuit(int V, vector<int>adj[]){ 

        int evens =0; 

        int odds =0; 

        for(int i =0;i< V;i++){ 

            if(adj[i].size() & 1) odds++; 

            else evens++; 

        } 

        if(evens == V) return 2; 

        else if (odds <= 2) return 1; 

        else return 0; 

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