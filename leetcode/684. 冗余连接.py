# https://leetcode.cn/problems/redundant-connection/submissions/420097445/

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
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        uf = UnionFind(n)
        for e in edges:
            a,b = uf.find(e[0] - 1), uf.find(e[1] - 1)
            if a == b:
                return e
            uf.add(a, b)

        return []