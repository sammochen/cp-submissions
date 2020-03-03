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
	ll n;	
	VLL parent;
	VVLL E;

	ll maxdist;
	ll furthest;


	void dfs(ll at, ll dist) {
		if (dist > maxdist) {
			furthest = at;
			maxdist = dist;
		}

		for (ll to : E[at]) {
			if (parent[at] == to) continue;
			parent[to] = at;

			dfs(to, dist + 1);
		}		
	}

	void main() {
		cin >> n;
		E.resize(n);

		REP(i,0,n-1) {
			ll a, b;
			cin >> a >> b;
			a--;b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		parent.clear();
		parent.resize(n, -1);
		
		ll a, b;
		maxdist = -1;
		dfs(0, 0);
		a = furthest;

		parent.clear();
		parent.resize(n, -1);

		maxdist = -1;
		dfs(furthest, 0);
		b = furthest;

		// put all on the path
		queue<ll> Q;
		VLL d(n, inf);
		for (ll v = b; v != a; v = parent[v]) {
			Q.push(v);
			d[v] = 0;
		}
		Q.push(a);
		d[a] = 0;

		ll diameter = Q.size() - 1;
		
		ll far = -1;
		ll farthest = -1;
		while (Q.size()) {
			ll at = Q.front(); Q.pop();
			if (d[at] >= far && at != a && at != b) {
				far = d[at];
				farthest = at;
			}
			for (ll to : E[at]) {
				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
				}
			}
		}

		cout << diameter + far << endl;
		cout << a+1 << ' ' << b+1 << ' ' << farthest+1 << endl;
		



		
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
