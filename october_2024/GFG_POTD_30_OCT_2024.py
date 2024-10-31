from collections import Counter

class Solution:
    def countPairsWithDiffK(self, arr, k):
        num_count = Counter(arr)  # Count occurrences of each element
        count = 0

        for num in num_count:
            # Check for pairs (num, num + k)
            if num + k in num_count:
                count += num_count[num] * num_count[num + k]

        return count