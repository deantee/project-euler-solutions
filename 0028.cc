#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  static ll arr[1001][1001];
  ll x{500}, y{500}, val{1}, len{1}, k{};
  ll dd[]{-1, 0, 1, 0, -1};
  arr[x][y] = val++;
  while (val <= 1001 * 1001) {
    for (ll t{}; t < 2; ++t) {
      for (ll i{}; i < len && val <= 1001 * 1001; ++i) {
        x += dd[k];
        y += dd[k + 1];
        arr[x][y] = val++;
      }
      k = (k + 1) % 4;
    }
    ++len;
  }
  ll ans{};
  for (ll i{}; i < 1001; ++i) {
    ans += arr[i][i] + arr[i][1000 - i];
  }
  ans -= arr[500][500];
  cout << ans << '\n';
}
