/*
Original problem: https://atcoder.jp/contests/abc134/tasks/abc134_c
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

const ll mod = 1e9+7;

namespace SOLVE {
    void main() {
        int n;
		cin >> n;
		VI A(n);
		deque<int> dq;

		// my attempt at a O(n) solution
		// trying to avoid O(nlogn) sorting

		REP(i,0,n) {
			cin >> A[i];

			if (dq.size() == 0) {
				dq.push_front(A[i]);
			} else if (dq.size() == 1) {
				if (A[i] >= dq.front()) {
					dq.push_front(A[i]);
				} else {
					dq.push_back(A[i]);
				}
			} else if (A[i] >= dq.front()) {
				dq.push_front(A[i]);
				dq.pop_back();
			} else if (A[i] >= dq.back()) {
				dq.pop_back();
				dq.push_back(A[i]);
			}
		}

		REP(i,0,n) {
			if (dq.size() == 1) {
				cout << dq.front() << endl;
			} else {
				if (A[i] == dq.front()) {
					cout << dq.back() << endl;
				} else {
					cout << dq.front() << endl;
				}
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