/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_l
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
	    ll n;
	    cin >> n;
	    VLL A(n);
	    REP(i, 0, n) {
	        cin >> A[i];
	    }

	    // dp[i][j] is X-Y when the array is from i to j, inclusive
	    vector < VLL > dp(n, VLL(n));

        // interesting for order - purely for bottom-up dp purposes
	    RREP(start, n - 1, 0) {
	        REP(length, 0, n - start) {
	            ll end = start + length;
	            if (start == end) {
	                dp[start][end] = A[start];
	            } else {
	                dp[start][end] = max(A[end] - dp[start][end - 1], A[start] - dp[start + 1][end]);
	            }
	        }
	    }
	    cout << dp[0][n - 1] << endl;

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