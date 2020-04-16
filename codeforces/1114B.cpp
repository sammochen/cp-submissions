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
	ll n, m, k;
	cin >> n >> m >> k;
	VLL A(n);
	REP(i,0,n) {
		cin >> A[i];
	}

	VLL B = A;
	sort(B.begin(), B.end());

	map<ll,ll> good;
	ll total = 0;
	RREP(i,n-1,n-m*k) {
		good[B[i]]++;
		total += B[i];
	}

	VLL ans;
	ll cnt = 0;
	REP(i,0,n) {
		if (good[A[i]]) {
			good[A[i]]--;
			cnt++;
			if (cnt == m) {
				ans.push_back(i+1);
				cnt = 0;
			}
		}
	}

	cout << total << endl;
	REP(i,0,ans.size() - 1) cout << ans[i] << ' ';
	cout << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}