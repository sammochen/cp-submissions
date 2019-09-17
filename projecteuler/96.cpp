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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
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

namespace SOLVE {	
	// check if grid[x][y] was a valid place
	ll valid(VVLL grid, ll x, ll y, ll value) { 
		REP(i,0,9) {
			if (grid[i][y] == value) return 0;
			if (grid[x][i] == value) return 0;
			if (grid[x/3 * 3 + i % 3][y/3 * 3 + i / 3] == value) return 0;
		}
		return 1;
	}
	
	// fill in grid[i][j]
	ll solve(VVLL grid, ll ind) {
		if (ind == 81) return grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2]; // ans for a completed square
		ll i = ind / 9;
		ll j = ind % 9;
		
		if (grid[i][j] == 0) {
			REP(k,1,10) {	
				if (valid(grid, i, j, k)) {
					VVLL next = grid;
					next[i][j] = k;
					
					ll ans = solve(next, ind+1);
					if (ans != 0) return ans;
				}
			}
		} else {
			ll ans = solve(grid, ind+1);
			if (ans != 0) return ans;
		}
		return 0;
	}
	
	void main() {
		ll n = 50;
		VVLL grid(9, VLL(9));
		
		string a;
		ll ans = 0;
		REP(t,0,n) {
			debug(t);
			cin >> a >> a;
			REP(i,0,9) {
				cin >> a;
				REP(j,0,9) {
					grid[i][j] = (a[j] - '0');
				}
			}
			ans += solve(grid, 0);
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
