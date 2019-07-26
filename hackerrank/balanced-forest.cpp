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

const ll INF = 1e18 + 5;

namespace SOLVE {
	ll n, a, b;
	VLL values;
	VLL subtree; // stores the value of the subtree
	vector<VLL> E;
	map<ll, ll> otherbranch;
	map<ll, ll> thisbranch;
	stack<ll> st;

	ll total;
	ll ans;

	void init() {
		ans = INF;
		total = 0;

		values.clear();
		values.resize(n + 1);

		E.clear();
		E.resize(n + 1);

		subtree.clear();
		subtree.resize(n + 1);

		otherbranch.clear();

		thisbranch.clear();
	}

	// Preprocess subtree[i] for all i
	void fillsubtree(int v, int prev) {
		ll t = values[v];
		for (int e : E[v]) {
			if (e != prev) {
				fillsubtree(e, v);
				t += subtree[e];
			}
		}
		subtree[v] = t;
	}

	void dfs(int v, int prev) {
		// For every v, check this branch and other branches for other values that could be part of the triplet.
		// Have to account for all three combinations, as well as same/diff branch

		// notation: ABc, A == B, c < A.
		ll A, B, c;
		ll sub = subtree[v];

		// this is A, look for B
		A = sub, B = sub, c = total - A - B;

		if (otherbranch[B] >= 1 && c <= A) {
			ans = min(ans, A - c);
		}
		if (thisbranch[A + B] >= 1 && c <= A) {
			ans = min(ans, A - c);
		}

		// this is A, look for c
		if (otherbranch[c] >= 1 && c <= A) {
			ans = min(ans, A - c);
		}
		if (thisbranch[A + c] >= 1 && c <= A) {
			ans = min(ans, A - c);
		}

		// this is c, look for A
		if ((total - sub) % 2 == 0) {
			c = sub, A = (total - sub) / 2, B = A;
			if (otherbranch[A] >= 1 && c <= A) {
				ans = min(ans, A - c);
			}
			if (thisbranch[A + c] >= 1 && c <= A) {
				ans = min(ans, A - c);
			}
		}

		// Ensures that 'thisbranch' only contains values from v to the root
		thisbranch[sub] ++;
		st.push(sub);

		for (int e : E[v]) {
			if (e != prev) {
				dfs(e, v);
			}
		}

		// If v has been explored, take it off thisbranch and add to otherbranch. 
		// We can use the stack to keep track 
		thisbranch[st.top()]--;
		otherbranch[st.top()]++;
		st.pop();
	}


	void main() {
		cin >> n;
		init();

		REP(i, 0, n) {
			cin >> values[i + 1];
			total += values[i + 1];
		}

		REP(i, 0, n - 1) {
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}

		fillsubtree(1, 0);
		dfs(1, 0);

		if (ans != INF) {
			cout << ans << endl;
		}
		else {
			cout << "-1" << endl;
		}

	}
}


signed main() {
	int t;
	cin >> t;
	while (t--) {
		SOLVE::main();

	}


	return 0;
}
