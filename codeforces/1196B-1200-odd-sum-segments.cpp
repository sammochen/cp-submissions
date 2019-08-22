/*
Original problem: https://codeforces.com/problemset/problem/1196/B
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
        int n, k, x;
		int oddcount = 0;
		queue<int> q;

		cin >> n >> k;

		REP(i,0,n) {
			cin >> x;
			if (x % 2 == 1) {
				oddcount++;
				q.push(i + 1);
			}
		}

		if (oddcount >= k && (oddcount - k) % 2 == 0) {
			cout << "YES" << endl;
			REP(i, 0, k - 1) {
				cout << q.front() << ' ';
				q.pop();
			}
			cout << n << endl;
		} else {
			cout << "NO" << endl;
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