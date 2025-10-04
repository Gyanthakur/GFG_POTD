class Solution:
    def addOperators(self, s: str, target: int):
        res = []

        def dfs(idx, path, eval_val, prev):
            if idx == len(s):
                if eval_val == target:
                    res.append(path)
                return

            for i in range(idx, len(s)):
                if i != idx and s[idx] == '0':
                    break
                cur_str = s[idx:i+1]
                cur = int(cur_str)

                if idx == 0:
                    dfs(i+1, cur_str, cur, cur)
                else:
                    dfs(i+1, path + "+" + cur_str, eval_val + cur, cur)
                    dfs(i+1, path + "-" + cur_str, eval_val - cur, -cur)
                    dfs(i+1, path + "*" + cur_str, eval_val - prev + prev * cur, prev * cur)

        dfs(0, "", 0, 0)
        res.sort()
        return res


# Example
sol = Solution()
print(sol.addOperators("125", 7))  # Output: ['1*2+5', '12-5']
