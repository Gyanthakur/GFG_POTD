class Solution:
    def lengthOfLoop(self, head):
        s, f = head, head
        while f and f.next:
            s, f = s.next, f.next.next
            if s == f:
                cnt = 1
                while s.next != f:
                    s, cnt = s.next, cnt + 1
                return cnt
        return 0