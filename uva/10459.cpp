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


const ll inf = 1e9+7;
namespace SOLVE {	
    pair<VLL, ll> bfs(VVLL & E, ll s) {
		VLL d(E.size(), inf);
        d[s] = 0;
        queue<ll> Q;
        Q.push(s);
        ll maxd = 0;
        while (Q.size()) {
            ll at = Q.front();
            maxd = max(d[at], maxd);
            Q.pop();

            for (ll to : E[at]) {
                if (d[to] == inf) {
                    d[to] = d[at] + 1;
                    Q.push(to);
                }
            }
        }
		return {d, maxd};
	}

	void main() {
		ll n;
        while (cin >> n) {
            VVLL E(n+1);
            REP(i,1,n+1) {
                ll x;
                cin >> x;
                REP(j,0,x) {
                    ll y;
                    cin >> y;
                    E[i].push_back(y);
                }

            }
            // find the "center"
            // find all with deg 1
            VLL deg(n+1);
            queue<ll> Q;
            ll count = 0;
            
            REP(i,1,n+1) {
                deg[i] = E[i].size();
                if (deg[i] == 1) {
                    Q.push(i);
                }
            }

            while (count + Q.size() != n) {
                queue<ll> nextQ;
                while (Q.size()) {
                    ll at = Q.front();
                    Q.pop();
                    count++;

                    for (ll to : E[at]) {
                        deg[to]--;
                        if (deg[to] == 1) {
                            nextQ.push(to);
                        }
                    }
                }
                Q = nextQ;
            }

            VLL best;
            while (Q.size()) {
                best.push_back(Q.front());
                Q.pop();
            }

            VLL worst;
            if (best.size() == 1) {
                // needs to be farthest
                pair<VLL, ll> ans = bfs(E, best[0]);
                REP(i,1,n+1) {
                    if (ans.first[i] == ans.second) worst.push_back(i);
                }
            } else {
                pair<VLL, ll> ans1 = bfs(E, best[0]);
                pair<VLL, ll> ans2 = bfs(E, best[1]);
                REP(i,1,n+1) {
                    if (ans1.first[i] >= ans1.second - 1 && ans2.first[i] >= ans2.second - 1) worst.push_back(i);
                }
            }

            sort(best.begin(), best.end());

            printf("Best Roots  :");
            for (ll x : best) printf(" %lld", x);
            printf("\n");

            sort(worst.begin(), worst.end());

            printf("Worst Roots :");
            for (ll x : worst) printf(" %lld", x);
            printf("\n");
        }
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
