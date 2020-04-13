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
	ll n, k;
	cin >> n >> k;
	queue<ll> q;
	map<ll,ll> inq;
	REP(i,0,n) {
		ll x;
		cin >> x;
		if (inq[x]) continue;

		if (q.size() == k) {
			inq[q.front()] = 0;
			q.pop();
		}
		q.push(x);
		inq[x] = 1;
	}

	stack<ll> st;
	while (q.size()) {
		st.push(q.front());
		q.pop();
	}
	cout << st.size() << endl;
	while (st.size()) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}