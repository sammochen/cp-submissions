/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_g
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


namespace SOLVE {
    void main() {
        int v, e, a, b;
        cin >> v >> e;
        vector < VI > edges(v + 1);
        VI vin(v + 1);
        queue < int > topo; // find topological order
        
        VI dp(v + 1); // dp[i] stores the max length that ends at i

        REP(i, 0, e) {
            cin >> a >> b;
            edges[a].push_back(b);
            vin[b]++;
        }

        // look for all vertices that have no vout
        REP(i, 1, v + 1) {
            if (vin[i] == 0) {
                topo.push(i);
                dp[i] = 0;
            }
        }

        // finding topological order whilst creating the reversing topological order
        while (topo.size()) {
            int t = topo.front();
            topo.pop();

            // remove the top and remove all vertices outgoing from top
            for (int to: edges[t]) {
                dp[to] = max(dp[to], dp[t] + 1);

                vin[to]--;
                if (vin[to] == 0) {
                    topo.push(to); // to now has no incoming edges and is next in topo order
                }
            }
        }

        int ans = 0;
        REP(i, 1, v + 1) {
            ans = max(ans, dp[i]);
        }
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