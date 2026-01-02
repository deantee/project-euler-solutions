#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll i{}, j{1}, ans{};
  while (j <= ll(4e6)) {
    ll k{i + j};
    i = j;
    j = k;
    if (~j & 1) {
      ans += j;
    }
  }
  cout << ans << '\n';
}
