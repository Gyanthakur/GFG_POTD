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
	int is_bleak(int n)
	{
	    // Code here.
	    // 28.10.23 POTD
	    
	    int x = n;
	    
	    while(x >= (n-log2(n))){
	        if((x + __builtin_popcount(x)) == n)
	            return 0;
	           
	        x--;
	    }
	    
	    return 1;
	    
	    /*  
	        '__builtin_popcount(x)' returns the number of set bits in the
	            binary representation of the integer 'x'.
	    
	    */
	}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}


// DEFAULT BOILERPLATE
// void solution()
// {

// }
// signed main()
// {
// ios_base::sync_with_stdio(false); 
// cin.tie(NULL);
// cout.tie(NULL);
// cin>>t;
// while(t--)
// {
// solution();
// cout<<endl;
// }
// return 0;
// }
