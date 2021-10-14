// clang-format off

#ifdef SAM
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define fe(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define lg(x) (ll)x.length()
#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pqueue priority_queue

struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

// clang-format on

struct tnode {
    tnode* children[26];
    ll endofword;
};

tnode* root;

void insert(const string& key) {
    tnode* cur = root;
    rep(i, 0, key.length()) {
        ll index = key[i] - '0';
        if (!cur->children[index]) {
            cur->children[index] = new tnode();
        }
        cur = cur->children[index];
    }

    // mark last node as leaf
    cur->endofword = 1;
}

string add(const string& a, const string& b) {
    ll n = max(lg(a), lg(b));
    ll carry = 0;
    string res;
    for (ll i = 0; i < n || carry != 0; i++) {
        ll x = i < lg(a) ? a[i] - '0' : 0;
        ll y = i < lg(b) ? b[i] - '0' : 0;
        ll v = x + y + carry;
        res.pb((v % 10) + '0');
        carry = v / 10;
    }
    return res;
}

void init() {
    root = new tnode();

    string s = "1";
    rep(i, 0, 801) {
        string t = s;
        reverse(all(t));

        insert(t);

        s = add(s, s);
    }
}

void solve() {
    string s;
    cin >> s;

    ll ans = 0;
    rep(i, 0, lg(s)) {
        tnode* cur = root;
        rep(j, i, lg(s) + 5) {
            ans += cur->endofword;

            if (j >= lg(s)) break;
            ll index = s[j] - '0';
            if (!cur->children[index]) break;

            cur = cur->children[index];
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();

    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}