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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];
		VLL f(n+1), b(n+1); // sum from forward and back, ending at i
		VLL ff(n+1, -inf), bb(n+1, -inf); // best of f and b
		
		ll ans = -inf;
		
		REP(i,0,n) {
			f[i+1] = max(f[i], 0LL) + A[i];
			ff[i+1] = max(ff[i], f[i+1]);
		}
		
		RREP(i,n-1,0) {
			b[i] = max(b[i+1], 0LL) + A[i];
			bb[i] = max(bb[i+1], b[i]);
		}
		
		// choose some element i to get rid of
		// the ans is the forward bit, backwards bit or both
		REP(i,0,n) {
			ans = max({ans, ff[i] + bb[i+1], ff[i], bb[i+1]});
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
