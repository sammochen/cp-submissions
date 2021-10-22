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

namespace Timer {
chrono::high_resolution_clock::time_point prev;
void start() {
    prev = chrono::high_resolution_clock::now();
}
void stop() {
    auto cur = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = cur - prev;
    string time = to_string(ms.count()) + "ms";
    debug(time);
}
};  // namespace Timer

const ll nax = 3e4 + 20;

namespace SA {

ll L[nax][3], tempL[nax][3];
ll P[nax];
ll cnt[nax];  // counts the number of elements in each bucket

void radix(const ll n, const ll ind, ll from[][3], ll to[][3]) {
    const ll buckets = max(n, 256LL) + 2;
    // reset
    rep(i, 0, buckets + 5) cnt[i] = 0;

    // count the number of each element
    rep(i, 0, n) {
        cnt[from[i][ind] + 1]++;  // +1 bc we also have -1
    }

    // finds the cumulative number of elements
    rep(i, 1, buckets) cnt[i] += cnt[i - 1];

    // stable sort
    rrep(i, n - 1, 0) {
        cnt[from[i][ind] + 1]--;
        rep(j, 0, 3) to[cnt[from[i][ind] + 1]][j] = from[i][j];
    }
}

void buildSA(const string& s, ll sa[], ll ind[]) {
    ll n = lg(s);
    ll k = log2(n) + 2;

    rep(i, 0, n) {
        P[i] = s[i];  // initial rank is the character string is
    }

    rep(i, 1, k) {
        rep(j, 0, n) {
            ll nextj = j + tp(i - 1);

            ll first = P[j];
            // empty strings come first in lexicographic order
            ll second = nextj < n ? P[nextj] : -1;

            L[j][0] = first;
            L[j][1] = second;
            L[j][2] = j;
        }

        radix(n, 1, L, tempL);
        radix(n, 0, tempL, L);

        rep(j, 0, n) {
            // If the strings are the same, then your rank is the same as
            // the previous
            P[L[j][2]] =
                j > 0 && L[j - 1][0] == L[j][0] && L[j - 1][1] == L[j][1]
                    ? P[L[j - 1][2]]
                    : j;
        }
    }

    rep(i, 0, n) {
        sa[P[i]] = i;
    }
    rep(i, 0, n) {
        ind[sa[i]] = i;
    }
}

void buildLCP(const string& s, ll sa[], ll ind[], ll lcp[]) {
    // ! assumes sa has already been found

    // kasai's algorithm, find lcp
    // uses the idea that lcp[i+1] will be at least lcp[i] - 1
    ll n = lg(s);
    rep(i, 0, n) lcp[i] = 0;

    ll res = 0;
    rep(i, 0, n - 1) {
        ll index = ind[i] - 1;
        if (index < 0) continue;
        ll j = sa[index];

        rep(k, res, n + 5) {
            if (i + k < n && j + k < n && s[i + k] == s[j + k])
                res++;
            else
                break;
        }
        lcp[index] = res;

        if (res) res--;
    }
}
};  // namespace SA

#define lson (ind << 1)
#define rson (ind << 1 | 1)

// min tree
struct SegTree {
    struct node {
        ll l, r, v;
    };

    node no[nax * 4];

    void push_up(ll ind) {
        no[ind].v = min(no[lson].v, no[rson].v);
    }
    void push_down(ll ind) {}

    void build(ll l, ll r, ll ind, ll A[]) {
        no[ind].l = l;
        no[ind].r = r;
        if (l == r) {
            // do something
            no[ind].v = A[l];
        } else {
            ll mid = (l + r) / 2;
            build(l, mid, lson, A);
            build(mid + 1, r, rson, A);
            push_up(ind);
        }
    }

    void update(ll l, ll r, ll ind, ll val) {
        if (l > no[ind].r || r < no[ind].l) return;
        if (l <= no[ind].l && no[ind].r <= r) {
            // do something
        } else {
            push_down(ind);
            update(l, r, lson, val);
            update(l, r, rson, val);
            push_up(ind);
        }
    }

    void query(ll l, ll r, ll ind, ll& ans) {
        if (l > no[ind].r || r < no[ind].l) return;
        if (l <= no[ind].l && no[ind].r <= r) {
            // do something, ans = ?
            upmin(ans, no[ind].v);
        } else {
            push_down(ind);
            query(l, r, lson, ans);
            query(l, r, rson, ans);
            push_up(ind);
        }
    }
};

ll sa[nax], ind[nax], lcp[nax];
SegTree tree, tree2;

ll qlcp(ll lcpi, ll lcpj) {
    if (lcpi == lcpj) return inf;

    if (lcpi > lcpj) swap(lcpi, lcpj);
    ll ans = inf;
    tree.query(lcpi, lcpj - 1, 1, ans);
    return ans;
}

void solve() {
    // Go crazy
    ll n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    SA::buildSA(s, sa, ind);
    SA::buildLCP(s, sa, ind, lcp);

    tree.build(0, n - 2, 1, lcp);  // init tree 1
    tree2.build(0, n - 1, 1, sa);  // init tree 2

    // longest[i] is the largest k such that s[i:i+k] is a substring of s[:i]
    VLL longest(n);
    Timer::start();

    rep(i, 0, n) {
        // i want to find the largest k such that s[i:i+k] is a substring of
        // s[:i]
        ll L = 1, R = n - i;
        ll k = 0;
        while (L <= R) {
            ll M = (L + R) / 2;
            // does s[i:i+k] belong in s[:i]?
            // I will binary search up and down in the LCP list
            // to find the highest and lowest bound such that lcp(i, j) >= k
            // I then find the lowest index here and see if the index is less
            // than i-k Because if it is higher then it overlaps

            ll skew = 100;  // skews heavily towards ind[i] because most times,
                            // its near ind[i]
            ll lowest = ind[i];
            {
                ll LL = 0, RR = ind[i];
                while (LL <= RR) {
                    ll MM = RR - (RR - LL) / skew;
                    if (qlcp(ind[i], MM) >= M) {
                        upmin(lowest, MM);
                        RR = MM - 1;
                    } else {
                        LL = MM + 1;
                    }
                }
            }
            ll highest = ind[i];
            {
                ll LL = ind[i], RR = n - 1;
                while (LL <= RR) {
                    ll MM = LL + (RR - LL) / skew;

                    if (qlcp(ind[i], MM) >= M) {
                        upmax(highest, MM);
                        LL = MM + 1;
                    } else {
                        RR = MM - 1;
                    }
                }
            }

            // cool, i now have the lowest and highest indices
            ll minInd = inf;
            tree2.query(lowest, highest, 1, minInd);

            ll ok = minInd <= (i - M);
            if (ok) {
                upmax(k, M);
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        longest[i] = k;
    }
    Timer::stop();

    VLL dp(n, inf);
    dp[0] = a;
    rep(i, 0, n) {
        if (i + 1 < n) upmin(dp[i + 1], dp[i] + a);
        upmin(dp[min(n - 1, i + longest[i] - 1)], dp[i - 1] + b);
    }
    cout << dp[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}