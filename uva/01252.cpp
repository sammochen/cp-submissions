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
	ll m, n;
	map<set<string>, ll> done;
	map<set<string>, ll> dp;

	ll get(set<string> A) {
		if (A.size() == 1) return 0;
		if (done[A]) return dp[A];

		// else, return the max of any splitting + 1
		ll ans = inf;
		REP(i,0,m) {
			set<string> zero, one;
			for (string s : A) {
				if (s[i] == '0') {
					zero.insert(s);
				} else {
					one.insert(s);
				}
			}

			if (one.size() == 0 || zero.size() == 0) {
				continue;
			} else {
				ans = min(ans, max(get(one), get(zero)) + 1);
			}
		}
		done[A] = 1;
		dp[A] = ans;
		return ans;
	}

	void main() {
		while (in(m,n), m || n) {
			set<string> A;
			REP(i,0,n) {
				string s;
				in(s);
				A.insert(s);
			}

			ll ans = get(A);
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
