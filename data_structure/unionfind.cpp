// 失敗するからこそ そこから立ち向かって行く強さがあってそんな強さが本当の強さだと私は思うから
#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Credits : Beet-library https://beet-aizu.github.io/library/
struct UnionFind{
    int num;
    vector<int> Size, Par;
    UnionFind(){}
    UnionFind(int n): num(n), Size(n, 1), Par(n, 0){iota(all(Par), 0);}

    int find(int x){
        if(x == Par[x])return x;
        return Par[x] = find(Par[x]);
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            num--;
            if(Size[x] < Size[y])swap(x, y);
            Par[y] = x;
            Size[x] += Size[y];
        }
    }

    int size(int x){
        return Size[find(x)];
    }

    int count() const{
        return num;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    UnionFind uf = UnionFind(n);
    while(m--){
        int op, u, v;
        cin >> op >> u >> v;
        if(op)cout << uf.same(u, v) << '\n';
        else uf.unite(u, v);
    }
    return 0;
}
// Write Here
