/*
Original problem:
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
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	void main() {
		string s, ans;
		cin >> s;
		for (char c : s) {
			c = tolower(c);
			int vowel = 0;
			for (char v : "aeiouy") {
				if (c == v) {
					vowel = 1;
				}
			}
			if (!vowel) {
				ans.push_back('.');
				ans.push_back(c);
			}
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
