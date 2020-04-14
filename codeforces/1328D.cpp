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
		ll n;
		cin >> n;
		VLL A(n);
		set<ll> s;
		REP(i,0,n) {
			cin >> A[i];
			s.insert(A[i]);
		}

		if (s.size() == 1) {
			cout << 1 << endl;
			REP(i,0,n) cout << 1 << ' ';
			cout << endl;
			return;
		}

		ll q = 2;
		VLL ans(n);

		if (n%2==0) {
			REP(i,0,n) {
				ll x = (i%2) + 1;
				ans[i] = x;
			}
		} else {
			ll cur = 1;
			ll good = 0;
			REP(i,0,n) {
				if (!good && i > 0 && (A[i] == A[i-1])) {
					cur = 3 - cur;
					good = 1;
				}
				if (i == n-1 && !good && A[n-1] != A[0]) {
					q = 3;
					cur = 3;
				}

				ans[i] = cur;
				cur = 3 - cur;
			}
		}

		cout << q << endl;
		for (ll c : ans) cout << c << ' ';
		cout << endl;
	}

	signed main() {
		ll t = 1;
		cin >> t;
		REP(i,0,t) solve();
		return 0;
	}