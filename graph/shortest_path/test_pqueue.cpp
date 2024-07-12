#include <iostream>
#include <queue>
using namespace std;

struct PairComparator {
  bool operator()(pair<int, int> left, pair<int, int> right) {
    return left.second > right.second;
  }
};
int main() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator>
      minHeap;

  int f, s;
  while (cin >> f >> s) {
    minHeap.push({f, s});
  }
  cout << "----------------" << endl;
  while (!minHeap.empty()) {
    cout << minHeap.top().first << " " << minHeap.top().second << endl;
    minHeap.pop();
  }
}
