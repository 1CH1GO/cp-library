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

const int maxn = 5e8 + 1000;
bool pflag[maxn];
vector<int> primes;

void seive(){
    memset(pflag, true, sizeof pflag);
    pflag[0] = pflag[1] = false;
    for(int i = 2; i * i <= maxn; i++){
        if(pflag[i]){
            for(int j = i * i; j < maxn; j += i)
                pflag[j] = false;
        }
    }

    for(int i = 0; i < maxn; i++)
        if(pflag[i])
            primes.pb(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    seive();
    int n, a, b;
    cin >> n >> a >> b;
    int pi_n = upper_bound(all(primes), n) - primes.begin();
    
    vector<int> ans;
    for(int i = 0;;i++){
        if(a * i + b < (int)primes.size() && primes[a * i + b] <= n)
            ans.pb(primes[a * i + b]);
        else break;
    }
    cout << pi_n << ' ' << ans.size() << '\n';
    for(auto el: ans)cout << el << ' ';
    cout << '\n';
    return 0;
}
// Write Here
