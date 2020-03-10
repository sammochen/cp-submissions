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

PLL overlap(PLL a, PLL b) {
	PLL ans = {max(a.first, b.first), min(a.second, b.second)};
	if (ans.first >= ans.second) return {-1,-1};
	return ans;
}

ll first = 1;
void solve() {
	if (!first) cout << endl;
	first = 0;
	
	VLL A(4), B(4);
	REP(i,0,4) cin >> A[i];
	REP(i,0,4) cin >> B[i];

	PLL x = overlap({A[0], A[2]}, {B[0], B[2]});
	PLL y = overlap({A[1], A[3]}, {B[1], B[3]});
	debug(x,y);
	if (x.first == -1 || y.first == -1) cout << "No Overlap" << endl;
	else printf("%lld %lld %lld %lld\n", x.first, y.first, x.second, y.second);


}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}