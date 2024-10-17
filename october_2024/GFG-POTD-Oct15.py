class Solution:
    
    #Complete this fuction
    #Function to count the number of subarrays which adds to the given sum.
    def subArraySum(self, arr, tar):
    # Dictionary to store the frequency of cumulative sums
        cumulative_sum_count = {}
        cumulative_sum_count[0] = 1  
        cumulative_sum = 0
        count = 0
        
        for num in arr:
            cumulative_sum += num
            
            
            if (cumulative_sum - tar) in cumulative_sum_count:
                count += cumulative_sum_count[cumulative_sum - tar]
            
            # Update the dictionary with the current cumulative sum
            if cumulative_sum in cumulative_sum_count:
                cumulative_sum_count[cumulative_sum] += 1
            else:
                cumulative_sum_count[cumulative_sum] = 1
        
        return count
        
        
