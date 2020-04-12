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

struct leaf {
	ll v, d;
};

bool operator<(const leaf & a, const leaf & b) {
	return a.d > b.d;
};

void solve() {
	ll n, d;
	cin >> n >> d;

	ll l = 0, r = (n * (n-1)) / 2;
	ll len = -1;
	REP(i,1,n+1) {
		if ((i & (i-1)) == 0) len++;
		l += len;
	}
	
	if (d < l || d > r) {
		cout << "NO" << endl;
		return;
	}


	priority_queue<leaf> leaves;
	VLL par(n);
	VLL dep(n);
	VLL cnt(n);
	VLL bad(n);
	vector<set<ll>> nodes(n);

	// start with a chain of nodes
	REP(i,0,n) {
		par[i] = i-1;
		dep[i] = i;
		cnt[i] = 1;
		nodes[i].insert(i);
	}
	cnt[n-1] = 0;
	leaves.push({n-1, n-1});

	ll cur = (n * (n-1)) / 2;
	
	while (cur > d && leaves.size()) {
		leaf at = leaves.top(); leaves.pop();
		
		if (at.d-2 < 0 || nodes[at.d-2].size() == 0)  {
			bad[at.v] = 1;
			continue;
		}

		ll oldp = par[at.v];
		ll p = *nodes[at.d-2].begin();

		cnt[p]++;
		cnt[oldp]--;

		dep[at.v]--;
		par[at.v] = p;

		if (cnt[p] == 2) nodes[at.d-2].erase(p);
		if (cnt[oldp] == 1) nodes[at.d-1].insert(oldp);

		nodes[at.d].erase(at.v);
		nodes[at.d-1].insert(at.v);

		// identify new leaves
		if (at.d-1 >= 2) {
			if (!bad[at.v]) leaves.push({at.v, at.d-1});
			if (!bad[oldp] && cnt[oldp] == 0) leaves.push({oldp, at.d-1});
		}

		cur--;
	}

	cout << "YES" << endl;
	REP(i,1,n) {
		cout << par[i] + 1 << " ";
	}
	cout << endl;

}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}