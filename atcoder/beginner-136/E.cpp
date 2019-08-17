/*
Original problem: https://atcoder.jp/contests/abc135/tasks/abc135_e
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
		int x, y;
		cin >> n >> x >> y;
		if (n % 2 == 0 && (x + y) % 2 != 0) {
			cout << "-1" << endl;
			return;
		} 

		int i = 0, j = 0;
		queue<PII> ans;

		while (i != x || j != y) {
			int di, dj;

			if (i != x) {
				if (abs(x - i) >= n) {
					di = n;
					dj = 0;
				} else {
					di = abs(x - i);
					dj = n - di;
				}			
			} else {
				if (abs(y - j) >= 2 * n) {
					di = 0;
					dj = n;
				} else {
					dj = abs(y - j) / 2;
					di = n - dj;
				}
			}

			i = x > i ? i + di : i - di;
			j = y > j ? j + dj : j - dj;

			ans.push(MP(i, j));
		}

		cout << ans.size() << endl;
		while (ans.size()) {
			cout << ans.front().first << ' ' << ans.front().second << endl;
			ans.pop();
		}
		
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