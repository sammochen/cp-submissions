/*
Original problem: https://www.hackerrank.com/challenges/weighted-uniform-string
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
		string s;
		cin >> s;
		// i want to find the longest streak for each character
		// i will do this by keeping track of current streak and best streak 
		VI current(26);
		VI best(26);

		current[s[0] - 'a'] = 1;
		best[s[0] - 'a'] = 1;

		REP(i, 1, s.length()) {
			if (s[i] != s[i - 1]) {
				current[s[i - 1] - 'a'] = 0;
				current[s[i] - 'a'] = 1;
			}
			else {
				current[s[i] - 'a']++;
			}
			best[s[i] - 'a'] = max(best[s[i] - 'a'], current[s[i] - 'a']);
		}

		// queries: for each number, it is "Yes" if it can divide into 1->26 AND 
		//          for that respective letter the streak is at least as long

		int q, temp;
		cin >> q;
		REP(i, 0, q) {
			cin >> temp;
			int good = 0;
			// try 0 - 25, see if it divides
			REP(letter, 0, 26) {
				if (temp % (letter + 1) == 0) {
					// if it works, see if there are at least (temp / value) of that letter
					if (best[letter] >= temp / (letter + 1)) {
						good = 1;
						break;
					}
				}
			}
			if (good) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
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