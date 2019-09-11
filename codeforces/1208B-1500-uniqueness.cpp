/*
Original problem: https://codeforces.com/problemset/problem/1208/B
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
    void main() {
		int n;
		cin >> n;
		
		VI A(n);
		REP(i,0,n) cin >> A[i];

		map<int,int> a; // a freq
		
		ll ans = n;
		REP(i,0,n) {
			ans = min(ans, n - i);

			map<int,int> b = a;
			RREP(j,n-1,i) {		
				if (b[A[j]] == 1) {
					break;
				}
				b[A[j]]++;
				ans = min(ans, j - i);
			}

			if (a[A[i]] == 1) {
				break;
			}
			a[A[i]]++;
		}

		cout << ans << endl;
    }
}


signed main() {
	int t;
	t = 1;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
