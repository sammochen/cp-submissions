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

ll arrdebug = 10;
struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
  template<typename A> string f(A arr[]) { string s = open; rep(i,0,arrdebug) { if (s != open) { s += sep; } s += f(arr[i]); } s += close; return s; }
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

VLL primes = {2, 3, 5, 7};
ll isprime(ll x) {
    fe(p, primes) if (x == p) return 1;
    return 0;
}

const ll N = 35;
ll A[N][N];
ll pre[N][N];
ll dp[N][N][N][N];

void solve() {
    rep(i, 0, N) {
        pre[i][0] = 0;
        pre[0][i] = 0;
    }

    ll n;
    cin >> n;

    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> A[i][j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            pre[i + 1][j + 1] =
                pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + !isprime(A[i][j]);
        }
    }

    rep(height, 1, n + 1) {
        rep(width, 1, n + 1) {
            rep(i1, 0, n) {
                ll i2 = i1 + height - 1;
                if (i2 >= n) break;

                rep(j1, 0, n) {
                    ll j2 = j1 + width - 1;
                    if (j2 >= n) break;

                    if (width == 1 && height == 1) {
                        dp[i1][j1][i2][j2] = 0;
                        continue;
                    }

                    ll num = pre[i2 + 1][j2 + 1] - pre[i1][j2 + 1] -
                             pre[i2 + 1][j1] + pre[i1][j1];

                    if (num == 0) {  // no nonprimes
                        dp[i1][j1][i2][j2] = 0;
                        continue;
                    }

                    // consider each split

                    // there are at most this many splits
                    ll k = height + width + 2;

                    VLL cnt(k);
                    rep(i, i1, i2) {
                        ll one = dp[i1][j1][i][j2];
                        ll two = dp[i + 1][j1][i2][j2];
                        ll res = one ^ two;
                        if (res < k) {
                            cnt[res] = 1;
                        }
                    }
                    rep(j, j1, j2) {
                        ll one = dp[i1][j1][i2][j];
                        ll two = dp[i1][j + 1][i2][j2];
                        ll res = one ^ two;
                        if (res < k) {
                            cnt[res] = 1;
                        }
                    }

                    rep(i, 0, k) {
                        if (!cnt[i]) {
                            dp[i1][j1][i2][j2] = i;
                            break;
                        }
                    }
                }
            }
        }
    }

    ll res = dp[0][0][n - 1][n - 1];
    if (res == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
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