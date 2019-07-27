/* 
Original problem: https://www.hackerrank.com/challenges/maximum-subarray-sum
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

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
		ll n, m, temp;
		ll p = 0, ans = 0; // p is the prefix sum so far, mod m
		cin >> n >> m;

		set<ll> s; // this set contains all the prefix values, mod m 
		set<ll>::iterator itr;
		s.insert(0); 

		REP(i, 0, n) {
			cin >> temp;
			temp %= m;

			p += temp;
			p %= m;

			s.insert(p);

			// look for the next biggest thing
			itr = s.lower_bound(p + 1);
			if (itr != s.end()) {
				ll total = (p - *itr + m) % m;
				ans = max(ans, total);
			}

			// since it is modded, the next biggest thing could be from 0 onwards
			itr = s.lower_bound(0);
			if (itr != s.end()) {
				ll total = (p - *itr + m) % m;
				ans = max(ans, total);
			}
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