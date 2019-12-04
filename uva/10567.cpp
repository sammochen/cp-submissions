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
	ll n = 1000005;
	ll x;
	char buf[n]; // note the 100 limit
	x = scanf("%1000004s", buf);
	s = buf;
}

void in(ll & a) {
	ll x;
	x = scanf("%lld", &a);
}

ll next(VLL & A, ll x) {
	ll L = 0, R = A.size() - 1;
	while (L < R) {
		ll M = (L + R) / 2;
		if (A[M] >= x) R = M;
		else L = M + 1;
	}
	return A[L];
}

ll to(char c) {
	if (c <= 'Z') {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

namespace SOLVE {	
	void main() {
		string s;
		in(s);

		VVLL ind(52);
		REP(i,0,s.length()) {
			ind[to(s[i])].push_back(i);
		}

		debug(ind);
		// for every index, i will find where the next index for every letter is
		// this is O(26 * n * log(n))
		// alternatively, i wil
		ll t;
		in(t);
		REP(i,0,t) {
			string q;
			in(q);

			ll x = -1;
			ll ok = 1;
			REP(j,0,q.length()) {
				if (ind[to(q[j])][ind[to(q[j])].size() - 1] <= x) {
					ok = 0;
					break;
				} else {
					x = next(ind[to(q[j])], x+1);
				}
			}

			if (ok) printf("Matched %lld %lld\n", ind[to(q[0])][0], x);
			else printf("Not matched\n");
		}
	}
}


signed main() {
	ll t;
	t = 1;
	// in(t);
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
