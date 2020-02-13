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
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
const ll mod = 1e9+7;

namespace SOLVE {
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) cin >> A[i];

		VLL numberdp(n+1, 1); // numberdp[0] = 1
		VLL pathdp(n+1);
		VLL toedgedp(n+1);
		VLL allpathsdp(n+1);

		// number
		REP(i,1,n+1) {
			numberdp[i] = (numberdp[i-1] * 4 + 2) % mod;
		}

		// path
		REP(i,1,n+1) {
			pathdp[i] = (pathdp[i-1] * 2 + 3 * A[i-1]) % mod;
		}

		// toedge
		REP(i,1,n+1) {
			ll ans = 0;
			ans += 4 * toedgedp[i-1]; // all of them to get to the corner first
			ans %= mod;
			ans += 8 * numberdp[i-1] * A[i-1]; // move three of the groups to the corner
			ans %= mod;
			ans += pathdp[i-1] * 3 % mod * numberdp[i-1]; // move the three groups to the corner
			ans %= mod;
			ans += 3 * A[i-1] + 2 * pathdp[i-1]; // move the new middle 2 to the corner
			ans %= mod;
			toedgedp[i] = ans;
		}

		// allpaths
		REP(i,1,n+1) {
			ll ans = 0;
			ans += 4 * allpathsdp[i-1] % mod; // all the inter-group
			ans %= mod;
			ans += toedgedp[i-1] * numberdp[i-1] % mod * 12; // each time to get to the corner
			ans %= mod;
			ans += numberdp[i-1] * numberdp[i-1] % mod * 16 % mod * A[i-1]; // each time the middle paths get traversed
			ans %= mod;
			ans += (6 * numberdp[i-1] * A[i-1] + toedgedp[i-1] * 4) * 2 % mod; // add middle to others
			ans %= mod;
			ans += 1 * A[i-1]; // between the middle
			ans %= mod;
			allpathsdp[i] = ans;
		}

		cout << allpathsdp[n] << endl;
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
