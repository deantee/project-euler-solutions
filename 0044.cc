#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto p = [](ll n) -> ll { return n * (n * 3 - 1) / 2; };
  auto ok = [](ll n) -> bool {
    ll v{n * 24 + 1};
    ll r(sqrtl(v));
    return r * r == v && (r + 1) % 6 == 0;
  };
  for (ll i{2};; ++i) {
    for (ll j{i}; j-- > 1;) {
      if (ok(p(i) - p(j)) && ok(p(i) + p(j))) {
        cout << p(i) - p(j) << '\n';
        return 0;
      }
    }
  }
}
