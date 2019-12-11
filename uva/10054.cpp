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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

namespace SOLVE {	
    ll test = 1;
    VLL p(51); 

	ll getp(ll x) {
		if (p[x] == x) return x;
		p[x] = getp(p[x]);
		return p[x];
	}

	void merge(ll a, ll b) {
		p[getp(a)] = getp(b);
	}

	ll same(ll a, ll b) {
		return getp(a) == getp(b);
	}

    void dfs(ll at, VVLL & E) {
        REP(to,0,E.size()) {
            if (E[at][to]) {
                E[at][to]--;
                E[to][at]--;
                dfs(to, E);
                printf("%lld %lld\n", to, at);
            }
        }
    }

	void main() {
        if (test != 1) printf("\n");
        printf("Case #%lld\n", test++);

		ll n = 51, m, s, flag = 0;
        in(m);

        REP(i,0,n) p[i] = i;
        VLL deg(n);
       
        VVLL E(n, VLL(n)); // adjmatrix
        REP(i,0,m) {
            ll a, b;
            in(a,b);
            s = a;

            E[a][b]++;
            E[b][a]++;
            deg[a]++;
            deg[b]++;
            merge(a,b);
        }

        REP(i,0,n) {
            if (deg[i] & 1) {
                flag = 1;
            }
            if (deg[i] != 0 && !same(s,i)) {
                flag = 1;
            }
        }

        if (flag) {
            printf("some beads may be lost\n");
            return;
        }
        
        dfs(s, E);

	}
}


signed main() {
	ll t;
	t = 1;
    in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
