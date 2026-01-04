#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto is_palindrome = [](ll x) -> bool {
    if (x == 0) {
      return true;
    }
    if (x < 0 || x % 10 == 0) {
      return false;
    }
    ll y{};
    while (x > y) {
      y *= 10;
      y += x % 10;
      x /= 10;
    }
    return x == y || x == y / 10;
  };
  ll ans{};
  for (ll i{100}; i <= 999; ++i) {
    for (ll j{i}; j <= 999; ++j) {
      ll x{i * j};
      if (is_palindrome(x)) {
        ans = max(ans, x);
      }
    }
  }
  cout << ans << '\n';
}
