class Solution {
    public ArrayList<Integer> countBSTs(int[] arr) {
        // Code here
        
        int[] cloned = arr.clone();
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer,Integer> h = new HashMap<>();
        
        
        Arrays.sort(arr);
        int n = arr.length;
        
        // Step 1: find the catalan numbers
        long[] catalan = new long[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i = 2;i<=n;i++){
            catalan[i] = 0;
            for(int j = 0; j<i;j++){
                catalan[i] += (catalan[j] * catalan[i-j-1]);
            }
        }
        
        // Step 2:  Find unique bsts for each distinct element
        
        for(int i = 0;i < n; i++){
            int L = i; // number elements in left subtree (elements are <= arr[i])
            int R = n-i-1; // number of elements in right subtree (elements are > arr[i])
            
            long bstsPossible = catalan[L] * catalan[R];
            // bstsPossible = number of valid left subtrees * number of valid right subtrees
            
            h.put(arr[i],(int) bstsPossible);
        }
        
        // Step 3: Form the answer list
        
        for(int num: cloned){
            ans.add(h.get(num));
        }
        
        return ans;
    }
}
