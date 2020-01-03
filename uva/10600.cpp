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
	VLL p; 

	ll getp(ll x) {
		if (p[x] == x) return x;
		p[x] = getp(p[x]);
		return p[x];
	}

	void merge(ll a, ll b) {
		p[getp(a)] = getp(b);
	}

	ll same(ll a, ll b) {
		return getp(a) == getp(b);
	}

	struct edge {
		ll a, b, w;
		bool operator<(const edge & a) {
			return w < a.w;
		}
		bool operator==(const edge & e) {
			return a == e.a && b == e.b && w == e.w;
		}
	};

	ll n, m;
	pair<ll, vector<edge>> mst(vector<edge> E, edge badedge) {
		vector<edge> mst;
		ll mstcost = 0;
		p.clear();
		p.resize(n);
		REP(i,0,n) p[i] = i;

		for (edge e : E) {
			if (e == badedge) continue;
			if (same(e.a, e.b)) continue;
			merge(e.a, e.b);
			mstcost += e.w;
			mst.push_back(e);
		}
		REP(i,0,n) if (!same(0,i)) return {inf, {}};
		return {mstcost, mst};
	}

	void main() {
	
		in(n, m);

		vector<edge> E;

		REP(i,0,m) {
			ll a, b, w;
			in(a,b,w);
			a--; b--;
			E.push_back({a,b,w});
		}

		sort(E.begin(), E.end());

		// find first mst
		pair<ll, vector<edge>> first = mst(E, {-1,-1,-1});
	
		ll cost = inf;
		for (edge e : first.second) {
			cost = min(cost, mst(E, e).first);
		}

		cout << first.first << ' ' << cost << endl;
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
