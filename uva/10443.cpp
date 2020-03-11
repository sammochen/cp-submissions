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

ll n, m, k;

char lose(char c) {
    if (c == 'R') return 'S';
    if (c == 'S') return 'P';
    return 'R';
}

vector<string> next(vector<string> A) {
    VLL di = {0,0,1,-1};
    VLL dj = {1,-1,0,0};
    vector<string> B = A;
    REP(i,0,n) {
        REP(j,0,m) {
            REP(x,0,4) {
                ll ii = i + di[x];
                ll jj = j + dj[x];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if (A[ii][jj] == lose(A[i][j])) B[ii][jj] = A[i][j];
            }
        }
    }

    return B;
}

ll first = 1;
void solve() {
    if (!first) cout << endl;
    first = 0;
    
    cin >> n >> m >> k;
    vector<string> A(n);
    REP(i,0,n) cin >> A[i];

    REP(i,0,k) {
        A = next(A);
    }

    REP(i,0,n) {
        cout << A[i] << endl;
    }


}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}