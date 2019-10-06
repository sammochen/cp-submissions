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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

const ll mod = 1e9+7;

namespace SOLVE {	
	VVLL E;
	VVLL dp;

	void dfs(ll at, ll prev) {
		ll leaf = 1;

		ll black = 1; // number of ways all children are black
		ll tree = 1; // number of ways to make perfect tree
		
		for (ll to : E[at]) {
			if (to != prev) {
				leaf = 0;
				dfs(to, at);
				black *= dp[to][1]; // multiply by perfect black
				tree *= (dp[to][0] + dp[to][1] * 2 % mod) % mod; // multiply by alone, perfect white, perfect black
				black %= mod;
				tree %= mod;
			}
		}

		tree -= black; // cannot have all black - or else it has lone white
		tree = tree < 0 ? tree + mod : tree;

		dp[at][0] = black;
		dp[at][1] = tree;

	}

	void main() {
		ll n;
		cin >> n;
		E.resize(n+1);
		// dp[node][0]: white, alone - the rest of the tree is good
		// dp[node][1]: white, any perfect tree 
		dp.resize(n+1, VLL(2)); 


		REP(i,0,n-1) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		dfs(1, -1);

		ll ans = (dp[1][1]) * 2 % mod;
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
