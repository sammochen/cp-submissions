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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {
	struct todo {
		ll v, mask, dist;
	};

	struct comparetodo {
		bool operator() (const todo &a, const todo &b) {
			return a.dist > b.dist;
		}
	};

	struct edge {
		ll v, w;
	};

	ll moneytoll(string s) {
		string a = "";
		for (char c : s) {
			if (c != '.') a += c;
		}
		return stoll(a);
	}

	string lltomoney(ll x) {
		x = abs(x);
		string dollars = to_string(x/100);
		string cents = (x%100) < 10 ? "0" + to_string(x%100) : to_string(x%100);
		return "$" + dollars + "." + cents;
	}

	void main() {
		// dijkstras!
		// each vertex is (node, mask) for the mask that they have been to
		// find the shortest paths between d((0,0) and (0,mask)) - savings(mask) for all masks

		// O(~ n * 2^P * log(m)) (due to dijkstras)

		ll n, e ; // vertices, edges
		cin >> n >> e;

		vector<vector<edge>> adjlist(n+1);
		
		REP(i,0,e) {
			ll a, b;
			string s;
			cin >> a >> b >> s;
			adjlist[a].push_back({b, moneytoll(s)});
			adjlist[b].push_back({a, moneytoll(s)});
		}

		ll P; // number of operas
		cin >> P;

		VLL have(n+1); // have[n] gives the operas at some node n
		VLL saving(P); // saving[opera] gives the saving of opera

		REP(i,0,P) {
			ll a;
			string s;
			cin >> a >> s;
			have[a] |= (1LL << i);
			saving[i] += moneytoll(s);
		}

		// dijkstras, starting at (0,0)
		VVLL d(n+1, VLL((1LL << P), inf));
		priority_queue<todo, vector<todo>, comparetodo> pq;

		pq.push({0,0,0});
		d[0][0] = 0;

		while (pq.size()) {
			todo at = pq.top();
			pq.pop();

			if (d[at.v][at.mask] < at.dist) continue;
			d[at.v][at.mask] = at.dist;

			for (edge to : adjlist[at.v]) {
				ll newdist = at.dist + to.w;
				ll newmask = at.mask | have[to.v];

				if (newdist < d[to.v][newmask]) {
					d[to.v][newmask] = newdist;
					pq.push({to.v, newmask, newdist});
				}
			}
		}

		ll ans = inf;
		REP(mask,0,(1LL << P)) {
			ll saved = 0;
			REP(i,0,P) {
				if ((1LL << i) & mask) saved += saving[i];
			}
			ll x = d[0][mask] - saved;

			ans = min(ans, x);
		}
		
		
		if (ans == 0) {
			cout << "Don't leave the house\n";
		} else {
			cout << "Daniel can save " + lltomoney(ans) + "\n";
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	t = 1;
	cin >> t;

	while (t--) {
		SOLVE::main();
	}

	return 0;
}
