#include <bits/stdc++.h>
using namespace std;
int findJudge(int n, vector<vector<int>> &trust) {
  vector<pair<int, int>> degree(n + 1, {0, 0});
  // pair first value: indegree
  //      second value : outdegree
  for (auto i : degree) {
    cout << i.first << " " << i.second << endl;
  }
  for (auto edge : trust) {
    // increase the outdegree of first person
    degree[edge[0]].second = degree[edge[0]].second + 1;
    degree[edge[1]].first = degree[edge[1]].first + 1;
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << degree[i].first << " " << degree[i].second << endl;
    if (degree[i].first == n - 1 && degree[i].second == 0) {
      return i;
    }
  }
  return -1;
}
int main() {
  int n;
  int a, b;
  cin >> n;
  vector<vector<int>> trust;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    trust.push_back({a, b});
  }
  cout << findJudge(n, trust);
}
