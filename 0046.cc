#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<bool> is_prime(1e7, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i{4}; i < ll(is_prime.size()); i += 2) {
    is_prime[i] = false;
  }
  vector<ll> primes{2};
  for (ll i{3}; i < ll(is_prime.size()); i += 2) {
    if (!is_prime[i]) {
      continue;
    }
    primes.emplace_back(i);
    for (ll j{i * i}; j < ll(is_prime.size()); j += i * 2) {
      is_prime[j] = false;
    }
  }
  for (ll i{3};; i += 2) {
    if (is_prime[i]) {
      continue;
    }
    bool fail{true};
    for (ll prime : primes) {
      if (prime >= i) {
        break;
      }
      if (i - prime < 2 || (i - prime) % 2) {
        continue;
      }
      ll x{(i - prime) / 2};
      ll r(sqrtl(x));
      if (r * r == x) {
        fail = false;
        break;
      }
    }
    if (fail) {
      cout << i << '\n';
      return 0;
    }
  }
}
