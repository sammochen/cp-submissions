/*
Original problem: https://codeforces.com/problemset/problem/1178/B
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
        // for every o, see how many 'w' is on each side and multiply
		// efficiently via pre and suf sums
		string s = "", S;
		cin >> S;
		
		REP(i,1,S.size()) {
			if (S[i] == 'v' && S[i-1] == 'v') {
				s += "w";
			} else if (S[i] == 'o') {
				s += "o";
			}
		}
		
		int n = s.length();
		VLL pre(n + 1);
		VLL suf(n + 1);
		
		REP(i,0,n) {
			pre[i + 1] = pre[i] + (s[i] == 'w');
			suf[n - 1 - i] = suf[n - i] + (s[n - 1 - i] == 'w');
		}

		ll ans = 0;
		REP(i,0,n) {
			if (s[i] == 'o') {
				ans += max(0LL, pre[i]) * max(0LL, suf[i + 1]);
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