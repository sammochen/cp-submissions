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

namespace SOLVE {	
	struct edge {
		ll v, id;
	};


	void dfs(ll at, ll & max, vector<vector<edge>> &edges, VLL &visited, VLL &color) {
		visited[at] = 1; // started
		for (edge to : edges[at]) {
			if (visited[to.v] == 0) {
				dfs(to.v, max, edges, visited, color);
				color[to.id] = 1;
			} else if (visited[to.v] == 1) { // still going - cycle
				color[to.id] = 2;
				max = 2;
			} else {
				color[to.id] = 1;
			}
		}
		visited[at] = 2; // ended
	}
	
	void main() {
		ll n, m;
		cin >> n >> m;
		vector<vector<edge>> edges(n);
		VLL visited(n);
		VLL color(m);

		REP(i,0,m) {
			ll a, b;
			cin >> a >> b;
			edges[a-1].push_back({b-1,i});
		}

		ll max = 1;
		
		REP(i,0,n) {
			if (visited[i] == 0) dfs(i, max, edges, visited, color);
		}

		cout << max << endl;
		REP(i,0,m) {
			cout << color[i] << ' ';
		}
		cout << endl;

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
