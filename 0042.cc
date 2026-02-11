#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream is("0042_words.txt");
  string buf;
  is >> buf;
  is.close();
  stringstream ss(buf);
  ll ans{};
  while (getline(ss, buf, ',')) {
    buf = buf.substr(1, buf.size() - 2);
    ll s{};
    for (char c : buf) {
      s += c - 'A' + 1;
    }
    s *= 2;
    ll l{1}, r{LLONG_MAX};
    while (l < r) {
      ll m{l + (r - l) / 2};
      if (m * (m + 1) >= s) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (l * (l + 1) == s) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
