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
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
typedef vector<VVLL> VVVLL;

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {
	ll n, m;	
	ll id(ll r, ll c, ll d) {
		return (r * m + c) * 4 + d;
	}
	void main() {
		while (cin >> n >> m) {
			VVVLL A(n, VVLL(m, VLL(4)));
			REP(i,0,n) {
				REP(j,0,m) {
					if (i == n-1 && j == m-1) break;

					string s;
					cin >> s;
					for (char c : s) {
						if (c == 'N') A[i][j][0] = 1;
						if (c == 'E') A[i][j][1] = 1;
						if (c == 'S') A[i][j][2] = 1;
						if (c == 'W') A[i][j][3] = 1;
					}

				}
			}

			VLL dist(n*m*4, inf);
			ll s = id(0,0,0);
			queue<ll> Q;
			Q.push(s);
			dist[s] = 0;
			while (Q.size()) {
				ll at = Q.front();
				Q.pop();
				ll i = at / 4 / m;
				ll j = at / 4 % m;
				ll d = at % 4;

				VLL di = {-1,0,1,0};
				VLL dj = {0,1,0,-1};
				REP(x,0,4) {
					if (A[i][j][x] == 0) continue;

					ll ii = i + di[(x+d)%4];
					ll jj = j + dj[(x+d)%4];
					ll dd = (d + 1) % 4;

					if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
					if (dist[id(ii,jj,dd)] != inf) continue;

					dist[id(ii,jj,dd)] = dist[id(i,j,d)] + 1;
					Q.push(id(ii,jj,dd));
				}
			}
			ll ans = inf;
			REP(x,0,4) {
				ans = min(ans, dist[id(n-1, m-1, x)]);
			}
			if (ans == inf) cout << "no path to exit\n";
			else cout << ans << endl;
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
