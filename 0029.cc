#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static string mul(const string& a, int p, int o) {
  string ans(o, '0');
  int carry{};
  int n(a.size());
  for (int i{}; i < n || carry; ++i) {
    carry += (i < n ? (a[i] - '0') * p : 0);
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans;
}

static string add(const string& a, const string& b) {
  string ans{};
  int carry{};
  int n(a.size()), m(b.size());
  for (int i{}; i < n || i < m || carry; ++i) {
    carry += (i < n ? a[i] - '0' : 0) + (i < m ? b[i] - '0' : 0);
    ans.push_back(carry % 10 + '0');
    carry /= 10;
  }
  return ans;
}

static string mul(const string& a, const string& b) {
  string ans{"0"};
  int n(b.size());
  for (int i{}; i < n; ++i) {
    ans = add(ans, mul(a, b[i] - '0', i));
  }
  return ans;
}

static string pow(string base, int exp) {
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
  vector<string> vec;
  vec.reserve(99 * 99);
  for (ll a{2}; a <= 100; ++a) {
    for (ll b{2}; b <= 100; ++b) {
      vec.emplace_back(pow(to_string(a), b));
    }
  }
  sort(vec.begin(), vec.end());
  cout << unique(vec.begin(), vec.end()) - vec.begin() << '\n';
}
