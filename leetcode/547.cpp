# https://leetcode.cn/problems/number-of-provinces/submissions/420095969/
class UnionFind:
    def __init__(self, n:int) -> None:
        self.n = n
        self.par = list(range(n))
        pass

    def add(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x>y:
            x,y = y,x;
        self.par[y] = x
    
    def find(self, n):
        if self.par[n] == n:
            return n
        self.par[n] = self.find(self.par[n])
        return self.par[n]

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    uf.add(i, j)
        ans = 0
        for i in range(n):
            if uf.find(i) == i:
                ans += 1
        return ans