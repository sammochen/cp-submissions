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

// maps values to 0-based id
struct Mapper {
    ll cur = 1;
    umap<ll, ll> to;

    ll get(ll x) {
        if (to.find(x) == to.end()) {
            to[x] = cur;
            cur++;
        }
        return to[x];
    }
};

Mapper mapper;

// max 5 * 9
uset<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll isprime(ll x) {
    return primes.find(x) != primes.end();
}

const ll N = 400050;
const ll M = 57;
ll dp[N][M];

VLL nextE[10][10][10][10];

void initNextE() {
    rep(a, 0, 10) {
        rep(b, 0, 10) {
            rep(c, 0, 10) {
                if (!isprime(a + b + c)) continue;
                rep(d, 0, 10) {
                    if (!isprime(b + c + d) || !isprime(a + b + c + d))
                        continue;
                    rep(e, 0, 10) {
                        if (!isprime(c + d + e) || !isprime(b + c + d + e) ||
                            !isprime(a + b + c + d + e))
                            continue;
                        nextE[a][b][c][d].pb(e);
                    }
                }
            }
        }
    }
}

void dummy(ll a, ll b, ll c, ll d, ll steps, set<VLL>& vis) {
    // The dummy shows that after steps >= 3, the same ~60 states get visited
    if (steps >= 3) {
        VLL cur = {a, b, c, d};
        if (vis.find(cur) != vis.end()) return;
        vis.insert(cur);
    }

    fe(e, nextE[a][b][c][d]) {
        dummy(b, c, d, e, steps + 1, vis);
    }
}

VVLL getGoods(VVLL& starts) {
    set<VLL> vis;

    fe(start, starts) {
        dummy(start[0], start[1], start[2], start[3], 0, vis);
    }

    debug(sz(vis));
    VVLL ans(all(vis));
    return ans;
}

ll beforeDP(ll a, ll b, ll c, ll d, ll n, const map<VLL, ll>& goodind) {
    // before dp will brute force recurse until a dp solution
    if (n == 4) return 1;
    if (n < 4) return 0;

    const VLL cur = {a, b, c, d};
    const auto& it = goodind.find(cur);
    if (it != goodind.end()) {
        ll res = dp[n][it->second];
        return res;
    }

    ll ans = 0;
    fe(e, nextE[a][b][c][d]) {
        ans += beforeDP(b, c, d, e, n - 1, goodind);
        ans %= mod;
    }
    return ans;
}

void solve() {
    initNextE();
    mst(dp, -1);
    ll q;
    scanf("%lld", &q);

    // to fill in the table
    VVLL starts;
    rep(a, 1, 10) {
        rep(b, 0, 10) {
            rep(c, 0, 10) {
                if (!isprime(a + b + c)) continue;
                rep(d, 0, 10) {
                    if (isprime(b + c + d) && isprime(a + b + c + d)) {
                        starts.pb({a, b, c, d});
                    }
                }
            }
        }
    }

    VVLL goods = getGoods(starts);  // the goods are the 60~ most common
    map<VLL, ll> goodind;
    VVLL goodadj(goods.size());

    // set index
    rep(i, 0, goods.size()) {
        goodind[goods[i]] = i;
    }

    // adj
    rep(i, 0, goods.size()) {
        ll a = goods[i][0], b = goods[i][1], c = goods[i][2], d = goods[i][3];
        fe(e, nextE[a][b][c][d]) {
            VLL after = {b, c, d, e};
            if (goodind.find(after) != goodind.end()) {
                goodadj[i].pb(goodind[after]);
            }
        }
    }

    VLL Q(q);
    ll biggest = -1;
    rep(i, 0, q) {
        scanf("%lld", &Q[i]);
        upmax(biggest, Q[i]);
    }

    // bottom up dp
    rep(i, 0, biggest + 5) {
        rep(j, 0, sz(goods)) {
            if (i < 4)
                dp[i][j] = 0;
            else if (i == 4)
                dp[i][j] = 1;
            else {
                dp[i][j] = 0;
                fe(to, goodadj[j]) {
                    dp[i][j] += dp[i - 1][to];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    VLL bf = {0, 9, 90, 303, 280};

    fe(n, Q) {
        if (n < bf.size()) {
            printf("%lld\n", bf[n]);
        } else {
            // I can start with any 4 digit
            ll ans = 0;
            fe(start, starts) {
                ll cur = beforeDP(start[0], start[1], start[2], start[3], n,
                                  goodind);
                ans += cur;
                ans %= mod;
            }
            printf("%lld\n", ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}