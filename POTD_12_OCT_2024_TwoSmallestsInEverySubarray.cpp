class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
    
        // Variable to store the maximum sum found
        long maxSum = -1;
    
        // Iterate over each element in the array except the
        // last one
        for (int i = 0; i < n - 1; i++) {
    
            // Initialize the minimum element as the current
            // element
            int minn = arr[i];
    
            // Initialize the second minimum element as the next
            // element
            int secondMinn = arr[i + 1];
    
            // Iterate over the remaining elements in the array
            for (int j = i + 1; j < n; j++) {
                // Update the minimum and second minimum
                // elements
                if (minn >= arr[j]) {
                    secondMinn = minn;
                    minn = arr[j];
                }
                else if (secondMinn > arr[j]) {
                    secondMinn = arr[j];
                }
    
                // Calculate the current sum of the minimum and
                // second minimum elements
                long currSum = minn + secondMinn;
    
                // Update the maximum sum if the current sum is
                // greater
                maxSum = max(maxSum, currSum);
            }
        }
    
        // Return the maximum sum found
        return maxSum;

    }
};
