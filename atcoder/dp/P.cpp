/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_p
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
	int n;
	vector<VLL> E;
	vector<VLL> dp;

	void dfs(int v, int prev) {
		ll white = 1, black = 1;
		for (int e : E[v]) {
			if (e != prev) {
				dfs(e, v);

				white *= ((dp[e][0] + dp[e][1]) % mod);
				white %= mod;

				black *= (dp[e][0]);
				black %= mod;
			}
		}

		dp[v][0] = white;
		dp[v][1] = black;
	}

    void main() {
        int a,b;
		cin >> n;
		E.resize(n+1);

		REP(i,0,n-1){
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		dp.resize(n+1, VLL(2)); // dp[i][black] gives the possibilities if it was white/black

		// rooted at 1: ans is 1,white + 1,black
		dfs(1, 0);
		ll ans = (dp[1][0] + dp[1][1]) % mod;
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