#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  array<ll, 8> primes{2, 3, 5, 7, 11, 13, 17, 19};
  array<ll, 8> max_freq{};
  for (ll i{1}; i <= 20; ++i) {
    ll x{i};
    for (ll j{}; j < 8; ++j) {
      ll cnt{};
      while (x % primes[j] == 0) {
        x /= primes[j];
        ++cnt;
      }
      max_freq[j] = max(max_freq[j], cnt);
    }
  }
  auto fast_pow = [](ll b, ll e) -> ll {
    ll x{1};
    while (e > 0) {
      if (e & 1) {
        x *= b;
      }
      b *= b;
      e /= 2;
    }
    return x;
  };
  ll ans{1};
  for (ll i{}; i < 8; ++i) {
    ans *= fast_pow(primes[i], max_freq[i]);
  }
  cout << ans << '\n';
}
