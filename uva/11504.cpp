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
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
	// get topological order (reversed)
	void dfs1(ll at, VVLL & E, VLL & visited, VLL & order) {
		visited[at] = 1;
		for (ll to : E[at]) {
			if (!visited[to]) {
				dfs1(to, E, visited, order);
			}
		}
		order.push_back(at);
	}

	// find connected components
	void dfs2(ll at, VVLL & E, VLL & visited) {
		visited[at] = 1;
		for (ll to : E[at]) {
			if (!visited[to]) {
				dfs2(to, E, visited);
			}
		}
	}
	void main() {
		ll n, m;
		in(n, m);
		VVLL E(n);
		VLL indeg(n);

		REP(i,0,m) {
			ll a, b;
			in(a, b);
			E[a-1].push_back(b-1);
			indeg[b-1]++;
		}

		VLL order(n);
		VLL v1(n);
		REP(i,0,n) {
			if (!v1[i]) dfs1(i, E, v1, order);
		}
		reverse(order.begin(), order.end());

		VLL v2(n);
		ll ans = 0;
		REP(i,0,n) {
			if (!v2[order[i]]) {
				dfs2(order[i], E, v2);
				ans++;
			}
		}

		cout << ans << endl;
	}
}


signed main() {
	ll t;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
