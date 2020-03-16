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

string left(string s) {
    return s+"V";
}
string right(string s) {
    return "V" + s.substr(0,s.length()-1);
}

ll todec(char c) {
    if (c == 'V') return 0;
    if (c == 'U') return 1;
    if (c == 'C') return 2;
    return 3;
}

ll todec(string s) {
    if (s == "") return 0;
    return todec(s.substr(0,s.length()-1)) * 4 + todec(s[s.length()-1]);
}

string tocow(ll v) {
    if (v == 0) return "";
    string cow = "VUCD";
    return tocow(v/4) + to_string(cow[v%4]);
}

string add(string a, string b) {
    return tocow(todec(a) + todec(b));
}
void solve() {
    string num1, num2, res;
    vector<string> op(3);
    cin >> num1 >> num2 >> op[0] >> op[1] >> op[2] >> res;

    REP(i,0,3) {
        if (op[i] == "A") {
            num2 = add(num1, num2);
        } else if (op[i] == "R") {
            num2 = right(num2);
        } else if (op[i] == "L") {
            num2 = left(num2);
        }
    }
    string ans = string(8-num2.length(), 'V') + num2;
    if (ans == res) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main() {
    cout << "COWCULATIONS OUTPUT" << endl;
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
    cout << "END OF OUTPUT" << endl;
	return 0;
}