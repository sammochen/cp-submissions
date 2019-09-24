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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll mod = 1e9 + 7;

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		VLL A(n-1);
		REP(i,0,n-1) cin >> A[i];
		
		VLL dp(n+1); // dp[i] is number of ways of ending at j
		dp[1] = 1;
		
		// for every number
		REP(i,2,n+1) {
			VLL next(n+1);
			
			// work out prefix sum of prev
			VLL pre(i);
			REP(j,1,i) pre[j] = (pre[j-1] + dp[j]) % mod;
			
			// for every number, find next[j]
			REP(j,1,i+1) {
				if (A[i-2] == 0) { // down
					// sum of j to i-1
					next[j] = (pre[i-1] - pre[j-1] + mod) % mod;
				} else {
					// sum of 1 to j-1
					next[j] = pre[j-1];
				}
			}
			dp = next;
		}
		
		ll ans = 0;
		for (ll x : dp) ans = (ans + x) % mod;
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
