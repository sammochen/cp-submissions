/*
Original problem: https://codeforces.com/problemset/problem/1203/E
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
    	int n, x;
    	cin >> n;
    	map<int, int> freq;
    	REP(i, 0, n) {
    		cin >> x;
    		freq[x]++;
    	}

    	int ans = 0;
    	REP(i, 1, 150002) {
    		if (freq[i - 1] >= 1) {
    			freq[i - 1]--;
    			ans++;
    		} else if (freq[i] >= 1) {
    			freq[i]--;
    			ans++;
    		} else if (freq[i + 1] >= 1) {
    			freq[i + 1]--;
    			ans++;

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