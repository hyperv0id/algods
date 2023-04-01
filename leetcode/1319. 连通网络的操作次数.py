# 
# 找到冗余链接, 看看能不能补上剩下的链接

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
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        uf = UnionFind(n)

        surplus = 0 # 过剩, 冗余
        for e in connections:
            a,b = uf.find(e[0] - 1), uf.find(e[1] - 1)
            if a == b:
                surplus += 1
            uf.add(a, b)
        total = 0
        for i in range(n):
            if i == uf.find(i):
                total+=1
        
        need = total - 1
        if need <= surplus:return need

        return -1