#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> vec(10);
  iota(vec.begin(), vec.end(), 0LL);
  for (ll i{1}; i < ll(1e6); ++i) {
    next_permutation(vec.begin(), vec.end());
  }
  for (ll x : vec) {
    cout << x;
  }
  cout << '\n';
}
