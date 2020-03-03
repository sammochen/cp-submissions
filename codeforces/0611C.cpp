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

namespace SOLVE {
	void main() {
		ll n, m;
		cin >> n >> m;
		vector<string> G(n + 2); // i will plump the sides with #
		vector<VLL> v(n + 2, VLL(m + 2)); // vertical
		vector<VLL> h(n + 2, VLL(m + 2)); // horizontal
		
		G[0] = string(m + 2, '#');
		G[n + 1] = string(m + 2, '#');
		
		string s;
		REP(i,0,n) {
			cin >> s;
			G[i+1] = "#" + s + "#";
		}
		
		REP(i,1,n+1) {
			REP(j,1,m+1) {
				v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + (G[i][j] == '.' && G[i-1][j] == '.');
				h[i][j] = h[i-1][j] + h[i][j-1] - h[i-1][j-1] + (G[i][j] == '.' && G[i][j-1] == '.');
			}
		}
		
		ll q, a, b, c, d;
		cin >> q;
		REP(i,0,q) {
			cin >> a >> b >> c >> d;
			
			ll ans = 0;
			ans += v[c][d] - v[a][d] - v[c][b-1] + v[a][b-1];
			ans += h[c][d] - h[c][b] - h[a-1][d] + h[a-1][b];
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
