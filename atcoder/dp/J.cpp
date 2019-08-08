/*
Original problem: https://atcoder.jp/contests/dp/tasks/dp_j
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

namespace SOLVE {
	const int nax = 305;
	double E[nax][nax][nax] = {0};
	double P[nax][nax][nax] = {0};

	void main() {
		int n, temp;
		int count[4] = {0};
		cin >> n;

		REP(i, 0, n) {
			cin >> temp;
			count[temp]++;
		}

		P[count[1]][count[2]][count[3]] = 1; // the probability moves to get to this state
		E[count[1]][count[2]][count[3]] = 0; // the expected value - a little redundant

		RREP(f3, n, 0) {
			RREP(f2, n, 0) {
				RREP(f1, n, 0) {
					if (f1 + f2 + f3 == 0) {
						// no more transitions - complete
						break;
					}

					// there is a probability that nothing happens: Pwaste
					// i want to find the p-bility and ev that nothing happens

					// p[waste] + p[waste]^2 + p[waste]^3 ... = S
					// S / p[waste] = S + 1
					// S = (1 - p[waste]) / p[waste]

					// E[waste] = 1 / S + 1

					double useful = f1 + f2 + f3;
					double Pwaste = 1 - (useful / n);
					double Ewaste = Pwaste / (1 - Pwaste) + 1;

					// the expected value of a state has to include the transition to itself
					E[f1][f2][f3] += Ewaste * P[f1][f2][f3];

					// now that we have considered the self-transitions, we consider useful instead of n
					if (f1 != 0) {
						E[f1 - 1][f2][f3] += E[f1][f2][f3] * (f1 / useful);
						P[f1 - 1][f2][f3] += P[f1][f2][f3] * (f1 / useful);
					}
					if (f2 != 0) {
						E[f1 + 1][f2 - 1][f3] += E[f1][f2][f3] * (f2 / useful);
						P[f1 + 1][f2 - 1][f3] += P[f1][f2][f3] * (f2 / useful);
					}
					if (f3 != 0) {
						E[f1][f2 + 1][f3 - 1] += E[f1][f2][f3] * (f3 / useful);
						P[f1][f2 + 1][f3 - 1] += P[f1][f2][f3] * (f3 / useful);
					}

				}
			}
		}
		cout << setprecision(20) << E[0][0][0] << endl;
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