#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<int, int> mp;
  for (ll p{1}; p <= 1000; ++p) {
    for (ll a{1}; a < p; ++a) {
      for (ll b{a + 1}; b < p; ++b) {
        ll c{p - a - b};
        if (a * a + b * b == c * c) {
          ++mp[a + b + c];
        }
      }
    }
  }
  ll ans{}, best{};
  for (auto& [k, v] : mp) {
    if (best < v) {
      best = v;
      ans = k;
    }
  }
  cout << ans << '\n';
}
