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
		VLL d(n, -inf);
		d[s] = 100;

		// first run through
		REP(i,0,n-1) {
			for (edge e : E) {
				if (d[e.a] != -inf && d[e.a] + e.d >= 0) d[e.b] = max(d[e.b], d[e.a] + e.d);
			}
		}

		// second run through - spot infinite loops 
		VLL copy = d;
		REP(i,0,n-1) {
			for (edge e : E) {
			 	if (copy[e.a] != -inf && d[e.a] + e.d >= 0) copy[e.b] = max(copy[e.b], copy[e.a] + e.d);
			}
		}

		// re-do d, this time with places of positive infinite loops, set to infinity
		REP(i,0,n) {
			if (copy[i] > d[i]) d[i] = inf;
		}

		REP(i,0,n-1) {
			for (edge e : E) {
				if (d[e.a] == -inf) ll aaa;
				else if (d[e.a] == inf) d[e.b] = inf; 
				else if (d[e.a] != inf && d[e.a] + e.d >= 0) d[e.b] = max(d[e.b], d[e.a] + e.d);
			}
		}

		return d;
	}

	void main() {
		while (1) {
			ll n;
			cin >> n;
			if (n == -1) return;
			VVLL al(n);
			VLL points(n);

			REP(i,0,n) {
				cin >> points[i];
				ll x;
				cin >> x;
				REP(j,0,x) {
					ll y;
					cin >> y;
					al[i].push_back(y-1);
				}
			}

			vector<edge> E;
			REP(i,0,n) {
				REP(j,0,al[i].size()) {
					E.push_back({i, al[i][j], points[al[i][j]]});
				}
			}

			VLL ans = bellmanfords(E, n, 0);

			if (ans[n-1] > 0) cout << "winnable" << endl;
			else cout << "hopeless" << endl;

		}
	
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
