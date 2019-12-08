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

namespace SOLVE {	
	ll bfs(ll s, VVLL & E, VLL & color) {
		queue<ll> Q;
		Q.push(s);
		color[s] = 1;
		VLL cnt(3);

		while (Q.size()) {
			ll at = Q.front();
			Q.pop();
			cnt[color[at]]++;

			for (ll to : E[at]) {
				if (color[to] != 0) {
					if (color[to] == color[at]) return -1;
				} else {
					color[to] = color[at] == 1 ? 2 : 1;
					Q.push(to);
				}
			}
		}
		return cnt[1] + cnt[2] == 1 ? 1 : min(cnt[1], cnt[2]);
	}

	ll test = 1;
	void main() {
		ll n, m;
		in(n, m);

		VVLL E(n);
		REP(i,0,m) {
			ll a, b;
			in(a,b);
			E[a].push_back(b);
			E[b].push_back(a);
		}

		VLL color(n);
		ll ans = 0;
		REP(i,0,n) {
			if (color[i] == 0) {
				ll b = bfs(i, E, color);
				if (b == -1) {
					cout << -1 << endl;
					return;
				} else {
					ans += b;
				}
			}
		}
		cout << ans << endl;
	}
}


signed main() {
	ll t;
	in(t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
