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

const ll inf = 1e9+7;

namespace SOLVE {	
	struct todo {
		ll i, j, d;
	};

	struct comparetodo {
		bool operator()(todo & a, todo & b) {
			return a.d > b.d;
		}
	};

	void main() {
		ll n = 80;
		char c;

		VVLL grid(n, VLL(n));

		REP(i,0,n) {
			REP(j,0,n-1) {
				cin >> grid[i][j] >> c;
			}
			cin >> grid[i][n-1];
		}

		// dijkstras algorithm!
		priority_queue<todo, vector<todo>, comparetodo> pq;
		VVLL best(n, VLL(n, inf));

		pq.push({0,0,grid[0][0]});

		while(pq.size()) {
			todo t = pq.top();
			pq.pop();
			
			if (t.d >= best[t.i][t.j]) {
				continue;
			}

			best[t.i][t.j] = t.d;

			VLL di = {0,0,1,-1};
			VLL dj = {1,-1,0,0};

			REP(x,0,4) {
				ll i = t.i + di[x];
				ll j = t.j + dj[x];

				if (i < 0 || i >= n || j < 0 || j >= n) continue;

				pq.push({i,j,t.d + grid[i][j]});
			}
		}

		ll ans = best[n-1][n-1];
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
