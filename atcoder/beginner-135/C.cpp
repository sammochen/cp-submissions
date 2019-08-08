/*
Original problem: https://atcoder.jp/contests/abc135/tasks/abc135_c
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
        int n;
		cin >> n;
		VI towns(n+1);
		VI heros(n);
		REP(i,0,n+1) {
			cin >> towns[i];
		}
		REP(i,0,n) {
			cin >> heros[i];
		}
		
		ll ans = 0;
		REP(i,0,n) {
			// greedy: hero should always save own town first
			if (heros[i] <= towns[i]) {
				ans += heros[i];
				towns[i] -= heros[i];
			} else if (heros[i] <= towns[i] + towns[i+1]) {
				ans += heros[i];
				towns[i + 1] -= (heros[i] - towns[i]);
				towns[i] = 0;
			} else {
				ans += (towns[i] + towns[i+1]);
				towns[i + 1] = 0;
				towns[i] = 0;
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