/*
Original problem: https://codeforces.com/problemset/problem/1202/B
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

const int inf = 1e9 + 7;

namespace SOLVE {
	ll ten(ll x) { // x is guarantee smaller than inf
		while (x < 0) {
			x += 10;
		}
		return x % 10;
	}

    void main() {
		string s;
		cin >> s;

		VLL freq(10, 0); // freq[i] stores the number of steps of i
		REP(i, 1, s.length()) {
			freq[ten(s[i] - s[i - 1])]++;
		}

		// memo[i][j][k] is steps required to jump k with i and j
		vector<vector<VLL>> memo(10, vector<VLL>(10));

		REP(i, 0, 10) {
			REP(j, 0, 10) {
				// do bfs
				VLL d(10, inf);

				queue<PII> q; // num, steps
				q.push(MP(i,0)); 
				q.push(MP(j,0)); 
				d[i] = 0;
				d[j] = 0;

				while (q.size()) {
					int a = q.front().first;
					int dd = q.front().second;
					q.pop();

					int b1 = ten(a + i);
					int b2 = ten(a + j);

					if (dd + 1 < d[b1]) {
						q.push(MP(b1, dd + 1));
						d[b1] = dd + 1;
					}
					if (dd + 1 < d[b2]) {
						q.push(MP(b2, dd + 1));
						d[b2] = dd + 1;
					}
				}

				memo[i][j] = d;
			}
		} 

		REP(i, 0, 10) {
			REP(j, 0, 10) {
				ll ans = 0;
				REP(k, 0, 10) {
					if (memo[i][j][k] == inf && freq[k] >= 1) {
						ans = -1;
						break;
					}
					ans += memo[i][j][k] * freq[k];
				}
				cout << ans << " ";
			}
			cout << endl;
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