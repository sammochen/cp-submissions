/*
Original problem: https://codeforces.com/problemset/problem/1201/D
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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll inf = 1e18+5;

namespace SOLVE {
	PLL minpll(PLL &a, PLL &b) {
		return a.first <= b.first ? a : b;
	}

	void main() {
		ll n, m, k, q, a, b;
		cin >> n >> m >> k >> q;

		// leftmost and rightmost treasures in each row
		VLL left(n + 1, inf);
		VLL right(n + 1, 0);

		// safe[i] is 1 when it is a safe col
		VLL safe(m + 1);
		
		VLL lcol(m + 5, inf);
		VLL rcol(m + 5, inf);
		
		// the largest row that a treasure is in - once we finish with maxrow were done
		ll maxrow = 0; 

		// 1,1 - makes dealing with row 1 easier
		left[1] = 1;
		right[1] = 1;

		REP(i, 0, k) {
			cin >> a >> b;
			left[a] = min(left[a], b);
			right[a] = max(right[a], b);
			maxrow = max(a, maxrow);
		}
		REP(i, 0, q) {
			cin >> a;
			safe[a] = 1;
		}

		REP(i, 1, m + 1) {
			lcol[i] = safe[i] ? i : lcol[i-1];
		}
		RREP(i, m, 1) {
			rcol[i] = safe[i] ? i : rcol[i+1];
		}

		// (moves, lastcolumn) - holds the current best options
		// 0: end at left, go left
		// 1: end at left, go right
		// 2: end at right, go left
		// 3: end at right, go right
		vector<PLL> opt(4, MP(0, 1)); // start with 0 moves at space 1
		
		REP(row, 1, maxrow + 1) {
			if (right[row] == 0) { // no treasure - onwards
				continue;
			}
			vector<PLL> nextopt(4, MP(inf, inf));

			// these are the 4 safe columns
			ll LL = lcol[left[row]];
			ll LR = lcol[right[row]];
			ll RL = rcol[left[row]];
			ll RR = rcol[right[row]];

			// see what each opt[i] can offer
			for (PLL o : opt) {
				// amount of moves required to end on L or R
				ll endL = o.first + abs(right[row] - o.second) + abs(right[row] - left[row]);
				ll endR = o.first + abs(left[row] - o.second) + abs(right[row] - left[row]);

				if (row == maxrow) { // if that was the last row, thats it!
					PLL tempL = MP(endL, -1);
					PLL tempR = MP(endR, -1);

					nextopt[0] = minpll(nextopt[0], tempL);
					nextopt[1] = minpll(nextopt[1], tempR);
				} else {
					// amount of moves required to end on each of LL, LR, RL, RR
					PLL tempLL = MP(endL + abs(left[row] - LL), LL);
					PLL tempLR = MP(endR + abs(right[row] - LR), LR);
					PLL tempRL = MP(endL + abs(left[row] - RL), RL);
					PLL tempRR = MP(endR + abs(right[row] - RR), RR);

					nextopt[0] = minpll(nextopt[0], tempLL);
					nextopt[1] = minpll(nextopt[1], tempLR);
					nextopt[2] = minpll(nextopt[2], tempRL);
					nextopt[3] = minpll(nextopt[3], tempRR);
				}
			}
			opt = nextopt;
		}

		ll ans = inf;
		REP(i,0,4) {
			ans = min(ans, opt[i].first);
		}
		// add 1 for each step up
		cout << maxrow - 1 + ans << endl; 
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