/*
Original problem: https://atcoder.jp/contests/abc137/tasks/abc137_c
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

const ll mod = 1e9+7;

namespace SOLVE {
    void main() {
        int n;
		cin >> n;
		map<VI,ll> cnt;

		string s;
		ll ans = 0;
		REP(i,0,n){
			cin >> s;
			VI f(26);
			for (char c : s) {
				f[c - 'a']++;
			}
			ans += (cnt[f]);
			cnt[f]++;
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