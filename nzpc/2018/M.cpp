#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

ll n, a, b;
VLL A, L, R;

ll dp[3005][3005];

ll get(ll i, ll j, ll k, ll rem) {
	if (k == n) return 1;
	if (i >= a && j >= b) return 0;
	if (dp[i][j] != -1) return dp[i][j];


	ll ans = 0;
	if (i < a) {
		if (L[i] < rem) {
			ans |= get(i+1, j, k, rem-L[i]);
		} else if (L[i] == rem) {
			ans |= get(i+1, j, k+1, A[k+1]);
		}
	}

	if (j < b) {
		if (R[j] < rem) {
			ans |= get(i, j+1, k, rem-R[j]);
		} else if (R[j] == rem) {
			ans |= get(i, j+1, k+1, A[k+1]);
		}
	}

	dp[i][j] = ans;

	return ans;
}

void solve() {
	mst(dp,-1);

	in(n,a,b);
	A.resize(n);
	L.resize(a);
	R.resize(b);
	in(A, L, R);

	A.push_back(0);

	string ans = get(0,0,0,A[0]) ? "YES" : "NO";
	cout << ans << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}