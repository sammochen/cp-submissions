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

ll dp[15][15][15][15];

ll get(ll digit, ll upper, ll lower, ll n) {
	if (n == 0) {
		if (digit > 0 || upper > 0 || lower > 0) return 0;
		return 1;
	}
	digit = max(digit, 0LL);
	upper = max(upper, 0LL);
	lower = max(lower, 0LL);
	if (dp[digit][upper][lower][n] != -1) return dp[digit][upper][lower][n];


	ll ans = 0;
	ans += get(digit-1, upper, lower, n-1) * 10;
	ans += get(digit, upper-1, lower, n-1) * 26;
	ans += get(digit, upper, lower-1, n-1) * 26;

	dp[digit][upper][lower][n] = ans;
	return ans;
}

void bt(ll amount, string & cur, ll digit, ll upper, ll lower, ll n) {
	if (n == 0) return;

	ll now = get(digit-1, upper, lower, n-1) * 10;
	if (amount < now) {
		// must be a number
		ll one = get(digit-1, upper, lower, n-1);
		ll x = amount / one;
		cur.push_back(x + '0');
		bt(amount % one, cur, digit-1, upper, lower, n-1);
		return;
	} 
	amount -= now;
	now = get(digit, upper-1, lower, n-1) * 26;
	if (amount < now) {
		// must be a upper
		ll one = get(digit, upper-1, lower, n-1);
		ll x = amount / one;
		cur.push_back(x + 'A');
		bt(amount % one, cur, digit, upper-1, lower, n-1);
		return;
	} 
	amount -= now;
	now = get(digit, upper, lower-1, n-1) * 26;
	if (amount < now) {
		// must be a lower
		ll one = get(digit, upper, lower-1, n-1);
		ll x = amount / one;
		cur.push_back(x + 'a');
		bt(amount % one, cur, digit, upper, lower-1, n-1);
		return;
	} 

}

void solve() {
	memset(dp, -1, sizeof(dp));

	ll n;
	ll a, b, c;
	cin >> n >> a >> b >> c;
	ll k;
	cin >> k;

	string ans;
	bt(k-1, ans, a, b, c, n);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}