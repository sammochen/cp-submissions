/*
Original problem: https://atcoder.jp/contests/abc136/tasks/abc136_c
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

    	REP(i, 0, n) {
    		cin >> A[i];
    	}

    	// greedy: always choose the lowest possible
    	int x = A[0] - 1;
    	REP(i, 1, n) {
    		if (x > A[i]) { // too big! not possible
    			cout << "No" << endl;
    			return;
    		} else if (x == A[i]) { // if the prev number is the same, we cannot -1
    			x = A[i];
    		} else { // all good
    			x = A[i] - 1;
    		}
    	}
    	cout << "Yes" << endl;
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