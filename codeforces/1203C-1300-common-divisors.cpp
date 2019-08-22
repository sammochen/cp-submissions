/*
Original problem: https://codeforces.com/contest/1203/problem/C
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

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

namespace SOLVE {
    void main() {
        ll n;
		ll g, x;
		cin >> n >> g;
		
		REP(i,1,n) {
			cin >> x;
			g = gcd(g, x);
		}

		ll ans = 0;
		for (ll f = 1; f * f <= g; f++) {
			if (f * f == g) {
				ans++;
				break;
			}
			if (g % f == 0) {
				ans += 2;
			}
		}
		cout << ans << endl;
    }
}


signed main() {
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}