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
	void main() {
		ll n;
		cin >> n;
		VLL A(n);
		REP(i,0,n) {
			cin >> A[i];
		}

		if (n == 1) {
			cout << A[0] << endl;
			return;
		}

		VLL pre(n, A[0]);
		VLL suf(n, A[n-1]);
		REP(i,1,n) {
			pre[i] = __gcd(pre[i-1], A[i]);
		}
		RREP(i,n-2,0) {
			suf[i] = __gcd(suf[i+1], A[i]);
		}

		debug(pre);
		debug(suf);


		if (A[0] % suf[1] != 0) {
			cout << A[0] << endl;
			return;
		} else if (A[n-1] % pre[n-2] != 0) {
			cout << A[n-1] << endl;
			return;
		}

		// find some A[i] where __gcd(A[i-1], A[i+1]) cannot go into A[i]
		REP(i,1,n-1) {
			ll g = __gcd(pre[i-1], suf[i+1]);
			if (A[i] % g != 0) {
				cout << g << endl;
				return;
			}
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
