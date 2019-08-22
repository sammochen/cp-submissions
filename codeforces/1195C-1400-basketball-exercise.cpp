/*
Original problem: https://codeforces.com/problemset/problem/1195/C
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
		// dp! realise that some choice will be made every 2
		int n;
		cin >> n;
		vector<VLL> A(2, VLL(n));
		REP(i,0,2) {
			REP(j,0,n) {
				cin >> A[i][j];
			}
		}

		vector<VLL> dp(2, VLL(n)); // dp[i][j] is the best score after choosing A[i][j]     
		ll ans = 0;

		REP(j, 0, n) {
			REP(i, 0, 2) {
				ll opt1 = j - 1 >= 0 ? dp[1 - i][j - 1] : 0;
				ll opt2 = j - 2 >= 0 ? dp[1 - i][j - 2] : 0;
				dp[i][j] = A[i][j] + max(opt1, opt2);
				ans = max(ans, dp[i][j]);
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