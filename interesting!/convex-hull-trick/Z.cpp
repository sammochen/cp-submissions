/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_z
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
	struct line {
		ll m, c;
		ll ev(ll a) {
			return m * a + c;
		}
		db xint(line L) {
			return ((db)c - L.c) / (L.m - m);
		}
	};


    void main() {
		// convex hull. finding the minimum, gradient gets smaller every time
		ll n, c;
		cin >> n >> c;
		VLL h(n);
		REP(i,0,n) {
			cin >> h[i];
		}

		deque<line> dq;

		REP(i,0,n) {
			// while the first line isnt the lowest
			while (dq.size() >= 2 && dq[0].ev(h[i]) >= dq[1].ev(h[i])) {
				dq.pop_front();
			}
			
			// stores the current best value
			ll value;
			if (i == 0) {
				value = 0;
			} else {
				value = h[i] * h[i] + c + dq.front().ev(h[i]); 
			}
			line newline = {-2 * h[i], h[i] * h[i] + value};

			if (i == n - 1) {
				cout << value << endl;
			}

			// insert to the back i think!
			while (dq.size() >= 2 && newline.xint(dq.back()) <= dq[dq.size() - 2].xint(dq.back())) {
				dq.pop_back();
			}
			dq.push_back(newline);
		}
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