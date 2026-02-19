#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<bool> is_prime(1e6);
  is_prime[2] = true;
  for (ll i{3}; i < ll(is_prime.size()); i += 2) {
    is_prime[i] = true;
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
  vector<ll> pf(primes.size() + 1);
  for (ll i{}; i < ll(primes.size()); ++i) {
    pf[i + 1] = pf[i] + primes[i];
  }
  ll ans{}, best{};
  for (ll i{1}; i < ll(pf.size()); ++i) {
    for (ll j{i}; j--;) {
      ll diff{pf[i] - pf[j]};
      if (diff < ll(1e6) && is_prime[diff]) {
        if (best < i - j) {
          best = i - j;
          ans = diff;
        }
      }
    }
  }
  cout << ans << '\n';
}
