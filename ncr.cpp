#include <iostream>
using namespace std;

inline unsigned long long ncr(int n, int r) {
  unsigned long long res = 1;
  r = std::min(r, n - r);

  for (int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }

  return res;
}

int main() {
  cout << "Enter n upto 62, and r to calculate nCr: ";
  int n, r;
  cin >> n >> r;
  cout << "nCr = " << ncr(n, r) << '\n';

  return 0;
}
