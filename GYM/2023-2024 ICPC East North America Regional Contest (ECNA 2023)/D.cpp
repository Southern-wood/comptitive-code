#include <bits/stdc++.h>
using namespace std;

int main() {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int A, L;
    cin >> A >> L;
    sum += A * L;
  }
  int N, KWF;
  cin >> N >> KWF;
  cout << sum / 5 * N / KWF << '\n';
}