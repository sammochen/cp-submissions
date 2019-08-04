/*
Original problem: https://www.hackerrank.com/challenges/palindrome-index
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
	// helper function - determines if s is a palindrome if index was excluded
	int isp(string s, int index) {
		int l = 0, r = s.length() - 1;
		while (l < r) {
			if (l == index) {
				l++;
			}
			if (r == index) {
				r--;
			}
			if (s[l] != s[r]) {
				return 0;
			}
			l++, r--;
		}
		return 1;
	}

	void main() {

		string s;
		cin >> s;

		int l = 0, r = s.length() - 1;
		// searches from left and right, inwards. if there is a difference, it has to be either one, otherwise its -1
		while (l < r) {
			if (s[l] != s[r]) {
				if (isp(s, l)) {
					cout << l << endl;
					return;
				}
				if (isp(s, r)) {
					cout << r << endl;
					return;
				}
				cout << -1 << endl;
				return;
			}
			l++, r--;
		}
		cout << -1 << endl;
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