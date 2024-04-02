#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 60;

signed main() {
  string s;
  cin >> s;
  int n = s.size();

  auto isValid = [](const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] != 'E' && s[i] != 'O') {
        cout << "INVALID" << '\n';
        return false;
      }
      if (i && s[i] == s[i - 1] && s[i] == 'O') {
        cout << "INVALID" << '\n';
        return false;
      }
    }
    if (s.back() != 'O') {
      cout << "INVALID" << '\n';
      return false;
    }
    return true;
  };

  if (!isValid(s)) {
    return 0;
  }

  set<int> pows;
  for (int i = 0; i < N; i++) {
    pows.insert(1LL << i);
  }
  vector<int> ans;

  for (int i = 0; i < N; i++) {
    int x = 1LL << i;
    bool valid = true;
    for (int j = n - 1; j >= 0; j--) {
      if (s[j] == 'O' && (x - 1) % 3 != 0) {
        valid = false;
        break;
      } 
      if (s[j] == 'O') {
        x = (x - 1) / 3;
      } else {
        x = x << 1;
      }
      if (pows.count(x) || x <= 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << '\n';

}