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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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
		ll to, w;
	};

	struct todo {
		ll d, v;
		bool operator<(const todo& R) const {
			return d > R.d;
		}
	};

	void dijkstra(ll& start, ll& n, vector<vector<edge>>& E, VLL& ans) {
		priority_queue<todo> pq;
		VLL done(n+1);

		ans[start] = 0;
		pq.push({0,start});

		while (pq.size()) {
			todo at = pq.top();
			pq.pop();

			if (done[at.v]) continue;
			done[at.v] = 1;

			for (edge e : E[at.v]) {
				ll nextd = at.d + e.w;
				ll nextv = e.to;

				if (done[nextv] == 0 && nextd < ans[nextv]) {
					ans[nextv] = nextd;
					pq.push({nextd, nextv});
				}
			}
		}
	}

	void main() {
		ll n, m, A, B;
		cin >> n >> m >> A >> B;
		
		vector<vector<edge>> D(n+1); // distance adjlist
		REP(i,0,m) {
			ll a, b, d;
			cin >> a >> b >> d;

			D[a].push_back({b,d});
			D[b].push_back({a,d});
		}

		// work out all pairs shortest dist using dijkstras, for each v (n*n*logn)
		VVLL dist(n+1, VLL(n+1, inf));
		REP(i,1,n+1) {
			dijkstra(i, n, D, dist[i]);
		}

		// convert it to adjlist form
		vector<vector<edge>> C(n+1); // cost adjlist
		REP(at,1,n+1) {
			ll d, c;
			cin >> d >> c;

			REP(to,1,n+1) {
				if (dist[at][to] <= d) {
					C[at].push_back({to,c});
				}
			}
		}

		VLL cost(n+1, inf);
		dijkstra(A,n,C,cost);

		ll ans = cost[B] == inf ? -1 : cost[B];

		cout << ans << endl;
	
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
