/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_d
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

namespace SOLVE {
    void main() {
        ll n, w, a, b;
        cin >> n >> w;
        vector < PLL > objs(n);

        REP(i, 0, n) {
            cin >> a >> b;
            objs[i] = MP(a, b);
        }

        VLL dp(w + 1, -1); // dp[i] stores the best value for weight i

        dp[0] = 0;
        ll ans = 0;
        REP(i, 0, n) {
            RREP(oldw, w, 0) {
                if (dp[oldw] != -1) {
                    ll neww = oldw + objs[i].first;
                    if (neww <= w) {
                        dp[neww] = max(dp[neww], dp[oldw] + objs[i].second);
                    }
                }
            }
        }

        REP(weight, 0, w + 1) {
            ans = max(ans, dp[weight]);
        }
        cout << ans << endl;
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