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
	struct state {
		ll x, y, dir, dist;
	};

	bool operator<(const state & a, const state & b) {
		if (a.x == b.x) {
			if (a.y == b.y) {
				if (a.dir == b.dir) {
					return a.dist < b.dist;
				}
				return a.dir < b.dir;
			}
			return a.y < b.y;
		}
		return a.x < b.x;
	}

	void main() {
		ll n, m;
		while (cin >> n >> m) {
			if (n == 0 && m == 0) return;
			
			VVLL A(n, VLL(m));
			REP(i,0,n) REP(j,0,m) cin >> A[i][j];

			//        E S W N
			VLL dx = {0,1,0,-1};
			VLL dy = {1,0,-1,0};

			ll bx, by, ex, ey, dir;
			string d;
			cin >> bx >> by >> ex >> ey >> d;
			
			if (d == "south") dir = 1;
			if (d == "north") dir = 3;
			if (d == "east") dir = 0;
			if (d == "west") dir = 2;

			deque<state> Q;
			Q.push_back({bx, by, dir, 0});
			map<state, ll> dist;
			map<state, ll> done;
			dist[{bx, by, dir, 0}] = 0;
			done[{bx, by, dir, 0}] = 1;

			while (Q.size()) {
				state at = Q.front();
				Q.pop_front();

				vector<state> nexts;
				VLL costs;

				
				ll cost = at.dist == 0 ? 1 : 0;
				nexts.push_back({at.x + dx[at.dir], at.y + dy[at.dir], at.dir, (at.dist + 1)%3});
				costs.push_back(at.dist % 3 == 0 ? 1 : 0);
			
				nexts.push_back({at.x, at.y, (at.dir + 1) % 4, 0});
				costs.push_back(1);
				nexts.push_back({at.x, at.y, (at.dir + 3) % 4, 0});
				costs.push_back(1);

				REP(i,0,nexts.size()) {
					state next = nexts[i];
					ll cost = costs[i];

					if (done[next]) continue;
					if (next.x <= 0 || next.x >= n) continue;
					if (next.y <= 0 || next.y >= m) continue;
					if (A[next.x][next.y] || A[next.x-1][next.y] || A[next.x][next.y-1] || A[next.x-1][next.y-1]) continue;

					done[next] = 1;
					dist[next] = dist[at] + cost;
					if (cost == 0) {
						Q.push_front(next);
					} else {
						Q.push_back(next);
					}
				}
			}

			ll ans = inf;
			REP(i,0,4) {
				REP(j,0,4) {
					state ansstate = {ex, ey, i, j};
					ll ansdist = done[ansstate] ? dist[ansstate] : inf;
					ans = min(ans, ansdist);
				}
			}
			ans = ans == inf ? -1 : ans;
			cout << ans << endl;
			


		}
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
