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

const ll mod = 1e8;

namespace SOLVE {
	ll n1, n2, k1, k2;
	vector<vector<vector<VLL>>> dp(101, vector<vector<VLL>>(101, vector<VLL>(11, VLL(11, -1))));
	
	ll get(ll a, ll b, ll c, ll d) {
		// debug(a,b,c,d);
		if (a < 0 || b < 0) {
			return 0;
		}
		if (c > k1 || d > k2) {
			return 0;
		}
		
		if (a == 0 && b == 0) {
			return 1;
		}
		
		if (dp[a][b][c][d] != -1) {
			return dp[a][b][c][d];
		}
		ll ans = (get(a-1, b, c+1, 0) + get(a, b-1, 0, d+1)) % mod;
		dp[a][b][c][d] = ans;
		return ans;
	}
		
	void main() {
		cin >> n1 >> n2 >> k1 >> k2;
		
		cout << get(n1, n2, 0, 0) << endl;
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
