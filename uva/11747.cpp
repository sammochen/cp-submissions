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

namespace SOLVE {	
	VLL p(1005); 

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
	};
	bool operator<(const edge & a, const edge & b) {
		return a.w < b.w;
	}

	void main() {
		ll n, m;
		ll read = scanf("%lld%lld", &n, &m);
		if (n == 0 && m == 0) exit(0);
		REP(i,0,n+1) p[i] = i;
		
		vector<edge> E(m);
		REP(i,0,m) {
			read = scanf("%lld%lld%lld", &E[i].a, &E[i].b, &E[i].w);
		}

		sort(E.begin(), E.end());

		vector<edge> ans;
		REP(i,0,m) {
			if (same(E[i].a, E[i].b)) {
				ans.push_back(E[i]);
			} else {
				merge(E[i].a, E[i].b);
			}
		}

		if (ans.size() == 0) printf("forest\n");
		else {
			REP(i,0,ans.size()) {
				printf("%lld", ans[i].w);
				if (i == ans.size() - 1) printf("\n");
				else printf(" ");
			}
		}


	}
}


signed main() {
	while (1) {
		SOLVE::main();
	}

	return 0;
}
