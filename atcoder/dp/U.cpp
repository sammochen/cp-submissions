/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_u
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
	int MSB(ll x) {
		RREP(i,31,0) {
			if (x & (1 << i)) {
				return i;
			}
		}
		return -1;
	}

    void main() {
    	int n;
    	cin >> n;
    	vector<VLL> score(n, VLL(n));

    	REP(i, 0, n) {
    		REP(j, 0, n) {
    			cin >> score[i][j];
    		}
    	}		

		VLL group(1 << n); // useful to store values of groups together
    	VLL dp(1 << n); // stores the best score, allowing subsplits
    	group[0] = 0; // a group of 0 is 0
		dp[0] = 0; // a group of 0 is 0

    	REP(i, 1, 1 << n) {
			// first, find what it would be in one group
			int msb = MSB(i);
			group[i] = group[i ^ (1 << msb)];
			REP(rest, 0, msb) {
				if (i & (1 << rest)) {
					group[i] += score[msb][rest];
				}
			}

			// dp[i] is now at least this size
			dp[i] = group[i];
			// try all possible splits 
			for (int submask=i; submask != 0; submask = (submask - 1) & i) {
				dp[i] = max(dp[i], dp[submask] + dp[i ^ submask]);
			}
    	}

    	ll ans = dp[(1 << n) - 1];
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