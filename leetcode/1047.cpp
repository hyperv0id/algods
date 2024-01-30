# https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/submissions/419824447/
class Solution:
    def removeDuplicates(self, s: str) -> str:
        stk = []
        for c in s:
            if len(stk) == 0 or stk[-1] != c:
                stk.append(c)
            else:
                stk.pop()
        return ''.join(stk)
