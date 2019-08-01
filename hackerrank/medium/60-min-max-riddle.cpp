/*
Original problem: https://www.hackerrank.com/challenges/min-max-riddle
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
		int n;
		cin >> n;
		VLL A(n); // holds the initial array
		VLL radius(n, 1); // farthest distance that A[k] is a minimum of, from left to right. initially itself.
		VLL m(n + 1, -1); // m[i] is the largest value A[k] that has at least radius of i

		REP(i, 0, n) {
			cin >> A[i];
		}

		// to work out the range of values where A[x] is the smallest, the stack holds the indices of prior numbers
		// and helps calculate these ranges in O(n) time
		stack<ll> st;

		// determine how far to the RIGHT A[i] is the smallest
		REP(i, 0, n + 1) {
			// if A[i] is smaller than top, we must pop off the stack until A[i] is >= top.
			// for every pop, we can determine its radius
			while (st.size() && (i == n || A[i] < A[st.top()])) {
				ll x = st.top();
				radius[x] += i - x - 1; // this is how far right
				st.pop();
			}
			if (i != n) {
				st.push(i);
			}
		}

		// exactly the same but reverse: determine how far to the LEFT
		RREP(i, n - 1, -1) {
			while (st.size() && (i == -1 || A[i] < A[st.top()])) {
				ll x = st.top();
				radius[x] += x - i - 1;

				// here, we update m and break ties by choosing the maximum
				m[radius[x]] = max(m[radius[x]], A[x]);
				st.pop();
			}
			if (i != -1) {
				st.push(i);
			}
		}

		// this last step fixes holes in m, as well as adjusts when m[i] is smaller than m[i+1]
		// try this test case:
		// 8
		// 2 7 1 6 5 6 3 1
		// m[2] would produce 2 and m[3] would produce 5 - in reality m[3] should be 5 too.

		RREP(i, n - 1, 1) {
			m[i] = max(m[i + 1], m[i]);
		}

		for (int i = 1; i <= n; i++) {
			cout << m[i] << ' ';
		}
		cout << endl;
	}
}

signed main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}
	return 0;
}