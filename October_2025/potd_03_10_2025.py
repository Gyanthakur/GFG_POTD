class Solution:
    def possibleWords(self, arr):
        # code here
        
        map = {2: 'abc', 3:'def', 4: 'ghi', 5: 'jkl', 6: 'mno', 7: 'pqrs', 8: 'tuv', 9: 'wxyz'}
        
        def combination(st, index):
            nonlocal res
            
            if index == len(arr):
                res.append(st)
                return
            
            if arr[index] in map:
                for j in map[arr[index]]:
                    combination(st + j, index+1)
            else:
                combination(st, index+1)
                
        res = []
        combination('', 0)
        return res