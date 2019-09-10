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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

const ll nax = 101;

namespace SOLVE {
	ll n, m;
	vector<vector<VLL>> E(nax, vector<VLL>(nax)); // E[color][i] gives the neighbours to i
	vector<VLL> parent(nax, VLL(nax, -1)); // parent[color][i] is the parent
	VLL visited;
	
	void dfs(ll v, ll p, ll color) {
		parent[color][v] = p;
		visited[v] = 1;
		
		for (ll next : E[color][v]) {
			if (!visited[next]) {
				dfs(next,p,color);
			}
		}
	}
	
	void main() {
		cin >> n >> m;
		
		ll a, b, c;
		REP(i,0,m) {
			cin >> a >> b >> c;
			E[c][a].push_back(b);
			E[c][b].push_back(a);
		}
		
		REP(color,1,m+1) {
			visited.clear();
			visited.resize(n + 1);
			REP(p,1,n+1) {
				if (!visited[p]) {
					dfs(p, p, color);
				}
			}
		}
		
		ll q;
		cin >> q;
		
		REP(i,0,q) {
			cin >> a >> b;
			ll ans = 0;
			REP(color,1,m+1) {
				ans += (parent[color][a] == parent[color][b] && parent[color][a] != -1); // same parent, both have parents
			}
			cout << ans << endl;
		}
		
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
