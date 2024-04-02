#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a;
  cin >> a;
  int n = a.size();
  vector<int> hyphen;
  for (int i = 0; i < n; i++) {
    if (a[i] == '-') {
      if (!hyphen.empty() && i - hyphen.back() == 1 // adjacent hyphens
          || i == 0 || i == n - 1 ||
          hyphen.size() == 2 && i != n - 2 // hyphen at the beginning or end
          || hyphen.size() == 3) {         // more than 3 hyphens
        cout << "invalid" << '\n';
        return;
      }
      hyphen.push_back(i);
    }
    if (a[i] >= '0' && a[i] <= '9' || a[i] == '-') // valid characters
      continue;
    if (i == n - 1 && a[i] == 'X')
      continue;
    cout << "invalid" << '\n';
    return;
  }
  if (n - hyphen.size() != 10) {
    cout << "invalid" << '\n';
    return;
  }
  int check = 0, cnt = 10;
  for (int i = 0; i < n; i++) {
    if (a[i] == '-')
      continue;
    if (a[i] == 'X') {
      check += 10 * cnt;
    } else {
      check += (a[i] - '0') * cnt;
    }
    cnt--;
  }
  // cerr << "check code: " << check % 11 << '\n';
  if (check % 11 != 0) {
    cout << "invalid" << '\n';
    return;
  }
  a = "978-" + a;
  n = a.size();
  check = 0, cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == '-')
      continue;
    check += (a[i] - '0') * (cnt % 2 == 0 ? 1 : 3);
    cnt++;
  }
  for (int i = 0; i < 10; i++) {
    if ((check + i) % 10 == 0) {
      a.back() = i + '0';
      break;
    }
  }
  cout << a << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}