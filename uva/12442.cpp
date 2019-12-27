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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	VLL visited; // 0 for unvisited, 1 for visiting, 2 for done
	VVLL E;
	VLL dp;
	VLL first;

	ll inloop; // this is -1 if not in a loop, otherwise the value of loop-starter

	// returns number at dfs
	ll dfs(ll at, ll depth) {
		// 2 is done
		if (visited[at] == 2) return dp[at];

		// if you see yourself, it is a loop!
		if (visited[at] == 1) {
			dp[at] = depth - first[at];
			inloop = at;
			return dp[at];
		}

		// if there is nowhere to go, it is dead end
		if (E[at].size() == 0) {
			dp[at] = 1;
			visited[at] = 2;
			return 1;
		}

		// if there is somewhere to go, tag itself
		first[at] = depth;
		visited[at] = 1;
		ll next = dfs(E[at][0], depth + 1);

		// if 'at' is not in a loop,
		if (inloop == -1) {
			dp[at] = 1 + next;
			visited[at] = 2;
			return dp[at];
		} else {
			dp[at] = next;
			if (at == inloop) inloop = -1;
			visited[at] = 2;
			return dp[at];
		}
	}

	ll test = 1;
	void main() {
		visited.clear();
		E.clear();
		dp.clear();
		first.clear();

		ll n;
		in(n);

		visited.resize(n);
		E.resize(n);
		dp.resize(n);
		first.resize(n, -1);
		
		REP(i,0,n) {
			ll a, b;
			in(a, b);
			a--; b--;
			E[a].push_back(b);
		}

		REP(i,0,n) {
			if (visited[i] != 2) dfs(i, 0);
		}
		
		ll hi = 0;
		ll ans = -1;
		RREP(i,n-1,0) {
			if (dp[i] >= hi) {
				ans = i + 1;
				hi = dp[i];
			}
		}

		printf("Case %lld: %lld\n", test++, ans);
	}
}


signed main() {
	ll t; in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
