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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	ll ans = a+b+c;
	VLL A = {0,0,0};

	// enumerate a
	REP(i,1,2*a + 5) {
		ll x = i;
		if (x-a > ans) break;
		REP(j,1,2*b + 5) {
			ll y = x*j;
			if (y-b + x-a > ans) break;
			
			// find the last number
			ll z = c%y <= y/2 ? c - c%y : c-c%y + y;
			
			ll cost = abs(x-a) + abs(y-b) + abs(z-c);
			if (cost < ans) {
				ans = cost;
				A = {x,y,z};
			}
		}
	}
	cout << ans << endl;
	cout << A[0] << ' ' << A[1] << ' ' << A[2] << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}