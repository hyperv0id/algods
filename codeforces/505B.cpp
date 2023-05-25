#include <bits/stdc++.h>
using namespace std;


int n,m,q;
int v,w,c;

class UnionFind{
    vector<int> parent;
    int size = n;
public:
    UnionFind(int n){
        this->size = n;
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int get_parent(int n){
        while(parent[n] != n){
            n = get_parent(parent[n]);
        }
        return n;
    }
    void add(int x, int y){
        x = get_parent(x);
        y = get_parent(y);
        if(x>y){
            parent[x] = y;
        }else{
            parent[y] = x;
        }
    }
};

// https://codeforces.com/problemset/submission/505/206890418
int main(){
    cin >> n >> m;
    vector<UnionFind> colors = vector<UnionFind>(m, UnionFind(n+1));
    for (int i = 0; i < m; i++) {
        cin >> v >> w >> c;
        colors[c-1].add(v,w);
    }
    cin>>q;
    while(q--){
        cin>>v>>w;
        int ans = 0;
        for(auto col : colors) {
            ans += col.get_parent(v) == col.get_parent(w);
        }
        cout << ans << endl;
    }

    return 0;
}
