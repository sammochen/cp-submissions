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

	// how the state is indexed
	ll f(ll a, ll b) {
		return 2*a+b;
	}

	db dist(PLL a, PLL b) {
		db di = a.first - b.first;
		db dj = a.second - b.second;
		return sqrt(di*di + dj*dj);
	}

	void main() {
		ll n, k = 0; // k is no of penguins
		db d;
		cin >> n >> d;

		VVLL E(300);
		VVLL W(300, VLL(300));
		ll s = 200; // source
		// might need to do another thing of itself to itself

		vector<PLL> A(n); // coordinates
		REP(i,0,n) {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			A[i].first = a;
			A[i].second = b;
			addedge(E, W, s, f(i,0), c);
			addedge(E, W, f(i,0), f(i,1), d);

			k += c;
		}

		REP(i,0,n) {
			REP(j,i+1,n) {
				if (dist(A[i], A[j]) <= d) {
					addedge(E, W, f(i,1), f(j,0), inf);
					addedge(E, W, f(j,1), f(i,0), inf);
				}
			}
		}

		VLL ans;
		REP(i,0,n) {
			ll mf = dinic(E, W, s, f(i,0));
			if (mf == k) ans.push_back(i);
		}

		if (ans.size() == 0) cout << -1 << endl;
		else {
			REP(i,0,ans.size()) {
				cout << ans[i];
				if (i == ans.size() - 1) cout << endl;
				else cout << ' ';
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
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}