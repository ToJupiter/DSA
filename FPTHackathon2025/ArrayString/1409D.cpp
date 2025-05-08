#include <iostream>
using namespace std;
long long sumd(long long n) {
  long long s = 0;
  while (n) s += n % 10, n /= 10;
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long ans = 0, p = 1;
    while (sumd(n) > s) {
      long long d = n % 10;
      ans += (10 - d) * p;
      n += 10 - d;
      n /= 10;
      p *= 10;
    }
    cout << ans << endl;
  }
  return 0;
}