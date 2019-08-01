/*
Original problem: https://www.hackerrank.com/challenges/poisonous-plants
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	void main() {
		// imagine: a number can be a killer if it is smaller than the one on the right
		// a number can only kill as many numbers as many days it can live
		// a number could be unkillable: i will use inf
		// therefore: i need to track (for every number) days it can live, kills it has made so far and who killed it

		int n, ans = 0;
		int inf = 1e9 + 7;
		cin >> n;
		VI A(n);
		VI days(n, inf); // days[i] is in how many days plant i will die, inf if never
		VI killer(n, inf); // killer[i] is who killed plant i, inf if never
		VI kills(n, 0); // kills[i] is how many kills it makes

		REP(i, 0, n) {
			cin >> A[i];
		}

		// start from 1: 0 is default unkillable since there are no killers before it
		REP(i, 1, n) {
			// look for the killer! start looking from the i-1's killer
			// if k is not its killer, the next 'suspect' is who killed k, since all numbers from killer[k] + 1 to k - 2 is invalid
			for (int k = i - 1; k != inf; k = killer[k]) {
				if (A[k] < A[i] && kills[k] < days[k]) {
					killer[i] = k;
					days[i] = kills[k] + 1;
					kills[k]++;

					// ans is the max number of days needed
					ans = max(ans, days[i]);
					break;
				}
			}
		}

		cout << ans << endl;
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