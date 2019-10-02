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
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(vector<vector<A>> v) {
	string s = "";
	for (vector<A> vv : v) s += to_string(vv) + "\n";
	return s;
}


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
	void main() {
		ll n, m;
		cin >> n >> m;
		VVLL grid(n+1, VLL(m+1, 1)); // 0 is good, 1 is block
		REP(i,1,n+1) {
			string s;
			cin >> s;
			REP(j,1,m+1) {
				grid[i][j] = s[j-1] == '.' ? 0 : 1;
			}
		}


		// find all cells reachable by 1,1
		VVLL start(n+1, VLL(m+1));
		REP(i,1,n+1) {
			REP(j,1,m+1) {
				if (i==1 && j==1) {
					start[i][j] = 1;
				} else if (grid[i][j] == 1) {
					start[i][j] = 0;
				} else {
					start[i][j] = start[i-1][j] || start[i][j-1];
				}
			}
		}

		// find all cells that can reach n,m
		VVLL end(n+2, VLL(m+2));
		RREP(i,n,1) {
			RREP(j,m,1) {
				if (i==n && j==m) {
					end[i][j] = 1;
				} else if (grid[i][j] == 1) {
					end[i][j] = 0;
				} else {
					end[i][j] = end[i+1][j] || end[i][j+1];
				}
			}
		}

		// search up diagonals - if there is a diagonal with only one point, that is critical
		REP(d,1,n+m-2) { // from 1 to n+m-3 (not including the start and end)
			ll count = 0;

			REP(i,1,n+1) {
				ll j = d + 2 - i;
				if (1 <= i && i <= n && 1 <= j && j <= m) {
					if (start[i][j] && end[i][j]) {
						count++;
					}
				}
			}

			// critical point
			if (count == 1) {
				cout << 1 << endl;
				return;
			}

			// no path
			if (count == 0) {
				cout << 0 << endl;
				return;
			}
		}

		// can be blocked at start/end
		cout << 2 << endl;
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
