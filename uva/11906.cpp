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

namespace SOLVE {	
	ll n, m, a, b;
	ll even, odd;

	void dfs(ll i, ll j, VVLL & A, VVLL & visited) {
		if (visited[i][j]) return;
		visited[i][j] = 1;

		VLL di = {a, -a, a, -a, b, -b, b, -b};
		VLL dj = {b, b, -b, -b, a, a, -a, -a};
		map<PLL, ll> done;
		
		ll count = 0;
		REP(x,0,8) {
			ll ii = i + di[x];
			ll jj = j + dj[x];
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
			if (A[ii][jj] == 1) continue;
			dfs(ii, jj, A, visited);

			if (!done[{ii,jj}]) count++;
			done[{ii,jj}] = 1;
		}

		if (count % 2) odd++;
		else even++;
	}

	ll test = 1;
	void main() {
		cin >> n >> m >> a >> b;
		VVLL A(n, VLL(m));
		VVLL visited(n, VLL(m));
		
		ll w;
		cin >> w;
		REP(i,0,w) {
			ll x, y;
			cin >> x >> y;
			A[x][y] = 1;
		}
	
		even = 0;
		odd = 0;
		dfs(0,0,A,visited);
		printf("Case %lld: %lld %lld\n", test++, even, odd);
	}
}


signed main() {
	ll t;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
