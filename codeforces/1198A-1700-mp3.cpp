/*
Original problem: https://codeforces.com/problemset/problem/1198/A
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
		int n, I;
		cin >> n >> I;
		VI A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		int k = 8 * I / n;
		int K = (1 << (min(k, 25))); 
		sort(A.begin(), A.end());

		VI pre(n);
		pre[1] = 1;
		REP(i,1,n) {
			pre[i] = pre[i - 1] + (A[i] != A[i - 1]);
		}

		int ans = n;
		int L = 0, R = 0;
		while (R < n) {
			// cout << L << ' ' << R << ' ' << pre[R] - pre[L] + 1<< endl;
			if (pre[R] - pre[L] + 1 <= K) {
				int change = n - R + L - 1;
				ans = min(ans, change);
				R++;
			} else {
				L++;
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