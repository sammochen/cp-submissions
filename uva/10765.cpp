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
	
	void dfs(ll at, ll prev, VVLL & E, VLL & first, VLL & low, VLL & kids) {
		first[at] = time;
		low[at] = time;
		kids[at] = at == 0 ? 0 : 1;
		time++;
		for (ll to : E[at]) {
			if (to == prev) continue;
			
			if (first[to] == -1) {
				dfs(to, at, E, first, low, kids);
				low[at] = min(low[at], low[to]);
				if (low[to] >= first[at]) kids[at]++;
				
			} else {
				low[at] = min(low[at], first[to]);
			}
		}

	}	

	struct aaa {
		ll n, f;
		bool operator<(const aaa & a) {
			if (a.f == f) return a.n > n;
			return a.f < f;
		}
	};

	
	void main() {
		ll n, m;
		while (in(n, m), n || m) {
			VVLL E(n);
			ll a, b;
			while (in(a, b), a != -1) {
				E[a].push_back(b);
				E[b].push_back(a);
			}

			VLL first(n, -1);
			VLL low(n, -1);
			VLL kids(n, 0);

			dfs(0, -1, E, first, low, kids);


			vector<aaa> ans(n);
			// number of distinct lowlinks for each edge
			REP(i,0,n) ans[i] = {i, kids[i]};
			
			sort(ans.begin(), ans.end());

			REP(i,0,m) {
				printf("%lld %lld\n", ans[i].n, ans[i].f);
			}
			printf("\n");
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
