/*
Original problem: https://codeforces.com/problemset/problem/1187/E
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
	int n;
	vector<VI> E;
	VLL ch; // ch[i] is number of children in subtree(i)
	VLL dp; // dp[i] is points if rooted at i
	ll ans = 0;

	ll ndfs(int a, int prev, int depth) {
		ll dpcount = depth; // tracks score
		ll chcount = 1; // itself

		for (int b : E[a]) {
			if (b != prev) {
				dpcount += ndfs(b, a, depth + 1);
				chcount += ch[b];
			}
		}
		ch[a] = chcount;
		return dpcount;
	}

	// re-rooting is O(1)
	void pdfs(int a, int prev) {
		if (a != 1) {
			dp[a] = dp[prev] + n - ch[a] * 2;
		}
		ans = max(ans, dp[a]); // keep best
		for (int b : E[a]) {
			if (b != prev) {
				pdfs(b, a);
			}
		}
	}

    void main() {
		int a, b;
		cin >> n;
		E.resize(n + 1);
		ch.resize(n + 1);
		dp.resize(n + 1);
		
		REP(i,0,n-1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		dp[1] = ndfs(1, 0, 1); // find the number of nodes in subtree while working out score of 1-rooted
		pdfs(1, 0); // re-rooting for all possibilities

		cout << ans;
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