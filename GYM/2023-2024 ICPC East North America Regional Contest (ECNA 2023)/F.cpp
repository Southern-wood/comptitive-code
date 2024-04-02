#include <bits/stdc++.h>
using namespace std;

const int N = 120;

vector<int> pow(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    a[i] *= 2;
  }
  for (int i = 0; i < a.size() - 1; i++) {
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }
  if (a.back() >= 10) {
    a.push_back(a.back() / 10);
    a[a.size() - 2] %= 10;
  }
  return a;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = s.size() - 1; j >= 0; j--) {
      a[i].push_back(s[j] - '0');
    }
  }
  map<vector<int>, int> mp;
  vector<int> ans = {1};
  for (int i = 0; i < N; i++) {
    mp[ans] = i;
    ans = pow(ans);
  }
  list<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(mp[a[i]]);
  }

  for (int i = 0; i < N; i++) {
    for (auto it = v.begin(); it != v.end(); it++) {
      if (*it < i) {
        it = prev(v.erase(it));
      }
      while (it != v.end() && next(it) != v.end() && *it == *next(it)) {
        (*it)++;
        it = v.erase(next(it));
      }
    }
    if (v.size() == 1) {
      break;
    }
  }

  for (auto it : mp) {
    if (it.second == *v.begin()) {
      for (int i = it.first.size() - 1; i >= 0; i--) {
        cout << it.first[i];
      }
      cout << '\n';
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}