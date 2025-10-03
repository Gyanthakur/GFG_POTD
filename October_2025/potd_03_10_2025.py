class Solution:
    def possibleWords(self, arr):
        keypad = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        n = len(arr)
        result = []

        def backtrack(index, current_word):
            if index == n:
                result.append(current_word)
                return
            
            if keypad[arr[index]]:
                for char in keypad[arr[index]]:
                    backtrack(index + 1, current_word + char)
            else:
              
                backtrack(index + 1, current_word)

        backtrack(0, "")
        return result
