#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

ll nax = 200;
VLL p(nax*nax, 1);
VLL P;

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

vector<PLL> factor(ll n) {
    vector<PLL> ans;
    ll ptr = 0;
    while (n != 1 && ptr < P.size()) {
        if (n % P[ptr] == 0) {
            ans.push_back({P[ptr], 1});
            n /= P[ptr];
        }

        while (n % P[ptr] == 0) {
            ans[ans.size()-1].second++;
            n /= P[ptr];
        }
        ptr++;
    }
    if (n != 1) ans.push_back({n,1});
    return ans;
}

void solve() {
    string s;
    while (getline(cin, s), s != "0") {
        stringstream ss;
        ss << s;
        VLL A;
        ll x;
        while (ss >> x) A.push_back(x);
        ll n = 1;
        for (ll i = 0; i < A.size(); i+=2) {
            n *= pow(A[i], A[i+1]);
        }
        vector<PLL> ans = factor(n-1);
        sort(ans.rbegin(), ans.rend());
        REP(i,0,ans.size()) {
            cout << ans[i].first << ' ' << ans[i].second;
            if (i == ans.size() - 1) cout << endl;
            else cout << ' ';
        }
    }
}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}