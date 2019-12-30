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
	VLL diameter(ll v, ll ignore, VVLL & E) {
		// do 2 bfs to find diameter
		PLL far = {-1,-1}; // dist, v
		queue<ll> Q;
		VLL d(E.size(), inf);
		Q.push(v);
		d[v] = 0;
		while (Q.size()) {
			ll at = Q.front(); Q.pop();
			if (d[at] > far.first) {
				far = {d[at], at};
			}

			for (ll to : E[at]) {
				if (to == ignore) continue;
				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
				}
			}
		}

		// then do it again
		d.clear();
		d.resize(E.size(), inf);
		Q.push(far.second);
		d[far.second] = 0;
		far = {-1,-1};

		VLL p(E.size(), -1); // parent
		while (Q.size()) {
			ll at = Q.front(); Q.pop();
			if (d[at] > far.first) {
				far = {d[at], at};
			}

			for (ll to : E[at]) {
				if (to == ignore) continue;
				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
					p[to] = at;
				}
			}
		}

		VLL path = {};
		for (ll v = far.second; v != -1; v = p[v]) {
			path.push_back(v);
		}
		return path;
	}

	void main() {
		// for every single edge, remove it
		// for the two remaning trees, find the diameter
		ll n;
		in(n);
		VVLL E(n);
		vector<PLL> edges(n-1);
		REP(i,0,n-1) {
			ll a, b;
			in(a, b);
			a--;b--;
			E[a].push_back(b);
			E[b].push_back(a);
			edges[i] = {a,b};
		}

		ll dist = inf;
		PLL make = {-1,-1};
		PLL cut = {-1,-1};

		for (PLL edge : edges) {
			VLL d1 = diameter(edge.first, edge.second, E);
			VLL d2 = diameter(edge.second, edge.first, E);

			ll d1half = d1.size() / 2;
			ll d2half = d2.size() / 2;
			ll d = max({d1half + d2half + 1, (ll)d1.size() - 1, (ll)d2.size() - 1});
			if (d < dist) {
				dist = d;
				make = {d1[d1.size() / 2], d2[d2.size() / 2]};
				cut = edge;
			}
		}

		printf("%lld\n%lld %lld\n%lld %lld\n", dist, cut.first + 1, cut.second + 1, make.first + 1, make.second + 1);



	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
