#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x{100 * (100 + 1) / 2};
  cout << x * x - 100 * (100 + 1) * (100 * 2 + 1) / 6 << '\n';
}
