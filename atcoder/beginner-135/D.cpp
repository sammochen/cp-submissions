/*
Original problem: https://atcoder.jp/contests/abc135/tasks/abc135_d
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
	ll addto(ll& a, ll b) {
		a += b;
		if (a >= mod) {
			a -= mod;
		}
	}

    void main() {
        string s;
		cin >> s;
		int n = s.size();
		// dp[i][13] is the number after the ith string with rem 13
		VLL dp(13);

		dp[0] = 1;

		REP(i,0,n) { // each char
			VLL next(13);
			REP(rem,0,13) { // each rem
				if (s[i] == '?') {
					REP(digit, 0, 10) { // each unknown digit
						addto(next[(rem * 10 + digit) % 13], dp[rem]);
					}
				} else {
					int digit = s[i] - '0';
					addto(next[(rem * 10 + digit) % 13], dp[rem]);
				}
			}
			dp = next;
		}
		cout << dp[5];
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