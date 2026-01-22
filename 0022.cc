#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream is("0022_names.txt");
  string str;
  vector<string> names;
  while (getline(is, str, ',')) {
    names.emplace_back(str.substr(1, str.size() - 2));
  }
  sort(names.begin(), names.end());
  ll n(names.size());
  ll ans{};
  for (ll i{}; i < n; ++i) {
    ll t{};
    for (char ch : names[i]) {
      t += ch - 'A' + 1;
    }
    ans += (i + 1) * t;
  }
  is.close();
  cout << ans << '\n';
}
