class Solution:
    def combinationSum(self, n, k):
        res = []
        path = []

        def backtrack(start, remaining, need):
            # success: exact k numbers and sum n
            if remaining == 0 and need == 0:
                res.append(path.copy())
                return
            # failure/pruning
            if remaining < 0 or need < 0 or start > 9:
                return

            # further pruning using lower/upper bound sums
            # minimal sum achievable with 'need' numbers starting at 'start'
            if need > 0:
                min_sum = need * (2 * start + (need - 1)) // 2
                # maximal sum achievable with 'need' numbers within 1..9, not reusing
                # largest available digits end at 9, so sum of last 'need' numbers ≤ 9 + 8 + ...
                # however must be ≥ start, thus we cap by 9
                max_start = min(9 - need + 1, start)
                # choose the largest 'need' digits we can use: 9, 8, ..., 9-need+1
                max_sum = need * (2 * 9 - (need - 1)) // 2
                # if min_sum > remaining or max_sum < remaining, no need to continue
                if min_sum > remaining or max_sum < remaining:
                    return

            for x in range(start, 10):
                path.append(x)
                backtrack(x + 1, remaining - x, need - 1)
                path.pop()

        backtrack(1, n, k)
        return res