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
struct edge {
	ll to, d;
};

struct todo {
	ll v, d;
};

bool operator<(const todo & a, const todo & b) {
	return a.d > b.d;
};

// reset EVERYTHING
VLL hotels(105); // all the hotels
VLL ind(10005); // ind[hotelnumber] -> ind of hotel
vector<vector<edge>> E1(10005); // og E
vector<set<ll>> E2(105); // for the new adjmatrx
VLL didE2(105); // calculated E2?

void dijkstra(ll s) {
	VLL d(10005, inf);
	d[s] = 0;
	priority_queue<todo> pq;
	pq.push({s, 0});

	while (pq.size()) {
		todo t = pq.top(); pq.pop();
		if (t.d > d[t.v]) continue;
		if (ind[t.v]) E2[ind[s]].insert(ind[t.v]);

		for (edge e : E1[t.v]) {
			if (d[t.v] + e.d > 600) continue;

			if (d[t.v] + e.d < d[e.to]) {
				pq.push({e.to, d[t.v] + e.d});
				d[e.to] = d[t.v] + e.d;
			}
		}
	}
}

ll bfs(ll s, ll t) {
	VLL d(105, inf);
	queue<ll> Q;
	Q.push(s);
	d[s] = 0;
	while (Q.size()) {
		ll at = Q.front(); Q.pop();

		if (!didE2[at]) {
			dijkstra(hotels[at]);
			didE2[at] = 1;
		}

		for (ll to : E2[at]) {
			debug(at, E2[at]);
			if (d[to] == inf) {
				d[to] = d[at] + 1;
				Q.push(to);
				if (to == t) return d[to]-1;
			}
		}
	}
	return -1;
}

void reset(VLL & a, ll n) {
	a.clear();
	a.resize(n);
}

void reset (vector<vector<edge>> & a, ll n){
	a.clear();
	a.resize(n);
}

void reset(vector<set<ll>> & a, ll n) {
	a.clear();
	a.resize(n);
}

void solve() {
	// using 1-indexing
	ll n;
	while (cin >> n, n) {
		// reset EVERYTHING
		reset(hotels, 105); 
		reset(ind, 10005);
		reset(E1, 10005);
		reset(E2, 105);
		reset(didE2, 105);

		ll h;
		cin >> h;
		REP(i,1,h+1) {
			cin >> hotels[i];
			ind[hotels[i]] = i;
		}
		hotels[h+1] = 1;
		hotels[h+2] = n;
		ind[1] = h+1;
		ind[n] = h+2;
		
		ll m;
		cin >> m;
		REP(i,0,m) {
			ll a, b, w;
			cin >> a >> b >> w;
			E1[a].push_back({b,w});
			E1[b].push_back({a,w});
		}


		ll ans = bfs(h+1, h+2);
		cout << ans << endl;
	}
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}