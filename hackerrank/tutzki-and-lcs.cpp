// clang-format off

#include <bits/stdc++.h>

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

	void show() {cerr << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cerr << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cerr << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
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
template<typename A> A reversed(const A & a) { A b = a; reverse(all(b)); return b; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5, 1000000207};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

// clang-format on

const ll nax = 5000 + 50;
const ll buf = 10;

ll up[nax][nax] = {0};
ll down[nax][nax] = {0};
ll n, m;
string s, t;

void solve() {
    cin >> s >> t;
    n = lg(s);
    m = lg(t);

    // solve bottom up and stuff

    rrep(i, n - 1, 0) {
        rrep(j, m - 1, 0) {
            up[i + buf][j + buf] =
                max(up[i + 1 + buf][j + buf], up[i + buf][j + 1 + buf]);
            if (s[i] == t[j])
                upmax(up[i + buf][j + buf], up[i + 1 + buf][j + 1 + buf] + 1);
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            down[i + buf][j + buf] =
                max(down[i - 1 + buf][j + buf], down[i + buf][j - 1 + buf]);
            if (s[i] == t[j])
                upmax(down[i + buf][j + buf],
                      down[i - 1 + buf][j - 1 + buf] + 1);
        }
    }

    ll ans = 0;
    rep(i, 0, n + 1) {
        VLL goods(256);
        ll goodcnt = 0;
        rep(j, 0, m) {
            // can we insert character t[j] between s at i?
            if (up[i + buf][j + buf] == up[i + buf][j + 1 + buf]) {
                if (down[i - 1 + buf][j + buf] ==
                    down[i - 1 + buf][j - 1 + buf]) {
                    if (up[i + buf][j + 1 + buf] +
                            down[i - 1 + buf][j - 1 + buf] ==
                        up[0 + buf][0 + buf]) {
                        if (!goods[t[j]]) {
                            goods[t[j]] = 1;
                            goodcnt++;
                        }
                    }
                }
            }
        }
        ans += goodcnt;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}