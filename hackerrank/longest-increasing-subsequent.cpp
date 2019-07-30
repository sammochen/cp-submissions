/*
Original problem: https://www.hackerrank.com/challenges/longest-increasing-subsequent
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
		int n;
		cin >> n;
		VI A(n);

		// there are 3 cases where things have to be done
		// an element is smaller than all the tails: create new list
		// an element is larger than all the tails: append to largest size and create new list
		// an element is in between: find the largest tail that is <= than A[i] and append to that

		VI tail(A.size() + 1); // tail[i] provides the tail element of the list that is size i

		cin >> A[0];
		tail[1] = A[0];
		int maxsize = 1;

		REP(i, 1, n) {
			cin >> A[i];
			// case 1: if the new element is largest than all, add to the largest one
			if (A[i] > tail[maxsize]) {
				tail[++maxsize] = A[i];
			}
			// case 2: if the new element is smallest than all, replace the smallest one
			else if (A[i] < tail[1]) {
				tail[1] = A[i];
			}
			// case 3: in between: find the smallest tail[j] where tail[j] < A[i]
			else {
				// i will do a simple linear scan for now. this uses the fact that tail[j] is strictly increasing
				for (int j = maxsize; j >= 1; j--) {
					if (tail[j] < A[i]) {
						tail[j + 1] = A[i];
						break;
					}
				}
			}
		}

		cout << maxsize << endl;
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