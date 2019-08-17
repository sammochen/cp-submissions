/*
Original problem: https://atcoder.jp/contests/abc137/tasks/abc137_d
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
	struct job {
		ll t, v;
		job(ll a, ll b) {
			t = a, v = b;
		}
	};

	struct sortjob {
		// sort by value, then by time
		bool operator()(job & a, job & b) {
			if (a.v == b.v) {
				return a.t > b.t;
			}
			return a.v > b.v;
		}
	};

	VLL value(100005); // value[i] is the value of the job, days counts down from m to 0
	VLL next(100005, -1); // points to the next lower day

	// dsu ideas
	int nextday(int x) {
		if (next[x] == -1) {return -1;} // if parent is -1, x is also -1
		if (next[x] == x) {return x;} // otherwise return parent
		next[x] = nextday(next[x]);
		return next[x];
	}

    void main() {
    	ll n, m, a, b;
    	cin >> n >> m;
    	vector<job> J(n, job(-1, -1));

    	REP(i, 0, n) {
    		cin >> a >> b;
    		J[i] = job(a, b);
    	}
		// treat the jobs in priority 
    	sort(J.begin(), J.end(), sortjob());

    	// set up next: from 0->m it is itself, rest is -1 (inv)
    	REP(i, 0, m + 1) {
    		next[i] = i;
    	}

    	for (job j: J) {
    		int day = nextday(j.t); // next available day for the job to 'fit' in
    		if (day == -1) { // this job cannot fit
    			continue;
    		}

    		value[day] = j.v; 
    		next[day] = day + 1; // day is now not free
    	}

		// add all values
    	ll ans = 0;
    	REP(i, 0, m + 1) {
    		ans += value[i];
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