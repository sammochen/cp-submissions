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
		vector<string> grid(n);
		REP(i,0,n) cin >> grid[i];

		// Implement a O(m*n) solution

		VVLL row(n, VLL(26));
		VVLL col(m, VLL(26));

		REP(i,0,n) {
			REP(j,0,m) {
				// for every item, add the letter count
				row[i][grid[i][j] - 'a']++;
				col[j][grid[i][j] - 'a']++;
			}
		}

		string ans;
		REP(i,0,n) {
			REP(j,0,m) {
				if (row[i][grid[i][j] - 'a'] == 1 && col[j][grid[i][j] - 'a'] == 1) ans.push_back(grid[i][j]);
			}
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
