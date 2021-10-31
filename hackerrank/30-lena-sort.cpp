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

VLL L, R, P, D;
VLL sum;
set<PLL> depths;  // depths, ind

// returns the last number used
ll big(ll ind) {
    if (ind == -1) return 0;
    if (sum[ind] == -1) {
        sum[ind] = 1 + big(L[ind]) + big(R[ind]);
    }
    return sum[ind];
}

void print(ll ind, ll first) {
    if (ind == -1) return;

    ll a = big(L[ind]);
    cout << first + a << ' ';

    print(L[ind], first);
    print(R[ind], first + a + 1);
}

void solve() {
    ll q;
    cin >> q;
    rep(_, 0, q) {
        ll n, k;
        cin >> n >> k;
        L.assign(n, -1);
        R.assign(n, -1);
        P.assign(n, -1);
        D.assign(n, -1);
        sum.assign(n, -1);

        depths.clear();

        ll total = 0;
        rep(i, 0, n) {
            if (i + 1 < n) L[i] = i + 1;
            if (i - 1 >= 0) P[i] = i - 1;

            D[i] = i;
            depths.insert({D[i], i});

            total += D[i];
        }

        ll extra = total - k;

        // ok i have a n size tree
        ll it = 0;
        while (extra > 0 && sz(depths)) {
            ll bottom = depths.rbegin()->se;
            ll top = depths.begin()->se;

            if (D[bottom] <= D[top] + 1) break;

            ll target = -1;  // null
            if (D[bottom] - D[top] - 1 <= extra) {
                target = top;
            } else {
                fe(x, depths) {
                    ll ind = x.se;
                    if (D[bottom] - D[ind] - 1 == extra) {
                        target = ind;
                        break;
                    }
                }
            }
            assert(target != -1);

            extra -= D[bottom] - D[target] - 1;

            // put bottom's parent back in
            depths.insert({D[P[bottom]], P[bottom]});

            // remove bottom and target from set

            depths.erase({D[bottom], bottom});
            depths.erase({D[target], target});

            // unlink from parent
            if (L[P[bottom]] == bottom) {
                L[P[bottom]] = -1;
            } else if (R[P[bottom]] == bottom) {
                R[P[bottom]] = -1;
            } else {
                assert(false);
            }

            // link with target
            P[bottom] = target;
            if (L[target] == -1) {
                L[target] = bottom;
            } else if (R[target] == -1) {
                R[target] = bottom;
            } else {
                assert(false);
            }

            // update depth
            D[bottom] = D[P[bottom]] + 1;

            // add target back in ONLY if it is not full
            if (L[target] == -1 || R[target] == -1) {
                depths.insert({D[target], target});
            }
            depths.insert({D[bottom], bottom});
        }

        if (extra != 0) {
            cout << -1 << endl;
        } else {
            // I have a sick tree now
            print(0, 1);
            cout << endl;
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