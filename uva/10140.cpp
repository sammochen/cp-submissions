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

ll nax = 1005;
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

ll isprime(ll x) {
    if (x < nax*nax) return p[x];
    REP(i,0,P.size()) {
        if (x % P[i] == 0) return 0;
        if (P[i] * P[i] > x) break;
    }
    return 1;
}


void solve() {
    ll L, U;
    while (cin >> L >> U) {
        ll small = inf, big = -inf;
        PLL smallans, bigans;
        ll prev = -1;
        REP(i,L,U+1) {
            if (isprime(i)) {
                if (prev != -1) {
                    if (i - prev < small) {
                        small = i-prev;
                        smallans = {prev, i};
                    } 
                    if (i - prev > big) {
                        big = i-prev;
                        bigans = {prev, i};
                    }
                }
                prev = i;
            }
        }

        if (small == inf) {
            cout << "There are no adjacent primes." << endl;
        } else {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", smallans.first, smallans.second, bigans.first, bigans.second);
        }
    }
}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}