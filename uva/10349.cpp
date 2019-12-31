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

const ll inf = 1e9+7;

namespace SOLVE {	
	VLL bfs(VVLL & E, VVLL & W, ll s) {
		VLL D(E.size(), inf);
		queue<ll> Q;
		D[s] = 0;
		Q.push(s);
		while (Q.size()) {
			ll at = Q.front();
			Q.pop();
			for (ll to : E[at]) {
				if (W[at][to] <= 0) continue;
				if (D[to] != inf) continue;
				D[to] = D[at] + 1;
				Q.push(to); 
			}
		}
		return D;
	}

	// returns the maxflow possible from at to t
	ll dfs(VVLL & E, VVLL & W, VLL & D, ll at, ll t, ll f) {
		if (at == t) {
			return f;
		}

		for (ll to : E[at]) {
			if (W[at][to] > 0 && D[to] == D[at] + 1) {
				ll flow = dfs(E, W, D, to, t, min(f, W[at][to]));
				if (flow > 0) {
					W[at][to] -= flow;
					W[to][at] += flow;
					return flow;
				}
			}
		}
		return 0;
	}

	// returns the max flow
	ll dinic(VVLL E, VVLL W, ll s, ll t) {
		ll mf = 0;
		while (1) {
			// do bfs
			VLL D = bfs(E, W, s);
			if (D[t] == inf) return mf;

			// do dfs 
			while (1) {
				ll f = dfs(E,W,D,s,t,inf);
				mf += f;
				if (f == 0) break;
			}
		}
		return mf;
	}

	void addedge(VVLL & E, VVLL & W, ll a, ll b, ll w) {
		E[a].push_back(b);
		E[b].push_back(a);
		W[a][b] = w;
	}

	ll n, m;
	ll id(ll i, ll j) {
		return (i * m + j);
	}

	void main() {
		
		cin >> n >> m;
		vector<string> A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		VVLL E(n*m*2 + 2);
		VVLL W(n*m*2 + 2, VLL(n*m*2 + 2));
		ll s = n*m*2, t = n*m*2 + 1;

		// for every vertex, if there is a vertex right or bottom, add an edge
		ll total = 0;
		REP(i,0,n) {
			REP(j,0,m) {
				if (A[i][j] == '*') {
					total++;
					if ((i+j) % 2) {
						addedge(E, W, s, id(i, j), 1);
						if (i != n-1 && A[i+1][j] == '*') addedge(E, W, id(i, j), id(i+1, j), 1);
						if (j != m-1 && A[i][j+1] == '*') addedge(E, W, id(i, j), id(i, j+1), 1);
						if (i != 0 && A[i-1][j] == '*') addedge(E, W, id(i, j), id(i-1, j), 1);
						if (j != 0 && A[i][j-1] == '*') addedge(E, W, id(i, j), id(i, j-1), 1);
					} else {
						addedge(E, W, id(i, j), t, 1);
					}					
				}
			}
		}

		ll mf = dinic(E, W, s, t);
		ll ans = total - mf;
		cout << ans << endl;
		

	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}