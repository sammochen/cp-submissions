/*
Original problem: https://codeforces.com/contest/1203/problem/D2
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
    void main() {
        // traverse both ways and look for the earliest finish
		string s, t;
		cin >> s >> t; // s is long, t is short

		VI L(t.size()); // L[i] is the earliest index of t[i]
		VI R(t.size()); // ^ but latest
		
		int ptr = 0;
		REP(i,0,s.size()) {
			if (t[ptr] == s[i]) {
				L[ptr] = i;
				ptr++;
			}
		}

		ptr = t.size() - 1;
		RREP(i, (int)s.size() - 1, 0) {
			if (t[ptr] == s[i]) {
				R[ptr] = i;
				ptr--;
			}
		}

		// i find the largest gap available
		int ans = 0;

		// earliest t[end] to end
		ans = max(ans, (int)s.size() - L[t.size() - 1] - 1);
		// start to latest t[start]
		ans = max(ans, R[0]);

		REP(i,0,(int)t.size() - 1) {
			// diff(L[i] and R[i+1])
			ans = max(ans, R[i+1] - L[i] - 1);
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