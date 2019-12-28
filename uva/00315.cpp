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
	ll time;
	
	void dfs(ll at, ll prev, VVLL & E, VLL & first, VLL & low, VLL & ap) {
		first[at] = time;
		low[at] = time;
		time++;
		ll kids = 0;
		for (ll to : E[at]) {
			if (to == prev) continue;
			
			if (first[to] == -1) {
				kids++;
				dfs(to, at, E, first, low, ap);
				low[at] = min(low[at], low[to]);
				if (at != 0 && low[to] >= first[at]) {
					ap[at] = 1;
				}
			} else {
				low[at] = min(low[at], first[to]);
			}
		}


		if (at == 0 && kids >= 2) {
			ap[at] = 1;
		}
	}	

	void main() {
		string s;
		while (getline(cin, s), s != "0") {
			ll n = stoll(s);
			VVLL E(n);
			map<PLL,ll> done;

			while (getline(cin, s), s != "0") {
				stringstream ss;
				ss << s;
				ll v, u;
				ss >> v;
				while (ss >> u) {
					if (!done[{u, v}]) {
						E[u-1].push_back(v-1);
						E[v-1].push_back(u-1);
						done[{u, v}] = 1;
						done[{v, u}] = 1;
					}
				}
			}

			VLL first(n, -1);
			VLL low(n, -1);
			VLL ap(n, 0);
			time = 0;

			dfs(0,0,E,first,low,ap);

			ll ans = 0;
			REP(i,0,n) ans += ap[i];

			printf("%lld\n", ans);
		}
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
