/*
Original problem: https://www.hackerrank.com/challenges/lisa-workbook
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
	int special(int start, int end, int num) {
		return (num >= start && num <= end);
	}

	void main() {
		int n, k;
		cin >> n >> k;
		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		int num = 1; // question number
		int ptr = 0; // points to chapter
		int ans = 0; // total special count

		for (int page = 1; page != 0; page++) { // infinite loop!
			int nextnum = min(A[ptr], num + k - 1);
			ans += special(num, nextnum, page);

			if (nextnum == A[ptr]) {
				ptr++;
				num = 1;
				if (ptr == n) {
					break;
				}
			}
			else {
				num = nextnum + 1;
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