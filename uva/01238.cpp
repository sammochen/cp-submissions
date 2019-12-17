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
	ll f(ll a, ll b, string s, ll flip) {
		ll sign = 1;
		if (s == "-") sign *= -1;
		if (flip) sign *= -1;
		return a + sign * b;
	}

	map<VLL,ll> done;

	void get(ll ind, ll b, ll value, VLL & A, vector<string> & sign) {
		if (done[{ind, b, value}]) return;
		done[{ind, b, value}] = 1;

		// i can close as many brackets as i can
		if (b) {
			get(ind, b - 1, value, A, sign);
		}

		if (ind == A.size()) {
			return;
		}

		// dont change bracket
		get(ind + 1, b, f(value, A[ind], sign[ind], b%2), A, sign);

		// if it is a negative, i get to add a flip
		if (sign[ind] == "-") {
			get(ind + 1, b + 1, f(value, A[ind], sign[ind], b%2), A, sign);
		}
	}

	void main() {
		string s;
		while (getline(cin, s)) {
			stringstream ss;
			ss << s;
			VLL A(1);
			ss >> A[0];
			vector<string> sign = {"+"};

			done.clear();

			ll x;
			while (ss >> s) {
				sign.push_back(s);
				ss >> x;
				A.push_back(x);
			}

			get(0, 0, 0, A, sign);
			ll ans = 0;
			REP(i,-3005, 3005) {
				ans += done[{(ll)A.size(),0,i}];
			}
			cout << ans << endl;
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
