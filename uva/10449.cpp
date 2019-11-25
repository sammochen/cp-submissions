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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	struct edge {
		ll a, b, d;
	};

	VLL bellmanfords(vector<edge> & E, ll n, ll s) {
		VLL d(n, inf);
		d[s] = 0;

		REP(i,0,n) {
			for (edge e : E) {
				if (d[e.a] != inf) d[e.b] = min(d[e.b], d[e.a] + e.d);
			}
		}

		VLL copy = d;
		REP(i,0,n) {
			for (edge e : E) {
				if (d[e.a] != inf) copy[e.b] = min(copy[e.b], copy[e.a] + e.d);
			}
		}

		REP(i,0,n) {
			if (copy[i] != d[i]) d[i] = -1;
		}

		return d;
	}

	ll cube(ll x) {
		return x*x*x;
	}

	void main() {
		ll n, m;
		ll test = 1;
		while (cin >> n) {
			cout << "Set #" << test++ << endl;
			VLL busy(n+1);
			REP(i,1,n+1) cin >> busy[i];

			vector<edge> E;

			cin >> m;
			REP(i,0,m) {
				ll a, b;
				cin >> a >> b;
				E.push_back({a,b,cube(busy[b] - busy[a])});
			}

			VLL D = bellmanfords(E, n+1, 1);

			ll q;
			cin >> q;
			REP(i,0,q) {
				ll x;
				cin >> x;
				
				if (D.size() == 0 || D[x] < 3 || D[x] == inf) cout << "?" << endl;
				else cout << D[x] << endl;
			}
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
