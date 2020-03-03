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
typedef vector<VVLL> VVVLL;

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
	string a, b;
	ll A, B;
	VVVLL dp;

	ll f(char c) {
		if (c == '(') return 1;
		else return -1;
	}

	ll get(ll i, ll j, ll open) {
		if (open < 0) return inf;
		if (i == A + 1) return inf;
		if (j == B + 1) return inf;
		if (i == A && j == B) return open;

		if (open > 205) return inf;
		if (dp[i][j][open] != -1) return dp[i][j][open];
		
		ll ans = inf;
		// take i
		ans = min(ans, 1 + get(i + 1, j, open + f(a[i])));
		// take j
		ans = min(ans, 1 + get(i, j + 1, open + f(b[j])));
		// add a bracket
		ans = min(ans, 1 + get(i, j, open + 1));

		// if a[i] and b[j] are the same, do both!
		if (a[i] == b[j]) {
			ans = min(ans, 1 + get(i + 1, j + 1, open + f(a[i])));
		}
		dp[i][j][open] = ans;
		return ans;
	}

	string s;
	void gets(ll i, ll j, ll open) {
		if (i == A && j == B) {
			REP(i,0,open) s += ")";
			return;
		}

		ll best;
		ll ans = inf;


		// 1: take i
		ll opt1 = 1 + get(i + 1, j, open + f(a[i]));
		if (opt1 < ans) {
			ans = opt1;
			best = 1;
		}

		ll opt2 = 1 + get(i, j + 1, open + f(b[j]));
		if (opt2 < ans) {
			ans = opt2;
			best = 2;
		}

		ll opt3 = 1 + get(i, j, open + 1);
		if (opt3 < ans) {
			ans = opt3;
			best = 3;
		}

		if (a[i] == b[j]) {
			ll opt4 = 1 + get(i + 1, j + 1, open + f(a[i]));
			if (opt4 < ans) {
				ans = opt4;
				best = 4;
			}
		}

		if (best == 1) {
			s += a[i];
			gets(i + 1, j, open + f(a[i]));
		} else if (best == 2) {
			s += b[j];
			gets(i, j + 1, open + f(b[j]));
		} else if (best == 3) {
			s += "(";
			gets(i, j, open + 1);
		} else {
			s += a[i];
			gets(i + 1, j + 1, open + f(a[i]));
		}
	}

	void main() {
		cin >> a >> b;
		A = a.length();
		B = b.length();
		a += "!!!!";
		b += "!!!!";

		dp.resize(A + 5, VVLL(B + 5, VLL(500, -1)));

		gets(0,0,0);
		cout << s << endl;

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