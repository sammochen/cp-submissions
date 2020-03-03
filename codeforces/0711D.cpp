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

const ll mod = 1e9+7;

namespace SOLVE {	
	VVLL E;
	VLL visited;
	ll cycle;
	ll edges;

	// 2^x mod 
	ll tp(ll x) {
		if (x == 0) return 1;
		ll h = tp(x/2);
		ll ans = x % 2 ? h * h * 2 : h * h;
		ans %= mod;
		return ans;
	}

	// dfs - count total edges and cycle size
	void dfs(ll at, ll prev, ll d) {
		visited[at] = d;
		
		for (ll to : E[at]) {
			if (visited[to] && visited[to] < d - 1) {
				// cycle detected
				cycle = d - visited[to] + 1;
				edges -= cycle - 1;
			} else if (!visited[to]) {
				edges++;
				dfs(to, at, d+1);
			}
		}
	}

	void main() {
		ll n;
		cin >> n;
		E.resize(n+1);
		visited.resize(n+1);

		REP(i,1,n+1) {
			ll x;
			cin >> x;
			E[i].push_back(x);
			E[x].push_back(i);
		}

		ll ans = 1;
		REP(i,1,n+1) {
			edges = 0;
			cycle = 0;
			if (!visited[i]) {
				dfs(i, -1, 1);
				
				if (cycle)	ans *= (tp(cycle) + mod - 2);
				ans %= mod;
				ans *= tp(edges);
				ans %= mod;
			}
		}

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
