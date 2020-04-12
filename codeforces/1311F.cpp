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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

#define lsb(i) ((i)&-(i))

const ll nax = 2e5 + 10;
ll arr[nax];

void add(ll i, ll k) {
    while (i < nax) {
        arr[i] += k;
        i += lsb(i);
    }
}

ll sum(ll i) {
    ll total = 0;
    while (i > 0) {
        total += arr[i];
        i -= lsb(i);
    }
    return total;
}

void solve() {
    memset(arr,0,sizeof(arr));
    ll n;
	cin >> n;
	vector<PLL> A(n);
	REP(i,0,n) cin >> A[i].first;
	REP(i,0,n) cin >> A[i].second;

	sort(A.begin(), A.end());

	// compress the speeds
	set<ll> speed;
	REP(i,0,n) speed.insert(A[i].second);

	map<ll,ll> M;
	ll id = 1;
	for (ll s : speed) {
		M[s] = id++;
	}

	REP(i,0,n) A[i].second = M[A[i].second];

	ll ans = 0;
	// going up
	REP(i,0,n) {
		// check how many its bigger or equal to
		ll bigger = sum(A[i].second);
		ans += bigger * A[i].first;
		add(A[i].second, 1);
	}

	memset(arr,0,sizeof(arr));
	RREP(i,n-1,0) {
		ll smaller = (n-1-i) - sum(A[i].second - 1);
		ans -= smaller * A[i].first;
		add(A[i].second, 1);
	}
	cout << ans << endl;

    
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}