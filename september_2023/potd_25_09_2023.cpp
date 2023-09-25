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
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // first sort a both array
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // create a priority queue of max heap
        priority_queue<int> pq;
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                // insert a negative element for mean heap
                int sum = (a[i] + b[j]) * -1;
                if(pq.size() < k){
                    pq.push(sum);
                }else if(sum < pq.top()){
                    pq.pop();
                    pq.push(sum);
                }else break;
            }
        }
       // create a vector of size k
        vector<int> result(k--);

        // geting value in vector
        while(!pq.empty()){
            // make value positive at their position
            result[k--] = pq.top()*-1;
            pq.pop();
        }
        
        return result;
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