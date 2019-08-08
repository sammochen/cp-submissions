/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_r
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

	vector<VLL> operator * (vector<VLL> A, vector<VLL> B) {
		int n = A.size();
		vector<VLL> C(n, VLL(n));
		REP(i, 0, n) {
			REP(k, 0, n) {
				REP(j, 0, n) {
					addmod(C[i][j], (A[i][k] * B[k][j]) % mod);
				}
			}
		}
		return C;
	}

	vector<VLL> operator ^ (vector<VLL> A, ll k) {
		if (k == 1) {
			return A;
		}
		vector<VLL> h = A ^ (k / 2);
		h = h * h;
		h = k % 2 == 1 ? h * A : h;
		return h;
	}

	void main() {
		// matrix multiplication - k steps is sum(A^k)
		ll n, k;
		cin >> n >> k;
		vector<VLL> A(n, VLL(n));

		REP(i, 0, n) {
			REP(j, 0, n) {
				cin >> A[i][j];
			}
		}

		vector<VLL> ansA = A ^ k;
		ll ans = 0;
		REP(i, 0, n) {
			REP(j, 0, n) {
				addmod(ans, ansA[i][j]);
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