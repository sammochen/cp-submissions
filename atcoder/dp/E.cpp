/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_e
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const int inf = 1e9+7;

namespace SOLVE {
	void main() {
		ll n, w, a, b;
        cin >> n >> w;
        vector<PLL> objs(n);

        REP(i,0,n){
            cin >> a >> b;
            objs[i] = MP(a,b);
        }
        // maximum value is 100000
        // dp[i] is the smallest weight of a value - if dp[i] = inf not possible
        VLL dp(100001, inf); 
        dp[0] = 0;
        REP(i,0,n) {
            RREP(oldv, 100000, 0) {
                if (dp[oldv] != -1) { // then i can possibly add something to it
                    ll oldw = dp[oldv];
                    ll neww = oldw + objs[i].first;
                    ll newv = oldv + objs[i].second;

                    if (neww <= w) {
                        dp[newv] = min(dp[newv], neww); 
                    }
                }
            }
        }

        
        RREP(v, 100000, 0) {
            if (dp[v] != inf) {
                cout << v << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}