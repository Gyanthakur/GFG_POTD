//👉🏻 Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length(), m = str2.length();
	    int dp[n+1][m+1];
	    for(int i=0;i<=n;i++)dp[i][0]=0;
	    for(int j=0;j<=m;j++)dp[0][j]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            dp[i][j] = str1[i-1]==str2[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return n+m-2*dp[n][m];
	} 

//👉🏻 logic 

// A.LCS (Longest Common Subsequence)
// The LCS is a subsequence that appears in both strings in the same order, but not necessarily consecutively.
// If you find the LCS between str1 and str2, you know that this part of the two strings can remain unchanged during the transformation. The rest of the characters need to be inserted or deleted.


//B. Insertions and Deletions-
// Deletions: Any character in str1 that is not part of the LCS must be deleted.
// Insertions: Any character in str2 that is not part of the LCS must be inserted into str1.

//C.formula-
//  -Operation =(length of str1-lcs)+(length of str2-lcs).

//👉🏻 time complexcity
// -O(n*m)because we fill the dp table with dimensions (n+1) x (m+1) using nested loops.

//👉🏻Space complexcity
//  -O(n*m) the space required for the DP table

