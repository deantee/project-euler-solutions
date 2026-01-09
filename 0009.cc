#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (ll a{1}; a < 500; ++a) {
    ll cmax{1000 - (a + 499)};
    if (a * a > cmax * cmax) {
      break;
    }
    for (ll b{max(a + 1, 501 - a)}; b < 500 && a + b * 2 < 1000; ++b) {
      ll c{1000 - a - b};
      ll diff{a * a + b * b - c * c};
      if (diff > 0) {
        break;
      }
      if (diff == 0) {
        cout << a * b * c << '\n';
        return 0;
      }
    }
  }
}
