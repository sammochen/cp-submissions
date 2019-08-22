/*
Original problem: https://codeforces.com/problemset/problem/1197/B
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
        // find the max, then it should be strictly decreasing from both ends
        int n, big = 0, ind;
        cin >> n;
        VI A(n);

        REP(i, 0, n) {
        	cin >> A[i];
        	if (A[i] > big) {
        		big = A[i];
        		ind = i;
        	}
        }

        REP(i, ind, n - 1) {
        	if (A[i] <= A[i + 1]) {
        		cout << "NO" << endl;
        		return;
        	}
        }

        RREP(i, ind, 1) {
        	if (A[i] <= A[i - 1]) {
        		cout << "NO" << endl;
        		return;
        	}
        }
		
        cout << "YES" << endl;
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