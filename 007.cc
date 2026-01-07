#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  array<bool, ll(1e6) + 1> is_prime;
  is_prime.fill(true);
  vector<ll> primes;
  primes.reserve(1e6 / log(1e6));
  primes.emplace_back(2);
  for (ll i{3}; i <= ll(1e6) && primes.size() < ll(1e4) + 1; i += 2) {
    if (is_prime[i]) {
      primes.emplace_back(i);
      for (ll j{i * i}; j <= ll(1e6); j += i * 2) {
        is_prime[j] = false;
      }
    }
  }
  cout << primes.back() << '\n';
}
