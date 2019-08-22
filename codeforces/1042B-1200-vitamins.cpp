/*
Original problem: https://codeforces.com/problemset/problem/1042/B
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

const ll inf = 1e9+7;

namespace SOLVE {
	int ABC(string s) {
		int ans = 0;
		for (char c : s) {
			if (c == 'A') {
				ans += 4;
			}
			if (c == 'B') {
				ans += 2;
			}
			if (c == 'C') {
				ans += 1;
			}
		}
		return ans;
	}

    void main() {
        ll n, x;
		cin >> n;
		string s;

		VLL dp(8, inf); // dp[ijk], binary, is having a, b, c 
		
		REP(i,0,n) {
			cin >> x >> s;
			int abc = ABC(s);
			dp[abc] = min(dp[abc], x);
		}

		ll ans = min(dp[7], dp[1] + dp[2] + dp[4]);
		REP(i,0,8) {
			REP(j,0,8) {
				if ((i | j) == 7) {
					ans = min(ans, dp[i] + dp[j]);
				}
			}
		}
		ans = ans == inf ? -1 : ans;
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