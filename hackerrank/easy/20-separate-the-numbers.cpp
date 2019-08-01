/*
Original problem: https://www.hackerrank.com/challenges/separate-the-numbers
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
	// helper function that determines whether x could become og
	// x is the starting number, og is the final string
	int possible(ll x, string target) {
		string s = "";
		while (s.length() < target.length()) {
			s += to_string(x);
			x++;
		}
		return s == target;
	}

	void main() {
		string s;
		cin >> s;
		int ans = -1;

		REP(i, 1, s.length() / 2 + 1) { // first number is size 1 to s/2
			if (possible(stoll(s.substr(0, i)), s)) {
				ans = i;
				break;
			}
		}
		if (ans == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES " << s.substr(0, ans) << endl;
		}
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