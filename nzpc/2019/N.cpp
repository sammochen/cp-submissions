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

ll cur_time;
VVLL scc;

void dfs(ll at, VVLL & E, VLL & first, VLL & low, stack<ll> & stack, VLL & onstack) {
	first[at] = cur_time;
	low[at] = cur_time;
	stack.push(at);
	onstack[at] = 1;
	cur_time++;

	for (ll to : E[at]) {
		if (first[to] == -1) {
			dfs(to, E, first, low, stack, onstack);
			low[at] = min(low[at], low[to]);
		} else if (onstack[to]) {
			low[at] = min(low[at], first[to]);
		}
	}

	if (first[at] == low[at]) {
		VLL comp;
		ll last;
		do {
			last = stack.top();
			comp.push_back(last);
			onstack[last] = 0;
			stack.pop();
		} while (last != at);

		scc.push_back(comp);
	}
}	

VLL tin, tout;
ll timer = 0;
vector<PLL> treeid;
VLL depth;
PLL tag; // keep tree id AND its index

void bldfs(ll v, ll p, ll d, VVLL & E) {
	treeid[v] = tag;
	depth[v] = d;
	tin[v] = ++timer;

	for (ll to : E[v]) {
		if (to != p) bldfs(to, v, d+1, E);
	}
	tout[v] = ++timer;
}

// returns if u is parent of v
ll isparent(ll u, ll v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}


void solve() {
	cur_time = 1;
	ll n, m;
	cin >> n >> m;
	VVLL E(n);
	VVLL revE(n);
	VLL first(n, -1), low(n), onstack(n);
	stack<ll> stack;

	REP(i,0,n) {
		ll b;
		cin >> b;
		E[i].push_back(b);
		revE[b].push_back(i);
	}

	REP(i,0,n) {
		if (first[i] == -1) dfs(i, E, first, low, stack, onstack);
	}

	VLL roots;
	VLL id(n);
	VLL ind(n); // if i is in a cycle, this is its index

	REP(i,0,scc.size()) {
		if (scc[i].size() >= 2) {
			ll at = scc[i][0];
			ll index = 0;
			ind[at] = index;
			while (E[at][0] != scc[i][0]) {
				at = E[at][0];
				ind[at] = ++index;
			}

			roots.push_back(i);
		}
		for (ll v : scc[i]) id[v] = i;
	}

	// build my lca tree
	ll newn = scc.size();
	tin.resize(newn);
	tout.resize(newn);
	treeid.resize(newn, {-1,-1});
	depth.resize(newn);
	timer = 0;

	VVLL newE(newn);
	REP(i,0,n) {
		for (ll to : E[i]) {
			if (id[i] != id[to]) {
				newE[id[to]].push_back(id[i]);
			}
		}
	}
	
	REP(i,0,n) {
		if (scc[id[i]].size() >= 2) {
			// in some cycle
			// traverse 
			tag = {id[i], ind[i]};
			treeid[id[i]] = tag;
			for (ll to : revE[i]) {
				if (id[i] == id[to]) continue;
				bldfs(id[to], id[to], 1, newE);
			}
		}
	}

	REP(i,0,m) {
		ll a, b;
		cin >> a >> b;

		if (id[a] == id[b]) {
			// cycle
			ll mod = scc[id[a]].size();
			cout << (ind[b] - ind[a] + mod) % mod << endl;
		} else if (treeid[id[a]].first == id[b]) {
			ll mid = treeid[id[a]].second;
			ll mod = scc[id[b]].size();
			cout << (ind[b] - mid + mod) % mod + depth[id[a]] << endl;
		} else if (treeid[id[a]] == treeid[id[b]] && isparent(id[b], id[a])) {
			cout << depth[id[a]] - depth[id[b]] << endl;
		} else {
			cout << -1 << endl;
		}
		
	}

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}