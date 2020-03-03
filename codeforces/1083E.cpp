/*
Original problem: https://codeforces.com/contest/1083/problem/E
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
	struct rect {
		ll x, y, a;
	};

	struct sortrect {
		bool operator() (rect &a, rect &b) {
			return a.x < b.x;
		}
	};

	struct line {
		ll m, c;
		ll y(int x) {
			return m * x + c;
		}
		db xint(line L) {
			return (db)(L.c - c) / (m - L.m);
		}
	};

    void main() {
		ll n, a, b, c;

		scanf("%lld", &n);
		vector<rect> R;
		REP(i,0,n) {
			scanf("%lld%lld%lld", &a, &b, &c);
			R.push_back({a,b,c});
		}

		sort(R.begin(), R.end(), sortrect());

		ll ans = 0;

		// convex hull trick
		deque<line> dq; // maintains the max of mx + c for any x
		dq.push_front({0,0}); // default - max is 0

		for (rect r : R) {
			// if the rightmost line is not max at r.y, delete! 
			while (dq.size() >= 2 && dq.back().y(r.y) <= dq[dq.size() - 2].y(r.y)) {
				dq.pop_back();
			}

			// dp[i] = area - cost + max(dp[j] - xj * yi)
			ll value = r.x * 1LL * r.y - r.a + dq.back().y(r.y);
			ans = max(ans, value);

			// insert this new line
			// m = R[i - 1].x
			// c = dp[i]
			line newline = {-r.x, value};
			// insert to the front. eliminate redundant ones at the front first
			// line 0 is redundant if the xint(new,0) > xint(0,1)
			while (dq.size() >= 2 && newline.xint(dq[0]) >= dq[1].xint(dq[0])) {
				dq.pop_front();
			}
			dq.push_front(newline);
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