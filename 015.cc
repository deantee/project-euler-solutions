#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto choose = [](ll n, ll k) -> ll {
    ll ans{1};
    for (ll i{}; i < k; ++i) {
      ans *= n - i;
      ans /= i + 1;
    }
    return ans;
  };
  cout << choose(40, 20) << '\n';
}
