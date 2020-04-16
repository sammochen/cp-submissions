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

ll a, b;
ll dfs(ll bit, VLL & lo, VLL & hi) {
	if (bit == -1 || (lo.size() == 0 && hi.size() == 0)) return (1LL << (bit+1));
	else {
		ll ans = 0;
		REP(on,0,2) {
			ll twop = (1LL << bit);
			VLL newlo, newhi;
			ll ok = 1;
			for (ll l : lo) {
				if (on) l ^= twop;
				if ((l & twop) < (a & twop)) {
					ok = 0;
					break;
				} else if ((l & twop) > (a & twop)) {
					
				} else {
					newlo.push_back(l & (~twop));
				}
			}

			for (ll h : hi) {
				if (on) h ^= twop;
				if ((h & twop) > (b & twop)) {
					ok = 0;
					break;
				} else if ((h & twop) < (b & twop)) {

				} else {
					newhi.push_back(h & (~twop));
				}
			}

			if (ok) ans += dfs(bit-1, newlo, newhi);
		}
		return ans;
	}
}

void solve() {
	ll n, w;
	cin >> n >> w;
	cin >> a >> b;
	VLL lo, hi;
	REP(i,0,n) {
		ll x;
		cin >> x;
		lo.push_back(x);
		hi.push_back(x);
	}

	cout << dfs(w, lo, hi) << endl;


}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}