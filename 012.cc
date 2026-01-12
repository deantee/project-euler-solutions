#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n{1};
  while (true) {
    ll a{n};
    ll b{n + 1};
    if (a % 2 == 0) {
      a /= 2;
    } else {
      b /= 2;
    }
    ll tz_a{__builtin_ctzll(a)};
    ll tz_b{__builtin_ctzll(b)};
    ll ans{tz_a + tz_b + 1};
    a >>= tz_a;
    b >>= tz_b;
    for (ll i{3}; i * i <= a || i * i <= b; i += 2) {
      ll t{};
      if (i * i <= a) {
        while (a % i == 0) {
          a /= i;
          ++t;
        }
      }
      if (i * i <= b) {
        while (b % i == 0) {
          b /= i;
          ++t;
        }
      }
      ans *= t + 1;
    }
    if (a > 1 || b > 1) {
      if (a == b) {
        ans *= 3;
      } else {
        if (a > 1) {
          ans *= 2;
        }
        if (b > 1) {
          ans *= 2;
        }
      }
    }
    if (ans > 500) {
      cout << n * (n + 1) / 2 << '\n';
      return 0;
    }
    ++n;
  }
}
