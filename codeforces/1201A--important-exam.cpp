/*
Original problem: https://codeforces.com/contest/1201/problem/A
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

const int inf = 1e9 + 7;

namespace SOLVE {
	void main() {
		// brute force/greedy - for each question j of m, see which of A-E is best
		int n, m;
		cin >> n >> m;
		vector<string> answers(n);
		VI scores(m);
		REP(i, 0, n) {
			cin >> answers[i];
		}
		REP(i, 0, m) {
			cin >> scores[i];
		}
		int best = 0;
		REP(i, 0, m) { // for each question
			int bestoption = 0;
			REP(c, 0, 5) {
				int score = 0;
				char C = 'A' + c;
				REP(j, 0, n) {
					if (answers[j][i] == C) {
						score += scores[i];
					}
				}
				bestoption = max(bestoption, score);
			}
			best += bestoption;
		}
		cout << best << endl;

	}
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}