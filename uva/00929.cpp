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

namespace SOLVE {	
	struct todo {
		ll i, j, cost;
	};

	bool operator<(const todo & a, const todo & b) {
		return a.cost > b.cost;
	}


	const ll inf = (ll)1e18 + 5;

	void main() {
		ll n, m;
		cin >> n >> m;
		VVLL A(n, VLL(m));
		REP(i,0,n) REP(j,0,m) cin >> A[i][j];

		VVLL d(n, VLL(m, inf));
		

		priority_queue<todo> pq;
		d[0][0] = A[0][0];
		pq.push({0,0,A[0][0]});

		while (pq.size()) {
			todo at = pq.top();
			pq.pop();

			if (at.cost > d[at.i][at.j]) continue;

			VLL di = {0,0,1,-1};
			VLL dj = {1,-1,0,0};

			REP(x,0,4) {
				ll ii = at.i + di[x];
				ll jj = at.j + dj[x];

				if (0 <= ii && ii < n && 0 <= jj && jj < m) {
					ll newcost = at.cost + A[ii][jj];

					if (newcost < d[ii][jj]) {
						d[ii][jj] = newcost;
						pq.push({ii,jj,newcost});
					}
				}
			}
		}

		cout << d[n-1][m-1] << endl;



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
