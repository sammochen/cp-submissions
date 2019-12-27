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
const ll mod = 20437;

namespace SOLVE {	
	ll n;
	VLL di = {0,0,1,-1};
	VLL dj = {1,-1,0,0};

	// returns {dist, count} from letter to next letter
	PLL bfs(ll letter, PLL s, PLL t, vector<string> & A) {
		VVLL c(n, VLL(n, 0));
		VVLL d(n, VLL(n, inf));
		queue<PLL> Q;

		c[s.first][s.second] = 1;
		d[s.first][s.second] = 0;
		Q.push(s);

		while (Q.size()) {
			PLL at = Q.front();
			Q.pop();

			REP(x,0,4) {
				ll i = at.first;
				ll j = at.second;
				ll ii = i + di[x];
				ll jj = j + dj[x];
				if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
				if (A[ii][jj] == '#') continue;
				if (A[ii][jj] >= 'A' && A[ii][jj] <= 'Z') {
					if (A[ii][jj] - 'A' > letter + 1) continue;
				}

				if (d[ii][jj] == inf) {
					d[ii][jj] = d[i][j] + 1;
					c[ii][jj] = c[i][j];
					Q.push({ii, jj});
				} else if (d[ii][jj] == d[i][j] + 1) {
					c[ii][jj] += c[i][j];
					c[ii][jj] %= mod;
				}
			}	
					
		}

		return {d[t.first][t.second], c[t.first][t.second]};
	}

	ll test = 1;
	void main() {
		while (in(n), n) {
			vector<string> A(n);
			REP(i,0,n) in(A[i]);
			
			// shortest paths - do it until all letters are done
			// do a bfs on every letter

			vector<PLL> pos(26, {-1,-1}); // stores all initial positions
			REP(i,0,n) {
				REP(j,0,n) {
					if (A[i][j] >= 'A' && A[i][j] <= 'Z') {
						pos[A[i][j] - 'A'] = {i, j};
					}
				}
			}

			ll d = 0, cnt = 1;
			ll good = 1;
			REP(i,0,25) {
				if (pos[i+1].first == -1) break;
				PLL res = bfs(i, pos[i], pos[i+1], A);
				if (res.first == inf) good = 0;

				d += res.first;
				cnt *= res.second;
				cnt %= mod;	
			}

			if (good) printf("Case %lld: %lld %lld\n", test++, d, cnt);
			else printf("Case %lld: Impossible\n", test++);

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
