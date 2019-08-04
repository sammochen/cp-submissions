/*
Original problem: https://www.hackerrank.com/challenges/red-knights-shortest-path
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define MP make_pair
#define PII pair<int,int>
#define PLL pair<ll,ll>


typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	int n;

	// in the grid!
	int valid(int i, int j) {
		return (i >= 0 && i < n && j >= 0 && j < n);
	}

	// a way to represent the 2d coordinate as an int
	int convert(int i, int j) {
		return i * n + j;
	}

	// determines the direction given the before and after
	string direction(PII before, PII after) {
		int di = after.first - before.first;
		int dj = after.second - before.second;
		switch (100 * di + dj) {
		case (-2):
			return "L";

		case (-201):
			return "UL";

		case (-199):
			return "UR";

		case (2):
			return "R";

		case (201):
			return "LR";

		case (199):
			return "LL";

		}
		return "-1";
	}

	void main() {
		// strategy: perform bfs. keep track of each square's parent, and work out the direction backwards
		int istart, jstart, iend, jend;
		cin >> n >> istart >> jstart >> iend >> jend;
		VI visited(n * (n + 1));
		vector<PII> parent(n * (n + 1), MP(-1,-1));

		// bfs!
		queue<PII> q;
		q.push(MP(istart, jstart));
		visited[convert(istart, jstart)] = 1;

		while (q.size()) {
			PII t = q.front();
			q.pop();

			// order of preference:
			// UL, UR, R, LR, LL, L
			int di[6] = { -2,-2,0,2,2,0 };
			int dj[6] = { -1,1,2,1,-1,-2 };
			
			REP(move, 0, 6) {
				int ii = t.first + di[move];
				int jj = t.second + dj[move];
				if (valid(ii, jj) && !visited[convert(ii,jj)]) {
					q.push(MP(ii, jj));
					visited[convert(ii, jj)] = 1;
					parent[convert(ii, jj)] = t;
				}
			}
		}

		// if not visited: impossible
		if (visited[convert(iend, jend)] == 0) {
			cout << "Impossible" << endl;
			return;
		}

		// determine the directions
		stack<string> ans;
		PII ptr = MP(iend, jend);
		while (ptr.first != istart || ptr.second != jstart) {
			PII before = parent[convert(ptr.first, ptr.second)];
			ans.push(direction(before, ptr));
			ptr = before;
		}

		// present answer
		cout << ans.size() << endl;
		while (ans.size()) {
			cout << ans.top() << ' ';
			ans.pop();
		}
	}
}

signed main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}
	return 0;
}