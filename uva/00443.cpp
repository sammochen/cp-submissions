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

string suffix(ll x) {
	if (x % 10 == 1 && x % 100 != 11) return "st";
	if (x % 10 == 2 && x % 100 != 12) return "nd";
	if (x % 10 == 3 && x % 100 != 13) return "rd";
	return "th";
}
void solve() {
	ll big = 1e12;
	set<ll> S;
	for (ll a = 1; a < big; a *= 2) {
		for (ll b = 1; a*b < big; b *= 3) {
			for (ll c = 1; a*b*c < big; c *= 5) {
				for (ll d = 1; a*b*c*d < big; d *= 7) {
					S.insert(a*b*c*d);
				}
			}
		}
	}
	VLL A;
	for (ll x : S) A.push_back(x);

	ll n;
	while (cin >> n, n) {
		printf("The %lld%s humble number is %lld.\n", n, suffix(n).c_str(), A[n-1]);
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}