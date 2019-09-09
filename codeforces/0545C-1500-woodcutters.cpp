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

#define x first
#define h second

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

const ll inf = 1e18 + 5;

namespace SOLVE {	
	void main() {
		ll n, a, b;
		cin >> n;
		
		vector<PLL> trees(n + 2);
		trees[0] = MP(-inf, 0);
		trees[n+1] = MP(inf, 0);
		
		REP(i,0,n) {
			cin >> a >> b;
			trees[i+1] = MP(a,b); // x, h
		}
		
		vector<VLL> dp(n, VLL(2)); // dp[i][0] is left, [1] is right
		dp[0][0] = 1;
		dp[0][1] = 0;
		if (trees[1].x + trees[1].h < trees[2].x) {
			dp[0][1] = 1;
		}
		
		REP(i,1,n) {
			// going left goes on tree
			if (trees[i+1].x - trees[i+1].h <= trees[i].x) {
				dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			
			// going left goes on tree right
			} else if (trees[i+1].x - trees[i+1].h <= trees[i].x + trees[i].h) {
				dp[i][0] = max(dp[i-1][0] + 1, dp[i-1][1]);
				
			// going left does not go on tree right!
			} else {
				dp[i][0] = max(dp[i-1][1] + 1, dp[i-1][0] + 1);
			}
			
			// go right if you can!
			dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
			if (trees[i+1].x + trees[i+1].h < trees[i+2].x) {
				dp[i][1]++;
			}
			
		}
		
		cout << max(dp[n-1][0], dp[n-1][1]) << endl;
			
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
