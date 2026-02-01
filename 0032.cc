#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> digits(9);
  iota(digits.begin(), digits.end(), 1LL);
  vector<ll> prods;
  do {
    for (ll i{1}; i < 9; ++i) {
      for (ll j{i + 1}; j < 9; ++j) {
        ll a{}, b{}, c{};
        for (ll k{}; k < i; ++k) {
          a = a * 10 + digits[k];
        }
        for (ll k{i}; k < j; ++k) {
          b = b * 10 + digits[k];
        }
        for (ll k{j}; k < 9; ++k) {
          c = c * 10 + digits[k];
        }
        if (a * b == c) {
          prods.emplace_back(c);
        }
      }
    }
  } while (next_permutation(digits.begin(), digits.end()));
  ll ans{};
  sort(prods.begin(), prods.end());
  prods.erase(unique(prods.begin(), prods.end()), prods.end());
  for (ll prod : prods) {
    ans += prod;
  }
  cout << ans << '\n';
}
