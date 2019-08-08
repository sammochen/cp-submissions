/*
Original problem: 
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
        int n, k;
        cin >> n >> k;
        VI A(n);
        REP(i, 0, n) {
            cin >> A[i];
        }
        VI win(k + 1);
        win[0] = 0; // 0 cannot make a move: loss
        REP(i, 0, k + 1) {
            // if win[i] is a losing pos, win[i + A[j]] is a winning position
            if (win[i] == 0) {
                REP(j, 0, n) {
                    if (i + A[j] <= k) {
                        win[i + A[j]] = 1;
                    }
                }
            }
        }
        string ans = (win[k] == 1) ? "First" : "Second";
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