#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string add(const string& a, const string& b) {
  string ans{};
  ll carry{};
  ll n(a.size()), m(b.size());
  for (ll i{}; i < n || i < m || carry; ++i) {
    carry += (i < n ? a[i] - '0' : 0) + (i < m ? b[i] - '0' : 0);
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans.substr(0, 10);
}

string mul(const string& a, int val, int off) {
  string ans(off, '0');
  ll carry{};
  ll n(a.size());
  for (ll i{}; i < n || carry; ++i) {
    carry += i < n ? (a[i] - '0') * val : 0;
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans.substr(0, 10);
}

string mul(const string& a, const string& b) {
  string ans{"0"};
  ll n(b.size());
  for (ll i{}; i < n; ++i) {
    ans = add(ans, mul(a, b[i] - '0', i));
  }
  return ans.substr(0, 10);
}

string pow(string base, ll exp) {
  string ans{"1"};
  while (exp) {
    if (exp % 2) {
      ans = mul(ans, base);
    }
    base = mul(base, base);
    exp /= 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string t{"0"};
  for (ll i{1}; i <= 1000; ++i) {
    string t1{to_string(i)};
    reverse(t1.begin(), t1.end());
    t = add(t, pow(t1, i));
  }
  string ans{t.substr(0, 10)};
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
