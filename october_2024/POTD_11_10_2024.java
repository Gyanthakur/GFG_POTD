
//{ Driver Code Starts
import java.util.ArrayList;
import java.util.List;

// } Driver Code Ends
class Solution {
  public List<Integer> rearrange(List<Integer> arr) {
    // Code here
    List<Integer> ans = new ArrayList<>();

    int n = arr.size();
    if (n <= 0) {
      return ans;
    }
    // Initialize the 'ans' list with -1 values
    for (int i = 0; i < n; i++) {
      ans.add(-1); // Use 'add()' to add default values
    }

    for (int i = 0; i < n; i++) {
      if (arr.get(i) >= 0 && arr.get(i) < n) {
        ans.set(arr.get(i), arr.get(i));
      }
    }

    return ans;
  }
}
