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
	ll ok = 0;
	void dfs(ll s, ll t, ll n, ll mask, vector<PLL> & A) {
		if (s == t && n == 0) {
			ok = 1;
			return;
		}

		REP(i,0,A.size()) {
			PLL dom = A[i];
			if (dom.first == s && ((1LL << i) & mask) == 0) {
				dfs(dom.second, t, n-1, mask | (1LL << i), A);
				if (ok) return;
			}
			if (dom.second != dom.first && dom.second == s && ((1LL << i) & mask) == 0) {
				dfs(dom.first, t, n-1, mask | (1LL << i), A);
				if (ok) return;
			}
		}
	}

	void main() {
		ll n, m;
		while (in(n), n) {
			in(m);
			PLL a, b;
			in(a.first, a.second);
			in(b.first, b.second);
			vector<PLL> A(m);
			REP(i,0,m) {
				in(A[i].first, A[i].second);
			}

			ok = 0 ;
			dfs(a.second, b.first, n, 0, A);
			if (ok) printf("YES\n");
			else printf("NO\n");
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
