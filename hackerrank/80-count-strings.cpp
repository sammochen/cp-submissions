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

const ll NAX = 128;

bitset<NAX> getOneBit(ll ind) {
    bitset<NAX> bit;
    bit[ind] = 1;
    return bit;
}

// Global NFA info
ll nfaNodes = 0;
vector<PLL> zeros, as, bs;

VLL getZeroEdges(ll at) {
    VLL ans;
    fe(z, zeros) {
        if (z.fi == at) ans.pb(z.se);
    }
    return ans;
}
VLL getAEdges(ll at) {
    VLL ans;
    fe(z, as) {
        if (z.fi == at) ans.pb(z.se);
    }
    return ans;
}
VLL getBEdges(ll at) {
    VLL ans;
    fe(z, bs) {
        if (z.fi == at) ans.pb(z.se);
    }
    return ans;
}

template <typename A>
set<A> merge(set<A> x, set<A> y) {
    x.insert(all(y));
    return x;
}

// return start, end
PLL f(const string& s) {
    ll n = lg(s);
    // recursive
    if (s[0] == '(') {
        assert(s[n - 1] == ')');
        string t = s.substr(1, n - 2);
        ll m = lg(t);

        // star
        if (t[m - 1] == '*') {
            string a = t.substr(0, m - 1);
            auto A = f(a);

            auto head = nfaNodes++;

            // Create a new node, which can any time go into A
            zeros.pb({head, A.fi});
            zeros.pb({A.se, head});
            return {head, head};
        }

        // or
        ll cnt = 0;
        rep(i, 0, m) {
            if (t[i] == '(') {
                cnt++;
            } else if (t[i] == ')') {
                cnt--;
            }
            if (cnt == 0 && t[i] == '|') {
                string a = t.substr(0, i);
                string b = t.substr(i + 1);
                auto A = f(a);
                auto B = f(b);

                auto head = nfaNodes++;
                auto tail = nfaNodes++;

                zeros.pb({head, A.fi});
                zeros.pb({head, B.fi});

                zeros.pb({A.se, tail});
                zeros.pb({B.se, tail});

                return {head, tail};
            }
        }

        // concatenation
        ll startB = -1;
        if (t[0] == '(') {
            ll cnt = 1;
            rep(i, 1, m) {
                if (t[i] == '(')
                    cnt++;
                else if (t[i] == ')')
                    cnt--;
                if (cnt == 0) {
                    startB = i + 1;
                    break;
                }
            }
        } else {
            startB = 1;
        }
        string a = t.substr(0, startB);
        string b = t.substr(startB);

        auto A = f(a);
        auto B = f(b);

        zeros.pb({A.se, B.fi});
        return {A.fi, B.se};

    } else {
        assert(s == "a" || s == "b");
        // single letter. make two states
        auto head = nfaNodes++;
        auto tail = nfaNodes++;

        if (s == "a") {
            as.pb({head, tail});
        } else {
            bs.pb({head, tail});
        }
        return {head, tail};
    }
}

VVLL operator*(VVLL a, VVLL b) {
    VVLL c(sz(a), VLL(sz(b)));

    rep(i, 0, sz(a)) {
        rep(j, 0, sz(a[0])) {
            rep(k, 0, sz(b[0])) {
                c[i][k] += a[i][j] * b[j][k];
                c[i][k] %= mod;
            }
        }
    }

    return c;
}

VVLL operator^(VVLL a, ll k) {
    if (k == 0) {
        VVLL b(sz(a), VLL(sz(a)));
        rep(i, 0, sz(a)) b[i][i] = 1;
        return b;
    }
    VVLL half = a ^ (k / 2);
    half = half * half;
    if (k % 2) {
        half = half * a;
    }
    return half;
}

// Returns all places you can get to with a zero
void dfsZero(ll at, bitset<NAX>& visMask) {
    if ((visMask & getOneBit(at)).any()) return;
    visMask |= getOneBit(at);

    fe(to, getZeroEdges(at)) {
        dfsZero(to, visMask);
    }
}

bitset<NAX> getZero(ll at) {
    bitset<NAX> visMask = 0;
    dfsZero(at, visMask);
    return visMask;
}

bitset<NAX> getZeroMask(bitset<NAX> atMask) {
    bitset<NAX> ans = 0;
    rep(i, 0, NAX) {
        bitset<NAX> oneBit;
        oneBit[i] = 1;
        if ((oneBit & atMask).any()) {
            ans |= getZero(i);
        }
    }
    return ans;
}

bitset<NAX> getOne(ll at, char move) {
    bitset<NAX> mask;
    if (move == 'a') {
        fe(to, getAEdges(at)) {
            mask |= getOneBit(to);
        }
    } else if (move == 'b') {
        fe(to, getBEdges(at)) {
            mask |= getOneBit(to);
        }
    }
    return mask;
}

bitset<NAX> getOneMask(bitset<NAX> atMask, char move) {
    bitset<NAX> ans = 0;
    rep(i, 0, NAX) {
        bitset<NAX> oneBit;
        oneBit[i] = 1;
        if ((oneBit & atMask).any()) {
            ans |= getOne(i, move);
        }
    }
    return ans;
}

bitset<NAX> getZeroOrOneMask(bitset<NAX> atMask, char move) {
    return getZeroMask(getOneMask(getZeroMask(atMask), move));
}

void dfs2(bitset<NAX> atMask, uset<bitset<NAX>>& vis) {
    if (vis.find(atMask) != vis.end()) return;
    vis.insert(atMask);

    bitset<NAX> nextMaskA = getZeroOrOneMask(atMask, 'a');
    bitset<NAX> nextMaskB = getZeroOrOneMask(atMask, 'b');

    dfs2(nextMaskA, vis);
    dfs2(nextMaskB, vis);
}

void solve() {
    string s;
    ll k;
    cin >> s >> k;

    nfaNodes = 0;
    zeros.clear();
    as.clear();
    bs.clear();

    auto nfa = f(s);

    // convert to DFA - powerset construction
    assert(nfaNodes < NAX);

    bitset<NAX> startMask = getZero(nfa.first);

    uset<bitset<NAX>> vis = {};
    dfs2(startMask, vis);

    umap<bitset<NAX>, ll> maskID;
    ll curMaskID = 0;
    fe(v, vis) {
        maskID[v] = curMaskID++;
    }

    ll n = curMaskID;
    VVLL E(n, VLL(n));
    fe(v, vis) {
        bitset<NAX> nextA = getZeroOrOneMask(v, 'a');
        bitset<NAX> nextB = getZeroOrOneMask(v, 'b');

        assert(maskID.find(nextA) != maskID.end());
        assert(maskID.find(nextB) != maskID.end());

        E[maskID[v]][maskID[nextA]]++;
        E[maskID[v]][maskID[nextB]]++;
    }

    VVLL pow = E ^ k;

    ll ans = 0;
    bitset<NAX> acceptMask;
    acceptMask[nfa.second] = 1;
    fe(v, vis) {
        if ((acceptMask & v).any()) {
            ans += pow[maskID[startMask]][maskID[v]];
            ans %= mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}