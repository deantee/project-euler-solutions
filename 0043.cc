#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string t(10, 0);
  iota(t.rbegin(), t.rend(), '0');
  vector<ll> vec{2, 3, 5, 7, 11, 13, 17};
  ll ans{};
  do {
    bool ok{true};
    for (ll i{}; i < 7; ++i) {
      if (stoll(t.substr(i + 1, 3)) % vec[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans += stoll(t);
    }
  } while (prev_permutation(t.begin(), t.end()));
  cout << ans << '\n';
}
