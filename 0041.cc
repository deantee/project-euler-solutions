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
  ll ans{};
  for (ll digit{1}; digit <= 9; ++digit) {
    string t(digit, 0);
    iota(t.begin(), t.end(), '1');
    do {
      ll x{stoll(t)};
      if (is_prime(x)) {
        ans = max(ans, x);
      }
    } while (next_permutation(t.begin(), t.end()));
  }
  cout << ans << '\n';
}
