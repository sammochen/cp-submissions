/*
Original problem: https://www.hackerrank.com/challenges/making-candies
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
	// ceil function - round up
	ll ceil(ll top, ll bottom) {
		if (top <= 0) {
			return 0;
		}
		return top % bottom == 0 ? top / bottom : top / bottom + 1;
	}

	// ll multiplication - return LLONG_MAX if overflow
	ll mult(ll a, ll b) {
		ll x = LLONG_MAX;
		if (x / a < b) {
			return LLONG_MAX;
		}
		return a * b;
	}

	ll mult(ll a, ll b, ll c) {
		return mult(mult(a, b), c);
	}

	// helper function to distribute the worker/machines. ideally keeps them at most 1 apart.
	PLL share(PLL current, ll extra) {
		if (abs(current.first - current.second) <= extra) {
			ll total = current.first + current.second + extra;
			return make_pair(total / 2, total - total / 2);
		}
		if (current.first < current.second) {
			return make_pair(current.first + extra, current.second);
		}
		return make_pair(current.first, current.second + extra);
	}

	void main() {
		ll m, w, p, n;
		ll money = 0;
		cin >> m >> w >> p >> n;

		PLL mw = make_pair(m, w); // one variable for machines and workers

		// the strategy is to calculate the number of days required if we decided to not buy any more workers or machines
		// in every iteration of the while loop, we will buy as many machines and workers as possible, and recalculate

		ll day = 0;
		ll ans = ceil(n, mult(m, w));
		while (day <= ans) {
			// the amount of days to have $p
			ll dayjump = ceil(p - money, mult(mw.first, mw.second)); // this is how many days it takes to be able to get p

			// we jump this many days and update day, money and machine/workers as well as ans
			day += dayjump;
			money += mult(dayjump, mw.first, mw.second);

			mw = share(mw, money / p);
			money %= p;

			ans = min(ans, day + ceil(n - money, mult(mw.first, mw.second)));
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