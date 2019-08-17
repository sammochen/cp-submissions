/*
Original problem: https://atcoder.jp/contests/abc134/tasks/abc134_e
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
        int n, temp;
		cin >> n;
		multiset<int> s;
		multiset<int>::iterator itr; 
		// keep the ends of the lists - add to the next smallest one

		REP(i,0,n) {
			cin >> temp;
			// finds the first number that is >= temp and find the next smallest
			itr = s.lower_bound(temp);
			
			// if it is begin, temp is too small
			if (itr == s.begin()) {
				s.insert(temp);
			} else {
				// replace
				itr--;
				s.erase(itr);
				s.insert(temp);
			}
		}
		cout << s.size() << endl;
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