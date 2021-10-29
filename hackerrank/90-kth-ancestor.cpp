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
ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(const string & from) { vector<string> ans; stringstream ss(from); string s; while (ss >> s) {ans.pb(s);} return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;    ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {    return x > 0 ? 1 : x < 0 ? -1 : 0; }
template<typename A> A reversed(const A & a) { A b = a; reverse(all(b)); return b; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5, 1000000207};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;

// clang-format on

const ll N = 1e5 + 5, K = 18;
ll dp[N][K];

void solve() {
    mst(dp, 0);

    ll n;
    cin >> n;

    rep(_, 0, n) {
        ll x, y;
        cin >> x >> y;
        dp[x][0] = y;
    }

    rep(j, 1, K) {
        rep(i, 0, N) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    ll q;
    cin >> q;
    rep(_, 0, q) {
        ll type;
        cin >> type;
        if (type == 0) {
            // add x, and x's parent is y
            ll x, y;
            cin >> y >> x;

            dp[x][0] = y;
            rep(j, 1, K) {
                dp[x][j] = dp[dp[x][j - 1]][j - 1];
            }
        } else if (type == 1) {
            // remove
            ll x;
            cin >> x;

            rep(j, 0, K) {
                dp[x][j] = 0;
            }
        } else if (type == 2) {
            ll x, k;
            cin >> x >> k;

            ll cur = x;

            rep(j, 0, K) {
                if (tp(j) & k) {
                    cur = dp[cur][j];
                }
                if (k == 0) break;
            }
            cout << cur << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}