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

const ll nax = 602;
const ll inf = 1e9+7;

namespace SOLVE {	
	VLL bfs(VVLL & E, VVLL & W, ll s) {
		VLL D(nax, inf);
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

	void main() {
		ll n;
		cin >> n;
		// source = 0;
		// start is 1-300
		// second is 301 - 600
		// sink = 601
		ll s = 0, t = 601;
		VVLL E(nax);
		VVLL W(nax, VLL(nax));

		VLL locked(n+1); // 1 if it is locked

		REP(i,1,n+1) {			
			ll m;
			cin >> m;

			locked[i] = m == 0 ? 1 : 0;

			REP(j,0,m) {
				ll x;
				cin >> x;
				if (x > i) addedge(E,W,i,x+300,1);
			}
		}

		// binary search
		ll L = 1, R = n+1;
		while (L < R) {
			ll M = (L + R) / 2;

			VVLL copyE = E;
			VVLL copyW = W;
			ll locks = 0;
			REP(i,1,M+1) {
				addedge(copyE,copyW,s,i,1);
				if (locked[i]) {
					addedge(copyE,copyW,i+300,t,1);
					locks++;
				}
			}

			ll mf = dinic(copyE, copyW, s, t);

			if (mf == locks) L = M + 1;
			else R = M;
		}

		ll ans = L - 1;
		cout << ans << endl;


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
