/*
Original problem: https://www.hackerrank.com/challenges/happy-ladybugs
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
	void main() {
		// there are 2 cases:
		// - if there is a space, it is possible to get any arrangement you like. 
		//   we can check frequencies and it is only "NO" if there is freq[i] = 1 for any char
		// - if there are no spaces, we need to check that all the chars have something the same next to them.

		int n;
		cin >> n;
		string s;
		cin >> s;

		int hasspace = 0;
		for (char c : s) {
			if (c == '_') {
				hasspace = 1;
			}
		}

		if (hasspace == 1) {
			// counting freq
			VI freq(26);
			for (char c : s) {
				if (c != '_') {
					freq[c - 'A']++;
				}
			}
			REP(i, 0, 26) {
				if (freq[i] == 1) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		else {
			// linear scan for adjacent differences
			if (s.length() == 1) {
				cout << "NO" << endl;
				return;
			}
			if (s[0] != s[1]) {
				cout << "NO" << endl;
				return;
			}
			if (s[s.length() - 1] != s[s.length() - 2]) {
				cout << "NO" << endl;
				return;
			}
			REP(i, 1, s.length() - 1) {
				if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		// otherwise: YES!
		cout << "YES" << endl;
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