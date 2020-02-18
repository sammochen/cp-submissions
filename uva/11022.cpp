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

namespace SOLVE {	
	ll sub(string & s, string & t) {
		if (s == t) return 1;
		if (s.length() % t.length() != 0) return 0;
		REP(i,0,s.length()) {
			if (s[i] != t[i % t.length()]) return 0;
		}
		return 1;
	}

	map<string, ll> done, dp;
	ll get(string s) {
		if (done[s]) return dp[s];
		ll n = s.length();
		ll ans = n;
		if (n == 1) return 1;

		// see how it could be subdivided, wholly by itself
		string t;
		REP(len,1,n) {
			t += s[len-1];
			if (sub(s, t)) ans = min(ans, get(t));
		}

		// or, split the string up into two
		REP(len,1,n) {
			string a = s.substr(0,len);
			string b = s.substr(len);
			ans = min(ans, get(a) + get(b));
		}

		done[s] = 1;
		dp[s] = ans;
		return ans;
	}

	void main() {
		string s;
		while (cin >> s, s != "*") {
			ll ans = get(s);
			printf("%lld\n", ans);
		}
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
