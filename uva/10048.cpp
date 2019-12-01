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

const ll inf = 1e9+7;

namespace SOLVE {	
	struct edge {
		ll to, d;
	};

	struct todo {
		ll v, d;
	};

	bool operator<(const todo & a, const todo & b) {
		return a.d > b.d;
	};

	VLL dijkstra(vector<vector<edge>> & E, ll s) {
		VLL d(E.size(), inf);
		d[s] = 0;
		priority_queue<todo> pq;

		pq.push({s, 0});
		while (pq.size()) {
			todo t = pq.top();
			pq.pop();

			for (edge e : E[t.v]) {
				ll nextd = max(d[t.v], e.d);
				if (nextd < d[e.to]) {
					pq.push({e.to, nextd});
					d[e.to] = nextd;
				}
			}
		}

		return d;
	}

	ll test = 1;
	void main() {
		ll n, m, q;
		ll read = scanf("%lld%lld%lld", &n, &m, &q);
		if (n == 0 && m == 0 && q == 0) exit(0);

		vector<vector<edge>> E(n+1);
		REP(i,0,m) {
			ll a, b, w;
			read = scanf("%lld%lld%lld", &a, &b, &w);
			E[a].push_back({b, w});
			E[b].push_back({a, w});
		}

		VVLL asp(n+1); // all shortest paths
		REP(i,1,n+1) asp[i] = dijkstra(E, i);

		if (test != 1) printf("\n");
		printf("Case #%lld\n", test++);
		REP(i,0,q) {
			ll a, b;
			read = scanf("%lld%lld", &a, &b);
			if (asp[a][b] == inf) printf("no path\n");
			else printf("%lld\n", asp[a][b]);
		}

	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
