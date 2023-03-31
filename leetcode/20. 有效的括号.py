class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for c in s:
            if len(stk) == 0:
                stk.append(c)
                continue
            elif c == ']' and stk[-1] == '[' \
                or c == ')' and stk[-1] == '(' \
                or c == '}' and stk[-1] == '{':
                stk.pop()
            elif c == ']' and stk[-1] != '[' \
                or c == ')' and stk[-1] != '(' \
                or c == '}' and stk[-1] != '{':
                return False
            else:
                stk.append(c)
        return len(stk) == 0