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

const ll nax = 1000;
const ll mod = 1e9 + 7;

namespace SOLVE {	
	ll dp[nax+1][nax+1][26];
	string s;

	ll get(ll L, ll R, ll c) {
		char cc = 'a' + c;

		if (L > R) return 0;
		if (L == R && s[L] == cc) return 1;
		if (L == R && s[L] != cc) return 0;
		if (dp[L][R][c] != -1) return dp[L][R][c];

		ll ans;
		
		if (s[L] != cc || s[R] != cc) {
			ans = get(L+1, R, c) + get(L, R-1, c) - get(L+1, R-1, c);			
		} else {
			// when L and R are the same and are cc, it is 2 plus what is inside
			// the prevents re-counting
			ans = 2;
			REP(i,0,26) {
				ans += get(L+1,R-1,i);
			}
		}

		ans %= mod;
		dp[L][R][c] = ans;
		return ans;

	}

	void main() {
		cin >> s;
		memset(dp, -1, sizeof dp);

		ll ans = 0;
		REP(i,0,26) ans += get(0, s.size() - 1, i);
		ans %= mod;
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
