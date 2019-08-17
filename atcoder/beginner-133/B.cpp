/*
Original problem: https://atcoder.jp/contests/abc133/tasks/abc133_b
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
    void main() {
        int n, d;
		cin >> n >> d;
		vector<VLL> A(n, VLL(d));
		REP(i,0,n) {
			REP(j,0,d) {
				cin >> A[i][j];
			}
		}
		ll ans = 0;
		// for every two pairs
		REP(i,0,n) {
			REP(j,0,i) {
				ll t = 0;
				REP(k,0,d) {
					t += (A[i][k] - A[j][k]) * (A[i][k] - A[j][k]);
				}
				ll s = sqrt(t);
				if (s * s == t) {
					ans++;
				}
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