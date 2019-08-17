/*
Original problem: https://atcoder.jp/contests/abc136/tasks/abc136_f
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

#define NE 0
#define NW 1
#define SW 2
#define SE 3

const ll mod = 998244353;

namespace SOLVE {
	struct point {
		ll x, y;
		VI q; // holds count of quads
		point(ll a, ll b) {
			x = a, y = b;
			q.resize(4);
		}
	};

	struct sortpoint {
		bool operator() (point &a, point &b) {
			return a.x < b.x;
		}
	};

	ll twop(ll x) {
		if (x == 0) {
			return 1;
		}
		ll h = twop(x/2);
		return x % 2 == 0 ? h*h % mod : h*h*2 % mod;
	}

    void main() {
        ll n,a,b;
		cin >> n;
		vector<point> points(n, point(0,0));

		// initialise		
		REP(i,0,n){
			cin >> a >> b;
			points[i] = point(a,b);
		}

		sort(points.begin(), points.end(), sortpoint());

		// forward order: work out NW and SW
		// this is O(n^2) - not good
		REP(i,0,n) {
			REP(j,0,i) { // j is behind i
				if (points[j].y < points[i].y) {
					points[j].q[NE]++;
					points[i].q[SW]++;
				} else {
					points[j].q[SE]++;
					points[i].q[NW]++;
				}
			}
		}

		// work out q
		ll ans = 0;
		for (point x: points) {
			ll count = 0; // how many counts of this point

			// itself and any combination of any other point
			count += twop(x.q[0] + x.q[1] + x.q[2] + x.q[3]);

			// two other
			count += (twop(x.q[0]) - 1) * (twop(x.q[2]) - 1);
			count += (twop(x.q[1]) - 1) * (twop(x.q[3]) - 1);

			// three other
			count += (twop(x.q[0]) - 1) * (twop(x.q[1]) - 1) * (twop(x.q[2]) - 1);
			count += (twop(x.q[0]) - 1) * (twop(x.q[1]) - 1) * (twop(x.q[3]) - 1);
			count += (twop(x.q[0]) - 1) * (twop(x.q[2]) - 1) * (twop(x.q[3]) - 1);
			count += (twop(x.q[1]) - 1) * (twop(x.q[2]) - 1) * (twop(x.q[3]) - 1);

			// all other
			count += (twop(x.q[0]) - 1) * (twop(x.q[1]) - 1) * (twop(x.q[2]) - 1) * (twop(x.q[3]) - 1);
			
			// cout << thisans << endl;
			ans += count;
			ans %= mod;
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