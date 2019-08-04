/*
Original problem: https://www.hackerrank.com/challenges/minimum-loss
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define MP make_pair

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {

	void main() {
		// strategy: use a set and its in-built lower_bound function

		int n;
		cin >> n;
		set<ll> S;
		set<ll>::iterator itr;

		ll temp;
		ll ans = 1e18;

		REP(i, 0, n) {
			cin >> temp;
			// look for the next highest number in the set
			itr = S.lower_bound(temp + 1);
			if (itr != S.end()) {
				ans = min(ans, *itr - temp);
			}
			S.insert(temp);
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