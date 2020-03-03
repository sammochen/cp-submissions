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

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll inf = 1e9 + 7;

namespace SOLVE {
    void main() {
		string s;
		cin >> s;

		// logs all positions: vert/hori
		vector<VLL> pos(2, VLL(1));

		for (char c : s) {
			if (c == 'W') {
				pos[0].push_back(pos[0][pos[0].size() - 1] + 1);
			}
			if (c == 'A') {
				pos[1].push_back(pos[1][pos[1].size() - 1] - 1);
			}
			if (c == 'S') {
				pos[0].push_back(pos[0][pos[0].size() - 1] - 1);
			}
			if (c == 'D') {
				pos[1].push_back(pos[1][pos[1].size() - 1] + 1);
			}
		}

		VLL width(2); // dimensions of box, vert/hori
		VLL flex(2); // whether vert/hori is reduce-able

		REP(i,0,2) { // vert and hori
			REP(j,0,2) { // +1 and -1
				if (j == 1) { // in the 2nd iteration, flip vector
					REP(k,0,pos[i].size()) {
						pos[i][k] *= -1;
					}
				}

				ll big = -inf, small = inf; 
				REP(k,0,pos[i].size()) {
					big = max(big, pos[i][k]);
					small = min(small, pos[i][k]);
				}
				width[i] = abs(big - small) + 1;

				// i want to insert +1: before the first min and after the last max
				int firstmin = -1, lastmax = -1;
				REP(k,0,pos[i].size()) {
					if (small == pos[i][k] && firstmin == -1) { // only the first
						firstmin = k;	
					}
					if (big == pos[i][k]) { // until the last
						lastmax = k;
					}
				}

				if (firstmin > lastmax) {
					flex[i] = 1;
				}
			}
		}

		ll ans = width[0] * width[1];

		REP(i,0,2) {
			if (flex[i] && width[i] > 2) {
				ans = min(ans, (width[i] - 1) * width[1-i]);
			}
		}
		cout << ans << endl;
	}
}


signed main() {
	int t;
	cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}