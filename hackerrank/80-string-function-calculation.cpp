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
vector<string> ssplit(const string & s) { vector<string> ans; stringstream ss; ss << s; string t; while (ss >> t) ans.pb(t); return ans; }
void makemod(ll & x, ll m) { x %= m; if (x < 0) {x += m;} }
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

#define lson (ind << 1)
#define rson (ind << 1 | 1)

namespace SA {
/**
 * E.g.
 * s = "banana"
 * 0 banana     5 a
 * 1 anana      3 ana
 * 2 nana    -> 1 anana
 * 3 ana        0 banana
 * 4 na         4 na
 * 5 a          2 nana
 *
 * sa gives the ordering, ind gives the index
 *
 * In this case:
 * sa  = [5,3,1,0,4,2]
 * ind = [3,2,5,1,4,0]
 *
 * lcp gives the LCP between indices IF THEY WERE SORTED
 * lcp = [1,3,0,0,2]
 */
VLL sa, ind, lcp;

void initSA(const string& s) {
    ll n = lg(s);
    ll k = log2(n) + 2;

    // 3 outputs
    sa.assign(n, -1);
    ind.assign(n, -1);  // NOTE n-1
    lcp.assign(n - 1, -1);

    VLL P(n);  // P[i] is a value that indicates the rank
    rep(i, 0, n) {
        P[i] = s[i];  // initial rank is the character string is
    }

    VVLL L(n);  // L[i] is the cumulative sum of P[i] and P[i + next]

    rep(i, 1, k) {
        rep(j, 0, n) {
            ll nextj = j + tp(i - 1);

            ll first = P[j];
            // empty strings come first in lexicographic order
            ll second = nextj < n ? P[nextj] : -1;

            L[j] = {first, second, j};
        }

        sort(L.begin(), L.end());

        rep(j, 0, n) {
            // If the strings are the same, then your rank is the same as the
            // previous
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

void initLCP(const string& s) {
    assert(sa.size() > 0);
    assert(lcp.size() > 0);

    ll n = lg(s);

    // kasai's algorithm, find lcp
    // uses the idea that lcp[i+1] will be at least lcp[i] - 1
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

void init(const string& s) {
    initSA(s);
    initLCP(s);
}

}  // namespace SA

VLL next_small(const VLL& A) {
    ll n = sz(A);
    // A[i] num elements in front (not inc itself) that are >=
    VLL ans(n, -inf);
    stack<PLL> st;  // value, index
    st.push({-inf, n});
    rrep(i, n - 1, 0) {
        while (st.top().first >= A[i]) st.pop();

        ans[i] = st.top().second - i - 1;
        st.push({A[i], i});
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    ll n = lg(s);

    SA::init(s);

    VLL forward = next_small(SA::lcp);
    VLL copy = SA::lcp;
    reverse(all(copy));
    VLL backward = next_small(copy);
    reverse(all(backward));

    ll ans = n;
    rep(i, 0, n - 1) {
        upmax(ans, SA::lcp[i] * (forward[i] + backward[i] + 2));
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