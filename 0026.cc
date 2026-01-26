#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static ll get_len(ll den) {
  while (den % 2 == 0) {
    den /= 2;
  }
  while (den % 5 == 0) {
    den /= 5;
  }
  if (den == 1) {
    return 0;
  }
  vector<int> last(den, -1);
  ll pos{}, rem{1};
  while (last[rem] == -1) {
    last[rem] = pos++;
    rem = rem * 10 % den;
  }
  return pos - last[rem];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll best{}, ans{};
  for (ll i{2}; i < 1000; ++i) {
    ll len{get_len(i)};
    if (len > best) {
      best = len;
      ans = i;
    }
  }
  cout << ans << '\n';
}
