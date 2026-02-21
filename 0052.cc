#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll i{1};
  while (true) {
    vector<string> vec;
    for (ll j{2}; j <= 6; ++j) {
      string str{to_string(i * j)};
      sort(str.begin(), str.end());
      vec.emplace_back(str);
    }
    sort(vec.begin(), vec.end());
    if (vec.front() == vec.back()) {
      cout << i << '\n';
      return 0;
    }
    ++i;
  }
}
