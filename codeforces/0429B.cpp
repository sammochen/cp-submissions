#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void solve() {
	ll n, m;
	cin >> n >> m;
	VVLL A(n, VLL(m));
	REP(i,0,n) {
		REP(j,0,m) cin >> A[i][j];
	}

	// best way to get to respective corner, including itself
	VVLL topleft(n+2, VLL(m+2));
	REP(i,0,n) {
		REP(j,0,m) {
			topleft[i+1][j+1] = max(topleft[i][j+1], topleft[i+1][j]) + A[i][j];
		}
	}
	VVLL topright(n+2, VLL(m+2));
	REP(i,0,n) {
		RREP(j,m-1,0) {
			topright[i+1][j+1] = max(topright[i][j+1], topright[i+1][j+2]) + A[i][j];
		}
	}
	VVLL botleft(n+2, VLL(m+2));
	RREP(i,n-1,0) {
		REP(j,0,m) {
			botleft[i+1][j+1] = max(botleft[i+2][j+1], botleft[i+1][j]) + A[i][j];
		}
	}
	VVLL botright(n+2, VLL(m+2));
	RREP(i,n-1,0) {
		RREP(j,m-1,0) {
			botright[i+1][j+1] = max(botright[i+2][j+1], botright[i+1][j+2]) + A[i][j];
		}
	}

	ll ans = -inf;
	REP(i,1,n-1) {
		REP(j,1,m-1) {
			ll x = i+1, y = j+1;
			ll value = -inf;
			value = max(value, topright[x-1][y] + botleft[x+1][y] + topleft[x][y-1] + botright[x][y+1]);
			value = max(value, topleft[x-1][y] + botright[x+1][y] + topright[x][y+1] + botleft[x][y-1]);
			
			ans = max(ans, value);
		}
	}


	cout << ans << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}