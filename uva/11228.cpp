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
typedef pair<db,db> PDD;

namespace SOLVE {	
	db dist(PDD a, PDD b) {
		db one = a.first - b.first;
		db two = a.second - b.second;
		return sqrt(one * one + two * two);
	}
	struct edge {
		ll a, b;
		db dist;
	};

	bool operator<(const edge &a, const edge &b) {
		return a.dist < b.dist;
	}

	VLL p;

	ll getp(ll a) {
		if (p[a] == a) return a;
		p[a] = getp(p[a]);
		return p[a];
	}

	ll same(ll a, ll b) {
		return getp(a) == getp(b);
	}

	ll merge(ll a, ll b) {
		p[getp(a)] = getp(b);
	}

	void main(ll t) {
		ll n;
		db k;
		cin >> n >> k;

		p.resize(n);
		REP(i,0,n) p[i] = i;

		vector<PDD> points(n);
		REP(i,0,n) cin >> points[i].first >> points[i].second;

		vector<edge> edges;
		REP(i,0,n) {
			REP(j,i+1,n) {
				edges.push_back({i,j,dist(points[i], points[j])});
			}
		}

		sort(edges.begin(), edges.end());

		db roads = 0, railroads = 0;
		ll cnt = 0;
		for (edge e : edges) {
			if (same(e.a, e.b)) continue;
			merge(e.a, e.b);

			if (e.dist <= k) {
				roads += e.dist;
			} else {
				railroads += e.dist;
				cnt++;
			}
		}

		printf("Case #%lld: %lld %.0f %.0f\n", t, cnt+1, roads, railroads);
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	REP(i,1,t+1) {
		SOLVE::main(i);
	}

	return 0;
}
