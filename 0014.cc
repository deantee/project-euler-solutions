#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<ll, ll> cache;
  auto dfs = [&](auto&& self, ll n) -> ll {
    if (n == 1) {
      return 1;
    }
    auto it = cache.find(n);
    if (it != cache.end()) {
      return it->second;
    }
    return cache[n] = self(self, n % 2 == 0 ? n / 2 : n * 3 + 1) + 1;
  };
  ll ans{};
  ll ans_n{};
  for (ll n{1}; n <= 1000000; ++n) {
    ll t{dfs(dfs, n)};
    if (ans < t) {
      ans = t;
      ans_n = n;
    }
  }
  cout << ans_n << '\n';
}
