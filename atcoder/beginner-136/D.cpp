/*
Original problem: https://atcoder.jp/contests/abc136/tasks/abc136_d
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
        string s;
		cin >> s;
		VI ans(s.size());
		// count R streaks
		int l = 1; // length
		REP(i,1,s.size()){
			if (s[i] == 'L' && s[i] != s[i-1]) {
				ans[i] += l/2;
				ans[i-1] += l - l/2;
			}
			if (s[i] == 'R' && s[i] != s[i-1]) {
				l = 1;
			}
			if (s[i] == 'R' && s[i] == s[i-1]) {
				l++;
			}
		}

		// L streaks
		l = 1;
		RREP(i,(int)s.size() - 2,0){
			if (s[i] == 'R' && s[i] != s[i+1]) {
				ans[i] += l/2;
				ans[i+1] += l - l/2;
			}
			if (s[i] == 'L' && s[i] != s[i+1]) {
				l = 1;
			}
			if (s[i] == 'L' && s[i] == s[i+1]) {
				l++;
			}
		}
		REP(i,0,s.size()) {
			cout << ans[i];
			if (i == s.size() - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}

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