/*
Original problem: https://codeforces.com/problemset/problem/1202/D
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
	ll nc2(ll x) {
		return x * (x - 1) / 2;
	}

	ll bs(ll x) { // return the index of nc2 that is <= x
		ll L = 0, R = 99999;
		while (L < R) {
			ll M = (L + R) / 2;
			if (nc2(M) <= x) {
				L = M + 1;
			} else {
				R = M;
			}
		}
		return L - 1;
	}

    void main() {
		ll n;
		cin >> n;

		// each number can be represented as
		// some sums of (nc2(j) * k)
		// 1 + j * 3 + k * 7

		ll maxj = 0;
		VI sevens(100001);

		while (n) {
			ll j = bs(n);
			ll k = n / nc2(j);
			maxj = max(maxj, j);
			sevens[j] = k;
			n = n % nc2(j);
		}

		// careful of duplicates!
		// if there is a (j,k) pair of (2,2) and (3,3)
		// it is: 133737
		// the latter sets includes all the previous sets' 3s

		string ans = "1";
		REP(i,1,maxj + 1) {
			ans += '3';
			ans += string(sevens[i], '7');
		}
		cout << ans << endl;
    }
}


signed main() {
	int t;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}