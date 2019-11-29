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

const ll inf = 1e9+7;

namespace SOLVE {	
	struct edge {
		string to;
		char c;
		ll d;
	};

	struct todo {
		string v;
		char last;
		ll d;
	};

	bool operator<(const todo & a, const todo & b) {
		return a.d > b.d;
	};

	void dijkstra(map<string, vector<edge>> & E, string s, string t) {
		map<pair<string, char>, ll> d;
		map<pair<string, char>, ll> done;

		REP(i,0,26) {
			char c = i + 'a';
			d[{s, c}] = 0;
			done[{s, c}] = 0;
		}

		priority_queue<todo> pq;

		pq.push({s, 'X', 0});

		ll ans = -1;

		while (pq.size()) {
			todo at = pq.top();
			pq.pop();

			if (at.v == t) {
				ans = at.d;
				break;
			}

			for (edge e : E[at.v]) {
				if (e.c == at.last) continue;

				if (!done[{e.to, e.c}] || at.d + e.d < d[{e.to, e.c}]) {
					pq.push({e.to, e.c, at.d + e.d});
					d[{e.to, e.c}] = at.d + e.d;
					done[{e.to, e.c}] = 1;
				}
			}
		}

		if (ans == -1) {
			cout << "impossivel" << endl;
		} else {
			cout << ans << endl;
		}
	}


	void main() {
		ll m;
		cin >> m;
		if (m == 0) exit(0);

		string s, t;
		cin >> s >> t;

		map<string, vector<edge>> E;

		REP(i,0,m) {
			string a, b, c;
			cin >> a >> b >> c;

			ll cost = c.length();
			E[a].push_back({b, c[0], cost});
			E[b].push_back({a, c[0], cost});
		}

		dijkstra(E, s, t);

	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t) {
		SOLVE::main();
	}

	return 0;
}
