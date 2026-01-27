#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static bool is_prime(ll n) {
  if (n < 5) {
    return n == 2 || n == 3;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (ll i{3}; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans{}, best{};
  for (ll a{-999}; a < 1000; ++a) {
    for (ll b{-1000}; b <= 1000; ++b) {
      ll n{};
      while (is_prime(n * n + a * n + b)) {
        ++n;
      }
      if (best < n) {
        best = n;
        ans = a * b;
      }
    }
  }
  cout << ans << '\n';
}
