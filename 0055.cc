#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static string add(const string& a, const string& b) {
  ll carry{};
  ll n(a.size()), m(b.size());
  string ans;
  for (ll i{}; i < n || i < m || carry; ++i) {
    carry += (i < n ? a[i] - '0' : 0) + (i < m ? b[i] - '0' : 0);
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const ll N(1e4);
  unordered_map<string, ll> mp;
  ll ans{};
  for (ll i{1}; i < N; ++i) {
    string str{to_string(i)};
    reverse(str.begin(), str.end());
    ll it{};
    while (it < 50) {
      string cpy{str};
      reverse(cpy.begin(), cpy.end());
      str = add(str, cpy);
      ++it;
      cpy = str;
      reverse(cpy.begin(), cpy.end());
      if (str == cpy) {
        break;
      }
    }
    if (it == 50) {
      ++ans;
    }
  }
  cout << ans << '\n';
}
