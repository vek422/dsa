#include <bits/stdc++.h>
#include <vector>
using namespace std;

// given is 2d array with field marked as water and land the goal is to find the
// total number of islands in the array
bool explore(vector<vector<int>> &, int, int, vector<vector<int>> &);
int count_island(vector<vector<int>> &graph, int rows, int cols) {
  vector<vector<int>> visited(rows, vector<int>(cols, 0));
  int count = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (explore(graph, r, c, visited))
        count++;
    }
  }

  return count;
}

bool explore(vector<vector<int>> &graph, int r, int c,
             vector<vector<int>> &visited) {
  bool row_inbound = 0 <= r && r < graph.size();
  bool col_inbound = 0 <= c && c < graph[0].size();
  if (!row_inbound || !col_inbound)
    return false;

  if (graph[r][c] == 0)
    return false;

  if (visited[r][c])
    return false;
  visited[r][c] = 1;

  explore(graph, r + 1, c, visited);
  explore(graph, r, c + 1, visited);
  explore(graph, r - 1, c, visited);
  explore(graph, r, c - 1, visited);
  return true;
}

int main() {
  int r, c;
  cin >> r >> c;
  int tmp;
  vector<vector<int>> graph(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> tmp;
      graph[i][j] = tmp;
    }
  }

  cout << "count : " << count_island(graph, r, c);
}
