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

const ll inf = (ll)1e18 + 5;
namespace SOLVE {
	VLL bfs(VVLL & E, ll s) {
		VLL d(E.size(), inf);
		queue<ll> Q;
		Q.push(s);
		d[s] = 0;
		while (Q.size()) {
			ll at = Q.front();
			Q.pop();

			for (ll to : E[at]) {
				if (d[to] == inf) {
					d[to] = d[at] + 1;
					Q.push(to);
				}
			}
		}
		return d;
	}
	ll test = 1;
	void main() {
		ll n,m;
		cin >> n >> m;
		VVLL E(n);
		REP(i,0,m) {
			ll a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		ll s, d;
		cin >> s >> d;
		VVLL D(n);
		REP(i,0,n) D[i] = bfs(E, i);
		ll ans = 0;
		REP(i,0,n) {
			ans = max(ans, D[s][i] + D[i][d]);
		}
		cout << "Case " << test++ << ": " << ans << endl;
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
