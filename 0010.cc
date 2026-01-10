#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr ll n(2e6);
  array<uint8_t, n> is_prime;
  is_prime.fill(true);
  ll ans{2};
  for (ll i{3}; i < n; i += 2) {
    if (is_prime[i]) {
      ans += i;
      for (ll j{i * i}; j < n; j += i * 2) {
        is_prime[j] = false;
      }
    }
  }
  cout << ans << '\n';
}
