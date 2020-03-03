/*
Original problem: https://codeforces.com/problemset/problem/1205/B
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

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll inf = 1e9+7;

namespace SOLVE {
    void main() {
        ll n, x;
		cin >> n;
	
		VI freq(64); // keep track of freq of bit - more than 3 means a 3-loop exists
		VLL V; // vector of vertices - max 64^2

		REP(i,0,n) {
			cin >> x;
			int good = 0;
			REP(j,0,64) {
				if ((1LL << j) & x) {
					freq[j]++;
					if (freq[j] == 3) {
						cout << 3 << endl;
						return;
					}
					good = 1;
				}
			}
			if (good) {
				V.push_back(x);
			}
		}

		ll ans = inf;

		// for every v in V, find shortest loop to itself
		for (ll v : V) {
			// bfs(v) to find smallest loop
			queue<PLL> q;
			map<ll,int> visited;
			map<ll,int> dist;
			map<ll,ll> parent; // ensure it doesnt go back on itself

			q.push(MP(v, 0));
			visited[v] = 1;
			dist[v] = 0;
			parent[v] = -1;

			while (q.size()) {
				ll a = q.front().first;
				ll d = q.front().second;
				q.pop();

				for (ll b : V) { // for every other vertex
					// if b has been visited and is not itself or the direct parent - there is a loop!
					if (a != b && visited[b] == 1 && (a & b) && parent[a] != b) {
						ans = min(ans, dist[b] + d + 1);
					}
					// if there is a connection and it hasnt been seen yet
					if (!visited[b] && (a & b)) {
						q.push(MP(b, d + 1));
						visited[b] = 1;
						dist[b] = d + 1;
						parent[b] = a;
					}
				}
			}
		}

		ans = ans == inf ? -1 : ans;
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