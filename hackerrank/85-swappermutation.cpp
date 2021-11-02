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

ll debugN = 10;
struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
    template<typename A> string f(A arr[]) { string s = open; rep(i,0,debugN) { if (s != open) { s += sep; } s += f(arr[i]); } s += close; return s; }
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

// clang-format on

const ll N = 2550;
ll inv[N];     // inversions
ll pre[N];     // prefix sum for inv
ll cyc[N];     // cycles
ll tmpcyc[N];  // tmp for cycle

void solve() {
    ll n, k;
    cin >> n >> k;

    // * Learnings!

    // * Swapping two adj elements either increases or decreases the number of
    // * inversions
    // * You can make any k-inversion arr in k swaps
    // * You can also make any j-inversion where j and k have same parity

    // * Swapping any two elements can change the number of cycles, where A[j]
    // * is the next element to go to
    // * Initially, sorted perm has n cycles
    // * If you swap two elements in the same cycle, it breaks it
    // * In k swaps, you can make any arr with [n-k..n] cycles

    // inv
    mst(inv, 0);  // at n = 0
    inv[0] = 1;
    rep(i, 1, n + 1) {
        pre[0] = 0;

        // prefix sum of inv
        rep(j, 0, k + 5) {
            pre[j + 1] = pre[j] + inv[j];
            makemod(pre[j + 1], mod);
        }

        rep(j, 0, k + 1) {
            // inv[j] is sum of j-i+1 .. j
            inv[j] = pre[j + 1] - pre[max(0LL, j - i + 1)];
            makemod(inv[j], mod);
        }
    }

    // cyc
    mst(cyc, 0);  // at n = 1
    cyc[1] = 1;
    rep(i, 2, n + 1) {
        rep(j, 1, n + 1) {
            tmpcyc[j] = cyc[j - 1] + cyc[j] * (i - 1);
            makemod(tmpcyc[j], mod);
        }
        swap(cyc, tmpcyc);
    }

    ll ans1 = 0, ans2 = 0;
    for (ll kk = k; kk >= 0; kk -= 2) {
        ans1 += inv[kk];
    }

    for (ll kk = max(0LL, n - k); kk <= n; kk++) {
        ans2 += cyc[kk];
    }

    cout << ans1 % mod << ' ' << ans2 % mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}