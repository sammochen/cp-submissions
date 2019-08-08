/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_s
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

const ll mod = 1e9+7;

namespace SOLVE {
	void addmod(ll & a, ll b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}

	void main() {
		ll n, r;
		string s;

		cin >> s >> r;
		n = s.length();

		vector < VLL > dp(r, VLL(2)); // dp[rem][tight]

		// base case
		dp[0][0] = 1;
		dp[0][1] = 1;

		RREP(index, n - 1, 0) {
			vector < VLL > temp(r, VLL(2));
			int digit = (s[index] - '0');

			REP(rem, 0, r) {
				// the tight version is the sum of all prev ones loose, plus the same number tight
				REP(num, 0, digit) {
					addmod(temp[rem][1], dp[(rem - num + 10 * r) % r][0]);
				}
				addmod(temp[rem][1], dp[(rem - digit + 10 * r) % r][1]);

				// the loose version is sum of 0-9
				REP(num, 0, 10) {
					addmod(temp[rem][0], dp[(rem - num + 10 * r) % r][0]);
				}
			}
			dp = temp;
		}


		// ans is dp[0][1] - 1 (the 0 was counted as a 0modr solution)
		ll ans = dp[0][1] == 0 ? mod - 1 : dp[0][1] - 1;
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