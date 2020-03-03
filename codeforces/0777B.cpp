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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	ll leastflick(VLL S, VLL M) {
		// obj 1: min flicks. tie or better, if better then get rid of biggest
		ll ans = 0;
		RREP(i,9,0) {
			M[i] += M[i+1];
			if (S[i] > M[i]) {
				ans += S[i] - M[i];
				M[i] = 0;
			} else {
				M[i] -= S[i];
			}
		}
		return ans;
	}
	
	ll mostflick(VLL S, VLL M) {
		ll ans = 0;
		REP(i,0,10) {
			// for every S, if there is a M that is bigger, use it
			ll amount = S[i];
		
			REP(j,i+1,10) {
				if (amount <= 0) {
					break;
				}
				if (M[j] >= amount) {
					M[j] -= amount;
					ans += amount;
					amount = 0;
				} else {
					ans += M[j];
					amount -= M[j];
					M[j] = 0;
				}
			}
		}
		return ans;
	}
		
	void main() {
		ll n;
		cin >> n;
		string s, m;
		cin >> s >> m;
		
		// count s, m freq
		VLL M(11), S(11);
		for (char c : m) {
			M[c - '0']++;
		}
		for (char c : s) {
			S[c - '0']++;
		}
		
		cout << leastflick(S,M) << endl;
		cout << mostflick(S,M) << endl;
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
