//
// Created by covariance on 24.02.2021.
//
#include <bits/stdc++.h>

using namespace std;

vector<uint32_t> dzeta(const string &str) {
  uint32_t n = str.size();
  vector<uint32_t> z(n);
  z[0] = 0;
  for (uint32_t i = 1, l = 0, r = 0; i != n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && !(str[z[i]] ^ str[i + z[i]])) {
      ++z[i];
    }
    if (i + z[i] > r + 1) {
      l = i, r = i + z[i] - 1;
    }
  }
  z.erase(z.begin());
  return z;
}

int main() {
  string p, t;
  cin >> p >> t;

  uint32_t d = p.size();
  vector<uint32_t> hash = dzeta(p + '&' + t);

  vector<uint32_t> ans;
  for (uint32_t i = d; i != hash.size(); ++i) {
    if (!(hash[i] ^ d)) {
      ans.push_back(i - d + 1);
    }
  }

  cout << ans.size() << endl;
  for (auto c : ans) {
    cout << c << ' ';
  }

  return 0;
}
