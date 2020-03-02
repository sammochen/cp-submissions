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

ll n, k;
VVLL ans;

void get(VLL A, ll prev, ll value) {
	if (value == 0 && A.size() == k) {
		ans.push_back(A);
	} else if (A.size() == k) return;

	if (value < prev) return;
	
	REP(v,prev,value+1) {
		if (v * (k - A.size()) > value) break;
		
		ll ok = 1;
		for (ll a : A) {
			if (__gcd(a,v) != 1) {
				ok = 0;
				break;
			} 
		}
		if (!ok) continue;
		VLL B = A;
		B.push_back(v);
		get(B, v, value - v);
	}
}

ll test = 1;
void solve() {
	ans.clear();
	cin >> n >> k;
	// split n into k bits
	get({}, 1, n);
	printf("Case %lld:\n", test++);
	for (VLL a : ans) {
		REP(i,0,a.size()) {
			printf("%lld", a[i]);
			if (i == a.size() - 1) printf("\n");
			else printf(" ");
		}
	}
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}