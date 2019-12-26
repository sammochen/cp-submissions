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
	// finds the lowest
	ll lower(ll v, VLL & A) {
		ll L = 0, R = A.size();
		while (L < R) {
			ll M = (L + R) / 2;
			if (A[M] >= v) R = M;
			else L = M + 1;
		}
		return L;
	}

	// finds the highest
	ll upper(ll v, VLL & A) {
		ll L = 0, R = A.size();
		while (L < R) {
			ll M = (L + R) / 2;
			if (A[M] <= v) L = M + 1;
			else R = M;
		}
		return L;
	}

	void main() {
		ll n, m;
		ll A[1005][505] = {};
		while (in(n, m), n || m) {
			ll f[1005] = {0};

			REP(i,0,n) {
				REP(j,0,m) {
					ll x;
					in(x);
					ll ind = i - j + m;
					A[ind][f[ind]++] = x;
				}
			}

			ll q;
			in(q);
			REP(i,0,q) {
				ll low, high;
				in(low, high);
				ll ans = 0;
				REP(i,0,n+m) {
					ll l = lower_bound(A[i], A[i] + f[i], low) - A[i];
					ll u = upper_bound(A[i] + l, A[i] + f[i], high) - A[i];
				
					ans = max(ans, u - l);
				}

				printf("%lld\n", ans);
			}
			printf("-\n");
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
