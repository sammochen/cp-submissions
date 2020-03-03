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
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	void main() {
		ll n, k;
		cin >> n >> k;
		
		VLL A(n);		
		REP(i,0,n) {
			cin >> A[i];
		}
		// prefix and suffix sums
		VLL kk(n+1); // kk[i] is the sum of the k from i
		
		REP(i,0,k) {
			kk[0] += A[i];
		}
		
		REP(i,1,n-k+1) {
			kk[i] = kk[i - 1] + A[i + k - 1] - A[i - 1];
		}
		
		vector<PLL> back(n+1); // best from the back
		back[n-k] = MP(kk[n-k], n-k);
		RREP(i, n-k-1, 0) {
			if (kk[i] >= back[i+1].first) {
				back[i] = MP(kk[i], i);
			} else {
				back[i] = back[i+1];
			}
		}
		
		ll best = 0;
		PLL ans = MP(-1,-1);
		REP(i,0,n-k+1) {
			if (kk[i] + back[i+k].first > best) {
				best = kk[i] + back[i+k].first;
				ans = MP(i, back[i+k].second);
			}
		}
		
		cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
		
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
