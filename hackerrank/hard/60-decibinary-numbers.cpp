/*
Original problem: https://www.hackerrank.com/challenges/decibinary-numbers
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

namespace SOLVE {
	ll inv = -1;
	ll nax = 300000; // the last 299999-equivalent decibinary number is indexed at 118179178844129560
	ll intbit = 20; // which requires 20 bits
	VLL prefix(nax);

	vector<VLL> freq(nax, VLL(intbit, inv)); // freq[i][j] stores the number of decibinary in intbit digits

	// top down recursion!
	// count(i, j) returns the number of ways i (in decimal) can be represented in j digits. 
	// allows leading 0s.

	ll count(ll num, ll digits) {
		// base cases
		if (num < 0) {
			return 0;
		}
		if (num == 0 && digits >= 0) {
			return 1;
		}
		if (digits <= 0) {
			return 0;
		}

		// memoisation
		if (freq[num][digits] != -1) {
			return freq[num][digits];
		}

		// the strategy is - what if the first digit was 0-9? 
		// how many ways can you represent what is left within some amount of digits?
		ll total = 0;
		ll twop = (1LL << (digits - 1));
		for (ll mult = 0; mult <= 9 && mult * twop <= num; mult++) {
			total += count(num - mult * twop, digits - 1);
		}

		freq[num][digits] = total;
		return total;
	}

	// returns the 'index'th number of n if we can use 'digits' digits
	// it feels like a tree - choosing the right branch if the index is within the lower/upper bounds
	string decibinary(ll n, ll index, int digits, int showzero) {
		if (digits == 0) {
			return "";
		}

		// small and big are index bounds
		ll small = 1, big = 0;
		ll twop = (1LL << (digits - 1));

		for (int i = 0; i <= 9; i++) {
			big += count(n - i * twop, digits - 1);

			if (small <= index && index <= big) { // then this is the right i!

				if (!showzero) {
					if (i == 0) {
						return decibinary(n - i * twop, index - small + 1, digits - 1, 0);
					}
					return to_string(i) + decibinary(n - i * twop, index - small + 1, digits - 1, 1);
				}
				else {
					return to_string(i) + decibinary(n - i * twop, index - small + 1, digits - 1, 1);
				}
			}

			small = big + 1;
		}
		return "inv"; // should never happen - only if the index is out of bounds
	}

	// returns the decimal number given the index
	// this is the "first" branch
	int decimal(ll index) {
		int L = 0, R = nax - 1;
		while (L < R) {
			int M = (L + R) / 2;
			if (prefix[M] >= index) {
				R = M;
			}
			else {
				L = M + 1;
			}
		}
		return L;
	}

	void main() {
		// concatenate to string is slightly faster than cout every time
		string ans = "";
		ll q, temp;

		// preprocess the prefix array
		prefix[0] = count(0, intbit - 1);
		REP(i, 1, nax) {
			prefix[i] = prefix[i - 1] + count(i, intbit - 1);
		}

		cin >> q;

		REP(i, 0, q) {
			cin >> temp;

			// this finds which decimal the index is
			ll d = decimal(temp);
			if (d == 0) {
				ans += "0\n";
			}
			else {
				// decibinary(decimal to represent, 1-index of the decimal, max bits, don't show leading zeros)
				ans += decibinary(d, temp - prefix[d - 1], intbit - 1, 0) + '\n';
			}
		}
		cout << ans;
	}
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}