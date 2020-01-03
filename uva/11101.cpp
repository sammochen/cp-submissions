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
	void main() {
		ll n, m;
		while (in(n), n) {
			queue<PLL> Q;
			VVLL d(2001, VLL(2001, inf));

			vector<PLL> s(n);
			REP(i,0,n) {
				ll a, b;
				in(a, b);
				s[i].first = a;
				s[i].second = b;
				d[a][b] = 0;
				Q.push({a, b});
			}

			in(m);
			VVLL t(2001, VLL(2001));
			REP(i,0,m) {
				ll a, b;
				in(a, b);
				t[a][b] = 1;
			}

			while (Q.size()) {
				PLL at = Q.front(); Q.pop();
				if (t[at.first][at.second]) {
					//debug(at.first, at.second, d[at.first][at.second]);
					printf("%lld\n", d[at.first][at.second]);
					break;
				}

				//debug(at);
				VLL di = {0,0,1,-1};
				VLL dj = {1,-1,0,0};
				REP(x,0,4) {
					ll ii = at.first + di[x];
					ll jj = at.second + dj[x];
					if (ii < 0 || ii > 2000 || jj < 0 || jj > 2000) continue;
					if (d[ii][jj] != inf) continue;
					d[ii][jj] = d[at.first][at.second] + 1;
					Q.push({ii, jj});
				}
			}


			
			
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
