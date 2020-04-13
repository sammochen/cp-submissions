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

VLL p; 

ll getp(ll x) {
	if (p[x] == x) return x;
	p[x] = getp(p[x]);
	return p[x];
}

void merge(ll a, ll b) {
	p[getp(a)] = getp(b);
}

ll same(ll a, ll b) {
	return getp(a) == getp(b);
}

void init(ll n) {
	p.clear();
	p.resize(n);
	REP(i,0,n) p[i] = i;
}

struct edge {
	ll a, b, w;
};

bool operator<(const edge & a, const edge & b) {
	return a.w > b.w;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	init(n+5);

	priority_queue<edge> edges;
	REP(i,0,m) {
		ll a, b, c;
		cin >> a >> b >> c;
		edges.push({a,b,c});
	}

	ll small = -inf;
	ll ans = 0;
	while (edges.size()) {
		vector<edge> current = {edges.top()};
		ll weight = current[0].w;
		edges.pop();

		while (edges.size() && edges.top().w == weight) {
			current.push_back(edges.top());
			edges.pop();
		}
		ll good = 0;
		for (edge e : current) {
			if (!same(e.a, e.b)) good++;
		}

		// count how many merges it did
		ll merges = 0;
		for (edge e: current) {
			if (!same(e.a, e.b)) {
				merges++;
				merge(e.a, e.b);
			}
		}
		
		ans += good - merges;
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}