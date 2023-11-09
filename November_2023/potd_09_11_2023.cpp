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
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    */
    int columnWithMaxZeros(vector<vector<int>>arr, int N){
        
        int max_count = 0, ans = -1;
        
        for(int i = 0;i<N;i++){
            int count = 0;
            for(int j = 0;j<N;j++){
                //counting zeroes
                if(arr[j][i] == 0){
                    count++;
                }
            }
            
            //updating max_count and ans as required
            if(count > max_count){
                max_count = count;
                ans = i;
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