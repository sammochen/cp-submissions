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

ll mod = 1e9+7;

void solve() {
	ll n;
	in(n);
	VLL A(n);
	in(A);

	map<ll,ll> yes;
	REP(i,0,n) {
		yes[A[i]] = 1;
	}

	ll nax = 1e6+5;

	vector<set<ll>> factors(nax);
	REP(i,1,n+1) {
		REP(f,i,nax+1) {
			if (i * f >= nax) break;
			if (!yes[i*f]) continue;

			if (i <= n) factors[i*f].insert(i);
			if (f <= n) factors[i*f].insert(f);
		}
	}

	VLL freq(n+1);
	freq[0] = 1;
	REP(i,0,n) {
		set<ll>::iterator it = factors[A[i]].end();
		it--;
		while (1) {
			ll f = *it;
			freq[f] += freq[f-1];
			freq[f] %= mod;
			
			if (it == factors[A[i]].begin()) break;
			it--;
		} 
	}

	ll ans = 0;
	REP(i,1,n+1) {
		ans += freq[i];
		ans %= mod;
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}