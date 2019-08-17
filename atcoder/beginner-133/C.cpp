/*
Original problem: https://atcoder.jp/contests/abc133/tasks/abc133_c
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

const ll mod = 2019;

namespace SOLVE {
    void main() {
        ll L, R;
		cin >> L >> R;
		VI rem(mod);
		REP(i,L,R+1) {
			if (i % mod == 0) {
				cout << 0 << endl;
				return;
			}
			rem[i%mod] =  1;
		}

		ll ans = 2019 * 2019;
		REP(i,0,mod) {
			REP(j,0,i) {
				if (rem[i] && rem[j]) {
					ans = min(ans, (i * j) % mod);
				}
			}
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