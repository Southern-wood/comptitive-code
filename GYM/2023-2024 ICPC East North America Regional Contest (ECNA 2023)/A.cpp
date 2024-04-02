#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), pre(n), suf(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  pre[0] = a[0], suf[n - 2] = a[n - 1];
  for (int i = 1; i < n; i++) {
    pre[i] = max(pre[i - 1], a[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = min(suf[i + 1], a[i]);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] <= suf[i] && a[i] >= pre[i]) {
      ans.push_back(a[i]);
    }
  } 
  cout << ans.size() << ' ';
  for (int i = 0; i < min((int)ans.size(), 100); i++) {
    cout << ans[i] << ' ';
  }

}