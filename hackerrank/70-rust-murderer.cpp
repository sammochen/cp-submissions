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
	ll n, m;	
	map<ll,ll> M;

	ll hash(ll a, ll b) {
		return min(a,b) * 3e5 + max(a,b);
	}

	ll isedge(ll a, ll b) {
		return M[hash(a,b)];
	}

	void putedge(ll a, ll b) {
		M[hash(a,b)] = 1;
	}

	VLL bfs(ll s) {
		VLL d(n, inf);
		set<ll> notfound;
		REP(i,0,n) notfound.insert(i);

		queue<ll> Q;
		Q.push(s);
		d[s] = 0;
		while (Q.size()) {
			ll at = Q.front();
			Q.pop();

			set<ll> del;

			for (ll to : notfound) {
				if (isedge(at, to)) continue;
				if (at == to) continue;

				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
					del.insert(to);
				}
			}

			for (ll v : del) {
				notfound.erase(v);
			}
		}
		return d;
	}


	void main() {
		M.clear();
		cin >> n >> m;

		REP(i,0,m) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			putedge(a,b);
		}
		
		ll s;
		cin >> s;
		s--;

		VLL ans = bfs(s);

		REP(i,0,n) {
			if (i != s) cout << ans[i] << ' ';;
		}
		cout << endl;


		
	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
