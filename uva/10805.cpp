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

const ll inf = 1e9+7;

namespace SOLVE {	
	VLL bfs(VVLL & E, ll s) {
		VLL d(E.size(), inf);
		queue<ll> Q;
		Q.push(s);
		d[s] = 0;
		while (Q.size()) {
			ll at = Q.front();
			Q.pop();

			for (ll to : E[at]) {
				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
				}
			}
		}
		return d;
	}

	ll test = 1;
	void main() {
		ll n, m;
		in(n,m);
		VVLL E(n+m);

		ll edge = n;

		REP(i,0,m) {
			ll a, b;
			in(a,b);
			E[a].push_back(edge);
			E[edge].push_back(a);

			E[edge].push_back(b);
			E[b].push_back(edge);
			edge++;
		}

		ll ans = inf;
		REP(i,0,n+m) {
			VLL d = bfs(E, i);
			sort(d.rend() - n, d.rend());
			ans = min(ans, d[0] + d[1]);
		}

		printf("Case #%lld:\n", test++);
		printf("%lld\n\n", ans/2);

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
