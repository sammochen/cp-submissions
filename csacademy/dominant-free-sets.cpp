/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

#define lsb(i) ((i) & (-i))

const ll nax = 100005;
const ll MOD = 1e9 + 7;

namespace SOLVE {	
	VLL tree;

	void mod(ll &x) {
		x %= MOD;
		while (x < 0) x += MOD;
		x %= MOD;
	}

	ll sum(ll i) {
		ll ans = 0;
		while(i > 0) {
			ans += tree[i];
			mod(ans);
			i -= lsb(i);
		}
		return ans;
	}

	void add(ll i, ll k) {
		while (i < nax) {
			tree[i] += k;
			mod(tree[i]);
			i += lsb(i);
		}
	}

	void main() {
		ll n;
		cin >> n;
		tree.resize(nax);

		vector<PLL> A(n);
		REP(i,0,n) cin >> A[i].first >> A[i].second;

		sort(A.begin(), A.end());

		REP(i,0,n) {
			ll ans = 1 + sum(nax) - sum(A[i].second);
			mod(ans);
			add(A[i].second, ans);
		}

		ll ans = sum(nax);
		cout << ans << endl;


	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
