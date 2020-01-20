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
	ll score(VVLL A) {
		ll v = 0;
		ll u = 0;
		REP(i,0,3) {
			v += A[i][i];
			u += A[i][2-i];
		}
		if (u != v) return inf;
		REP(i,0,3) {
			ll a = 0, b = 0;
			REP(j,0,3) {
				a += A[i][j];
				b += A[j][i];
			}
			if (a != v) return inf;
			if (b != v) return inf;
		}
		return 0;
	}

	ll f(VVLL A, ll ind, ll used) {
		if (ind == 9) return score(A);

		ll i = ind / 3, j = ind % 3;
		ll best = inf;
		REP(x,1,10) {
			if ((1LL << x) & used) continue;
			
			VVLL next = A;
			next[i][j] = x;
			best = min(best, abs(x - A[i][j]) + f(next, ind+1, used | (1LL << x)));
		}
		return best;
	}
	
	void main() {
		VVLL A(3, VLL(3));
		REP(i,0,3) REP(j,0,3) cin >> A[i][j];

		ll ans = f(A, 0, 0);
		cout << ans << endl;

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
