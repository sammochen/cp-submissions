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
	void main() {
		while (1) {
			ll n, m;
			cin >> n >> m;
			if (n == 0 && m == 0) break;
			VVLL A(n, VLL(m));

			ll k;
			cin >> k;
			REP(i,0,k) {
				ll r, amount;
				cin >> r >> amount;
				REP(j,0,amount) {
					ll x;
					cin >> x;
					A[r][x] = 1;
				}
			}

			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			VVLL D(n, VLL(m, inf));
			queue<PLL> q;
			q.push({a,b});
			D[a][b] = 0;
			while (q.size()) {
				PLL at = q.front();
				q.pop();

				VLL dx = {0,0,1,-1};
				VLL dy = {1,-1,0,0};
				REP(x,0,4) {
					ll ii = at.first + dx[x];
					ll jj = at.second + dy[x];

					if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
					if (A[ii][jj] == 1) continue;
					if (D[ii][jj] == inf) {
						D[ii][jj] = D[at.first][at.second] + 1;
						q.push({ii,jj});
					}
				}
			}

			cout << D[c][d] << endl;
		}
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
