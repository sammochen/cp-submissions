/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	VLL ind(string a, string b) {
		VLL ans(a.length());
		ll found = 0;
		
		a = a + a;
		REP(i,0,b.length()) {
			if (a.substr(i, b.length()) == b) {
				found = 1;
				ans[i] = 1;
			}
		}
		if (found == 0) {
			VLL x(0);
			return x;
		}
		return ans;
	}
	
	void main() {
		ll n, m;
		cin >> n;
		vector<string> S(n);
		REP(i,0,n) {
			cin >> S[i];
		}
		m = S[0].length();
		
		vector<VLL> grid(n);
		REP(i,0,n) {
			grid[i] = ind(S[0], S[i]);
			if (grid[i].size() == 0) {
				cout << -1 << endl;
				return;
			}
		}
		
		ll ans = 1e18+5;
		REP(target,0,m) {
			ll sum = 0;
			REP(i,0,n) {
				// find first 1 before target
				REP(j,0,m) {
					if (grid[i][(target-j+m)%m] == 1) {
						sum += j;
						break;
					}
				}
			}
			ans = min(ans, sum);
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
