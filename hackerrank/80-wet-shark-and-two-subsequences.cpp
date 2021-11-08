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

ll dp[105][105][2005];
ll A[105];
ll n, r, s;

ll get(ll ind, ll cnt, ll sum) {
    if (ind == n && sum == 0 && cnt == 0) {
        return 1;
    }
    if (sum < 0) return 0;
    if (cnt < 0) return 0;
    if (ind >= n) return 0;

    ll& ans = dp[ind][cnt][sum];
    if (ans != -1) return ans;

    ans = 0;
    ans += get(ind + 1, cnt - 1, sum - A[ind]);
    ans += get(ind + 1, cnt, sum);
    ans %= mod;
    return ans;
}

void solve() {
    cin >> n >> r >> s;
    rep(i, 0, n) {
        cin >> A[i];
    }

    if ((r + s) % 2) {
        cout << 0 << endl;
        return;
    }

    mst(dp, -1);

    ll one = (r + s) / 2;
    ll two = (r - s) / 2;
    ll ans = 0;
    rep(i, 1, n + 1) {
        ll cur1 = get(0, i, one);
        ll cur2 = get(0, i, two);

        ans += cur1 * cur2 % mod;
        ans %= mod;
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