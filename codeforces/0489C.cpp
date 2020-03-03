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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	const ll A = 2, B = 101, C = 901;
	string dp[A][B][C]; // dp[big][digits][sum], "--" is not explored, "-1" is invalid
	
	string get(ll big, ll m, ll s, ll first) {
		if (m == 0 && s == 0) {
			return "";
		}
		if (m < 0 || s < 0) {
			return "-1";
		}
		if (dp[big][m][s] != "--") {
			return dp[big][m][s];
		}
		
		// if first, cannot do 0
		ll n = first ? 9 : 10;
		VLL order(n);
		
		REP(i,0,n) {
			order[i] = big ? n - i - !first: i + first;
		}
				
		for (ll i : order) {
			string next = get(big, m-1, s-i, 0);
			if (next != "-1") {
				dp[big][m][s] = to_string(i) + next;
				return dp[big][m][s];
			}
		}
		
		dp[big][m][s] = "-1";
		return dp[big][m][s];
	}
				
	void main() {
		ll m, s;
		cin >> m >> s;
		
		
		REP(i,0,A) {
			REP(j,0,B) {
				REP(k,0,C) {
					dp[i][j][k] = "--"; // not explored
				}
			}
		}
		if (m == 1 && s == 0) {
			cout << "0 0" << endl;
		} else if (s == 0) {
			cout << "-1 -1" << endl;
		} else {	
			cout << get(0,m,s,1) << ' ' << get(1,m,s,1) << endl;
		}
		
		
		
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
