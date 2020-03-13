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

ll count(ll x, ll y, ll k, VLL factors) {
    ll ans = 0;
    for (ll f : factors) {
        ll i = f, j = k/f;
        ans += max(0LL, x - f + 1) * max(0LL, y - k/f + 1);
    }
    return ans;
}

map<ll,ll> streaks(VLL & A) {
    map<ll,ll> freq;
    ll streak = 0;
    REP(i,0,A.size()) {
        if (A[i] == 0) {
            if (streak) {
                freq[streak]++;
            }
            streak = 0;
        } else {
            streak++;
        }
    }
    if (streak) freq[streak]++;
    return freq;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    VLL A(n), B(m);
    REP(i,0,n) cin >> A[i];
    REP(i,0,m) cin >> B[i];

    VLL factors;
    for (ll i = 1; i * i <= k; i++) {
        if (k % i == 0) factors.push_back(i);
        if (i*i == k) break;
        if (k % i == 0) factors.push_back(k/i);
    }

    // count streaks of 1s 
    map<ll,ll> nstreak = streaks(A);
    map<ll,ll> mstreak = streaks(B);
    ll ans = 0;
    for (PLL a : nstreak) {
        for (PLL b : mstreak) {
            ans += a.second * b.second * count(a.first, b.first, k, factors);
        }
    }
    cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}