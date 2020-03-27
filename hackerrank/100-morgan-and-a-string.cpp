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

void solve() {
    string s, t;
    cin >> s >> t;
    ll n = s.length(), m = t.length();
    s.push_back('z');
    t.push_back('z');

    string ans;
    // two pointers
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] < t[j]) {
            ans.push_back(s[i]);
            i++;
        } else if (s[i] > t[j]) {
            ans.push_back(t[j]);
            j++;
        } else {
            // case where the first letter changes
            string same;
            ll ii = i, jj = j;

            // while they are both the same
            while (ii < n && jj < m && s[ii] == t[jj]) {
                same.push_back(s[ii]);
                ii++;
                jj++;
            }

            // i check which one is smaller, and grab the most valid substr (has to be non-increasing)
            string add = to_string(same[0]);

            REP(i,1,same.length()) {
                if (same[i] > same[i-1]) break;
                add.push_back(same[i]);
            }
            
            ans += add;

            // move the pointer that is the best up to that point
            if (s[ii] < t[jj]) {
                i += add.length();
            } else {
                j += add.length();
            }
        }
    }

    while (i < n) {
        ans.push_back(s[i]);
        i++;
    }

    while (j < m) {
        ans.push_back(t[j]);
        j++;
    }
    cout << ans << endl;
}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}