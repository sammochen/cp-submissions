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

const ll nax = 200;
namespace SOLVE {	
	vector<vector<VLL>> dp(nax+1, vector<VLL>(nax+1, VLL(nax+1, -1)));
	
	ll get(ll a, ll b, ll c) { // 3-digit binary 
		if (a == 0 && b == 0) return 1;
		if (b == 0 && c == 0) return 4;
		if (c == 0 && a == 0) return 2;
		
		if (dp[a][b][c] != -1) return dp[a][b][c];
		
		ll ans = 0;
		
		if (a >= 2) ans |= get(a-1,b,c);
		if (b >= 2) ans |= get(a,b-1,c);
		if (c >= 2) ans |= get(a,b,c-1);
		
		if (a && b) ans |= get(a-1,b-1,c+1);
		if (b && c) ans |= get(a+1,b-1,c-1);
		if (c && a) ans |= get(a-1,b+1,c-1);
		
		dp[a][b][c] = ans;
		return ans;
	}
		
	void main() {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		
		map<char, ll> M;
		for (char c : s) M[c]++;
		
		string rgb = "BGR";
		
		ll ans = get(M[rgb[2]], M[rgb[1]], M[rgb[0]]);
		
		REP(i,0,3) {
			if ((1LL << i) & ans) {
				cout << rgb[i];
			}
		}
		cout << endl;
		
		
		debug(ans);
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
