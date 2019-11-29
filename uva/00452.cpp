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
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll inf = 1e18;

namespace SOLVE {	
	VLL times(26);
	vector<string> depend(26);
	VLL dp(26, -1);
	VLL A;

	ll get(ll i) {
		if (dp[i] != -1) return dp[i];
		ll ans = 0;
		for (char c : depend[i]) {
			ans = max(ans, get(c - 'A'));
		}
		ans += times[i];
		dp[i] = ans;
		return ans;
	}

	ll f = 1;

	void process() {
		if (!f) cout << endl;
		f = 0;

		ll ans = 0;
		REP(i,0,A.size()) {
			ans = max(ans, get(A[i]));
		}
		cout << ans << endl;

		A.clear();
		dp.clear();
		dp.resize(26, -1);
		depend.clear();
		depend.resize(26);
		times.clear();
		times.resize(26);
	}

	void main() {
		string s;
		getline(cin, s);
		getline(cin, s);

		A.clear();
		dp.clear();
		dp.resize(26, -1);

		while (getline(cin,s)) {
			if (s == "") {
				process();
				continue;
			}

			stringstream ss;
			ss << s;
			char c;
			ss >> c;
			ll i = c - 'A';
			ll time;
			ss >> time;
			times[i] = time;
			string d = "";
			if (ss >> d) {
			}

			depend[i] = d;
			A.push_back(i);
		}

		process();
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
