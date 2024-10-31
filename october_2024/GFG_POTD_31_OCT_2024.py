class Solution:
    def alternateSort(self,arr):
        arr.sort() 
        result = []
        i, j = 0, len(arr) - 1

        while i <= j:
            if i != j:
                result.append(arr[j])
                result.append(arr[i])
            else:
                result.append(arr[j])  
            i += 1
            j -= 1

        return result