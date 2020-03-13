#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++) // for loop
#define RREP(x,l,u) for(ll x = l;x>=u;x--) // reverse for loop

/**
 *  debugging stuff
 */
string to_string(string s) {return s;}
string to_string(char c) {return string(1,c);}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

/**
 *  more debugging stuff
 */
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL; 
typedef pair<ll,ll> PLL;
typedef vector<string> VS;

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

ll N, d, notifications = 0;
VLL costs;
map<ll,ll> frequencies;

ll find_median(map<ll,ll> frequencies) {

    VLL in_arr;
    ll mid = d / 2 + 1;
    ll middle1, middle2;


    if (d % 2) { // odd
        for (auto it : frequencies) {

            if (mid - it.second <= 0) {
                middle1 = it.first;
                break;
            } 

            mid -= it.second;
        }
    } else {
        
        for (auto it : frequencies) {
            if (mid - it.second < 0) {
                middle1 = it.first;
                middle2 = it.first;
                break;
            } else if (mid - it.second == 0) {
                middle1 = it.first;
                middle2 = -inf;
            }

            if (middle2 == -inf) {
                middle2 = it.first;
                break;
            }

            mid -= it.second;
        }
    }

    // convert the d_days to a vector
    // VLL sorted = count_sort(in_arr);

    if (d % 2) { // odd
        return middle1 * 2;
    } else {
        return middle1 + middle2;
    }
}

namespace SOLVE {	
	void main() {
		cin >> N >> d;

        map<ll,ll> test;

        REP(i,0,N) {
            ll input;
            cin >> input;
            costs.push_back(input);
            test[input]++;

            // initialise the map
            if (i < d) {
                frequencies[input]++;
            }
        }

        // keep the index of the last value to add
        ll last = d;

        REP(i,0,N-d) {
            db median = find_median(frequencies);

            if (costs[last] < (median)) notifications++;

            frequencies[costs[i]]--;
            frequencies[costs[last++]]++;
        }

        // debug(notifications);

        // REP(i,d,N) {
        //     // take first d characters and sort it to find the median
        //     // db median = find_median(values, i);

        //     if (costs[i] >= (2*median)) notifications++;

        //     // pop front and add next values
        //     values.pop_front();
        //     values.push_back(costs[i]);
        // }

        cout << notifications << endl;
	}
}

signed main() {
	ll t;
	t = 1;
    // cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}