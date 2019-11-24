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
		ll n, m;

		while (cin >> n >> m) {
			// bfs
			VLL d(26, inf);
			VLL next(26, 0);
			queue<ll> q;
			
			string s;
			cin >> s;
			for (char c : s) {
				d[c - 'A'] = 0;
				q.push(c - 'A');
			}

			VVLL E(26);
			REP(i,0,m) {
				cin >> s;
				E[s[0] - 'A'].push_back(s[1] - 'A');
				E[s[1] - 'A'].push_back(s[0] - 'A');
			}

			while (q.size()) {
				ll a = q.front();
				q.pop();

				for (ll b : E[a]) {
					if (d[b] == inf) {
						next[b]++;
						if (next[b] == 3) {
							d[b] = d[a] + 1;
							q.push(b);
						}
					}
				}
			}

			ll ans = 0;
			ll cnt = 0;
			REP(i,0,26) {
				ans = d[i] != inf ? max(ans, d[i]) : ans;
				cnt += d[i] != inf ? 1 : 0;
			}

			if (cnt == n) {
				cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
			} else {
				cout << "THIS BRAIN NEVER WAKES UP" << endl;
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
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
