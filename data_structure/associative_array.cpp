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
using ll = long long; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<ll, ll> A;
    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 0){
            ll k, v;
            cin >> k >> v;
            A[k] = v;
        }else{
            ll k;
            cin >> k;
            cout << A[k] << '\n';
        }
    }
    return 0;
}
// Write Here
