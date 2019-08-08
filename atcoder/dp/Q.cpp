/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_q
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
	struct fenwick {
		int maxn;
		VLL A; // stores the fenwick tree

		void build(int n) {
			maxn = n;
			A.resize(maxn+1);
		}

		// update x with value v
		// this means i jump UP: all future when jumping down will see it
		void update(int x, ll v) {
			if (x > maxn) {
				return;
			}
			A[x] = max(A[x], v);
			int next = x + (x & -x);
			update(next, v);
		}

		ll query(int x) {
			if (x == 0) {
				return A[0];
			}
			int next = x - (x & -x);
			return max(query(next), A[x]);
		}
	};

    void main() {
        int n;
		cin >> n;

		fenwick tree;
		tree.build(n);

		VI h(n); // height
		VI b(n); // beauty
		
		REP(i,0,n){
			cin >> h[i];
		}
		REP(i,0,n){
			cin >> b[i];
		}

		REP(i,0,n){
			ll best = tree.query(h[i] - 1); // this is the best beauty if considering height below h[i]
			tree.update(h[i], best + b[i]);
		}

		ll ans = tree.query(n);
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