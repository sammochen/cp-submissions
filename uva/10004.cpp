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

namespace SOLVE {	
	// returns 0 if non-bicolorable
	ll dfs(ll at, VVLL & E, VLL & visited) {
		for (ll to : E[at]) {
			if (visited[to]) {
				if (visited[to] == visited[at]) return 0;
			} else {
				visited[to] = visited[at] == 1 ? 2 : 1;
				if (dfs(to, E, visited) == 0) return 0;
			}
		}
		return 1;
	}

	void main() {
		ll n;
		in(n);
		if (n == 0) exit(0);

		ll m;
		in(m);

		VVLL E(n);
		REP(i,0,m) {
			ll a, b;
			in(a,b);
			E[a].push_back(b);
			E[b].push_back(a);
		}

		VLL visited(n);

		visited[0] = 1;
		ll bi = dfs(0,E,visited);
		string ans = bi ? "BICOLORABLE." : "NOT BICOLORABLE.";
		cout << ans << endl;


	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
