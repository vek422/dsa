#include <bits/stdc++.h>
using namespace std;

int find_center(vector<vector<int>> &edges) {
  vector<int> nodes(edges.size() + 1, 0);
  for (auto edge : edges) {
    nodes[edge[0]]++;
    nodes[edge[1]]++;
  }

  for (int i = 1; i < nodes.size(); i++) {
    if (nodes[i] == edges.size())
      return i;
  }
  return -1;
}

int main() {

  vector<vector<int>> edges;
  int a, b;
  while (cin >> a >> b) {
    edges.push_back({a, b});
  }
  cout << "center : " << find_center(edges);
}
