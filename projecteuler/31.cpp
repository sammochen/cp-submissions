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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
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

namespace SOLVE {
	VLL coins = {1,2,5,10,20,50,100,200};
	ll n = 200, m = coins.size();;
	vector<VLL> dp(n+1, VLL(m, -1));
	
	ll get(ll i, ll j) { // ways to reach i, allowing use of j
		if (i == 0) return 1;
		if (i < 0) return 0;
		if (j == 0) return 1;
		
		if (dp[i][j] != -1) return dp[i][j];
		
		ll ways = 0;
		ways += get(i - coins[j], j); // use one j
		ways += get(i, j-1); // no j
		dp[i][j] = ways;
		return ways;
	}
	
	void main() {
		ll ans = get(n,m-1);
		
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
