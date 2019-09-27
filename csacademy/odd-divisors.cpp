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
	ll f(ll a, ll b) {
		ll ans = ((a + b) / 2) * ((b - a) / 2 + 1);
		//debug(a,b,ans);
		return ans;
	}
	
	ll r(ll a, ll b) {
		if (a == b) {
			if (a%2) return a;
			return r(a/2,b/2);
		}
		
		// find odd and even sides
		ll oL = a % 2 ? a : a + 1;
		ll eL = a % 2 ? a + 1 : a;
		
		ll oR = b % 2 ? b : b - 1;
		ll eR = b % 2 ? b - 1 : b;
		
		return r(eL/2, eR/2) + f(oL, oR);
		
	}
	void main() {
		ll a, b;
		cin >> a >> b;
		ll ans = r(a, b);
		cout << ans << endl;
		
	}
}


signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
