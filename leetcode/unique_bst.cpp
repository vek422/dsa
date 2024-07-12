#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
using namespace std;

unordered_map<int, int> memo;
const int MOD = pow(10, 9) + 7;
int numTrees(int N) {
  if (N == 0 || N == 1)
    return 1;
  if (memo.count(N))
    return memo[N];
  int count = 0;
  for (int i = 1; i <= N; i++) {
    count = (count + (numTrees(i - 1) * numTrees(N - i)) % MOD) % MOD;
  }
  memo[N] = count;
  return count;
}

int main() {

  int n;
  while (cin >> n)
    cout << numTrees(n) << endl;
  return 0;
}
