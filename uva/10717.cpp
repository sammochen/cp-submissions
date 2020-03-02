#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

ll lcm(ll a, ll b) {
	return a * b / __gcd(a,b);
}

ll lcm(ll a, ll b, ll c, ll d) {
	return lcm(lcm(a,b), lcm(c,d));
}

void solve() {
	ll n, q;
	while (cin >> n >> q, n||q) {
		VLL A(n);
		REP(i,0,n) cin >> A[i];

		set<ll> lcms;
		REP(a,0,n) {
			REP(b,0,a) {
				REP(c,0,b) {
					REP(d,0,c) {
						lcms.insert(lcm(A[a], A[b], A[c], A[d]));
					}
				}
			}
		}

		REP(i,0,q) {
			ll x;
			cin >> x;

			ll small = -inf, big = inf;

			for (ll l : lcms) {
				if (x % l == 0) {
					small = max(small, x);
					big = min(big, x);
				} else {
					small = max(small, x/l * l);
					big = min(big, x/l * l + l);
				}
			}

			printf("%lld %lld\n", small, big);

		}
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}