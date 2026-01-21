#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto d = [](ll n) -> ll {
    ll k{__builtin_ctzll(n)};
    n >>= k;
    ll res{1};
    res *= (1LL << (k + 1)) - 1;
    for (ll i{3}; i * i <= n; i += 2) {
      ll t{1};
      while (n % i == 0) {
        n /= i;
        t *= i;
        ++t;
      }
      res *= t;
    }
    if (n > 1) {
      res *= n + 1;
    }
    return res;
  };
  ll ans{};
  for (ll a{2}; a < 10000; ++a) {
    ll b{d(a) - a};
    if (a != b && d(b) - b == a) {
      ans += a;
    }
  }
  cout << ans << '\n';
}
