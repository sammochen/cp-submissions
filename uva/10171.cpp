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
		ll to, d;
	};

	struct todo {
		ll v, d;
	};

	bool operator<(const todo & a, const todo & b) {
		return a.d > b.d;
	};

	VLL dijkstra(vector<vector<edge>> & E, ll s) {
		VLL d(E.size(), inf);
		d[s] = 0;
		priority_queue<todo> pq;

		pq.push({s, 0});
		while (pq.size()) {
			todo t = pq.top();
			pq.pop();

			for (edge e : E[t.v]) {
				if (d[t.v] + e.d < d[e.to]) {
					pq.push({e.to, d[t.v] + e.d});
					d[e.to] = d[t.v] + e.d;
				}
			}
		}

		return d;
	}


	void main() {
		ll m;
		cin >> m;
		if (m == 0) exit(0);
		vector<vector<edge>> Y(26);
		vector<vector<edge>> M(26);
		REP(i,0,m) {
			string a,b,c,d;
			ll e;
			cin >> a >> b >> c >> d >> e;
			ll C = c[0] - 'A';
			ll D = d[0] - 'A';

			vector<vector<edge>> *E;
			if (a == "Y") E = &Y;
			else E = &M;

			if (b == "U") {
				(*E)[C].push_back({D, e});
			} else {
				(*E)[C].push_back({D, e});
				(*E)[D].push_back({C, e});
			}
		}
		string ys, ms;
		cin >> ys >> ms;

		ll ans = inf;
		VLL pos;
		VLL yd = dijkstra(Y, ys[0] - 'A');
		VLL md = dijkstra(M, ms[0] - 'A');
		REP(i,0,26) {
			ll d = yd[i] + md[i];
			if (d < ans) {
				ans = d;
				pos = {i};
			} else if (d == ans) {
				pos.push_back(i);
			}
		}
		
		if (ans == inf) cout << "You will never meet." << endl;
		else {
			cout << ans;
			for (ll p : pos) {
				char c = p + 'A';
				cout << ' ' << c;
			}
			cout << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	while (1) {
		SOLVE::main();
	}

	return 0;
}
