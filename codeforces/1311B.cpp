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

void solve() {
	ll n, m;
	cin >> n >> m;
	VLL A(n);
	map<ll,ll> edge;
	map<ll,ll> pos;
	REP(i,0,n) {
		cin >> A[i];
		pos[A[i]] = i;
	}

	REP(i,0,m) {
		ll x;
		cin >> x;
		edge[x] = 1;
	}

	// work out the earliest that each position can go to
	VLL earliest(n);
	vector<PLL> pairs;
	ll low = A[0], high = A[0];
	REP(i,1,n) {
		if (edge[i]) {
			low = min(low, A[i]);
			high = max(high, A[i]);
		} else {
			pairs.push_back({low, high});
			low = A[i];
			high = A[i];
		}
	}

	pairs.push_back({low, high});
	
	REP(i,1,pairs.size()) {
		if (pairs[i-1].second > pairs[i].first) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
	return;

	

}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}