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

#define DEBUG 1

#ifdef DEBUG
#define debug(str) do { cout << str << endl; } while (false)
#else
#define debug(str) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

const ll mod = 1e9 + 7;
namespace SOLVE {
	
	void main() {
		ll n, k, nax = 100005;
		cin >> n >> k;
	
		VLL dp(nax); // dp[i] is how many ways they can eat up to i with k parting
		VLL pre(nax); // pre[i] is sum up to i
		
		dp[0] = 1;
		pre[0] = 1;
		REP(i,1,nax) {
			dp[i] = dp[i-1];
			dp[i] += i >= k ? dp[i-k] : 0;
			dp[i] %= mod;
			
			pre[i] = (pre[i-1] + dp[i]) % mod;
		}
		
		REP(i,0,n) {
			ll a, b;
			cin >> a >> b;
			cout << (pre[b] - pre[a-1] + mod) % mod << endl;
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
