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

struct PrefixSum{
    vector<ll> pref;
    PrefixSum(){}
    PrefixSum(vector<ll> v){
        pref.pb(0);
        for(ll el: v)
            pref.pb(pref.back() + el);
    }
    // 1 - based indexing
    ll sum_1(int l, int r){
        return pref[r] - pref[l - 1];
    }
    // 0 - based indexing
    ll sum_0(int l, int r){
        return pref[r] - pref[l];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    PrefixSum pf = PrefixSum(a);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pf.sum_0(l, r) << '\n';
    }
    return 0;
}
// Write Here
