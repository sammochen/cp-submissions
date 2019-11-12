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
typedef vector<VVLL> VVVLL;

const ll inf = (ll)1e18 + 5;

namespace SOLVE {
	struct todo {
		ll x, y, mask, dist;
	};

	struct comparetodo {
		bool operator() (const todo &a, const todo &b) {
			return a.dist > b.dist;
		}
	};

	void main() {
		// dijkstras!
		ll n, m ; // row, col
		cin >> n >> m;

		VVLL grid(n, VLL(m));

		ll startx, starty;
		cin >> startx >> starty;

		ll P; // number of beepers
		cin >> P;
		REP(i,0,P) {
			ll a, b;
			cin >> a >> b;
			grid[a-1][b-1] |= (1LL << i);
		}


		// dijkstras, starting at (0,0)
		VVVLL d(n, VVLL(m, VLL((1LL << P), inf)));
		priority_queue<todo, vector<todo>, comparetodo> pq;

		pq.push({startx-1,starty-1,grid[startx-1][starty-1],0});

		while (pq.size()) {
			todo at = pq.top();
			pq.pop();

			if (d[at.x][at.y][at.mask] < at.dist) continue;
			d[at.x][at.y][at.mask] = at.dist;
 
			VLL dx = {0,0,1,-1};
			VLL dy = {1,-1,0,0};

			REP(dir,0,4) {
				ll xx = at.x + dx[dir];
				ll yy = at.y + dy[dir];
				if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
					ll newdist = at.dist + 1;
					ll newmask = at.mask | grid[xx][yy];
					if (newdist < d[xx][yy][newmask]) {
						d[xx][yy][newmask] = newdist;
						pq.push({xx,yy,newmask,newdist});
					}
				}
			}
		}

		ll ans = d[startx-1][starty-1][(1LL << P) - 1];
		
		
		cout << "The shortest path has length " << ans << endl;
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