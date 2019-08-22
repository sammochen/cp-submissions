/*
Original problem: https://codeforces.com/problemset/problem/1196/D1
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
    void main() {
        // preprocess the string into R first, G first and B first
		// prefix sums - O(n), 3 times
		// linear scan to find smallest k-substring, 3 times

		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;

		// prefix sums: pref[i][0] = 0
		vector<VI> pref(3, VI(n + 1));
		string rgb = "RGB";
		
		REP(i,0,3) {
			REP(j,0,n) {
				pref[i][j + 1] = pref[i][j] + (s[j] != rgb[(i + j) % 3]);
			}
		}

		int ans = inf;
		REP(i,0,3) {
			REP(j,0,n-k+1) {
				ans = min(ans, pref[i][k + j] - pref[i][j]);
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