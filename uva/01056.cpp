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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename Head, typename Tail> void in(Head & H, Tail & T) { in(H); in(T); }

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
				if (d[t.v] + e.d < d[e.to]) {
					pq.push({e.to, d[t.v] + e.d});
					d[e.to] = d[t.v] + e.d;
				}
			}
		}

		return d;
	}

	ll test = 1;
	void main() {
		ll n, m;
		in(n,m);
		
		if (n == 0 && m == 0) exit(0);

		vector<vector<edge>> E(n+1);
		ll id = 1;
		map<string, ll> person;
		REP(i,0,m) {
			string a, b;
			in(a,b);
			if (person[a] == 0) {
				person[a] = id++;
			}
			if (person[b] == 0) {
				person[b] = id++;
			}
			ll pa = person[a], pb = person[b];
			E[pa].push_back({pb,1});
			E[pb].push_back({pa,1});
		}

		ll ans = 0;
		REP(i,1,n+1) {
			VLL d = dijkstra(E, i);
			REP(j,1,n+1) {
				ans = max(ans, d[j]);
			}
		}
		
		if (ans != inf) printf("Network %lld: %lld\n\n", test++, ans);
		else printf("Network %lld: DISCONNECTED\n\n", test++);


	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
