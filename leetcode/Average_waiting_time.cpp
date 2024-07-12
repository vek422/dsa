#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime(vector<vector<int>> &customers) {
  int start = customers[0][0];
  double sum = 0;
  for (auto &customer : customers) {
    if (start < customer[0]) {
      start = customer[0] + customer[1];
    } else {
      start = customer[1] + start;
    }
    sum += start - customer[0];
    cout << "diff " << (start - customer[0]) << endl;
  }
  cout << "sum " << sum << endl;
  return sum / customers.size();
}

int main() {
  int n;
  vector<vector<int>> customers;
  cin >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    customers.push_back({x, y});
  }
  cout << "\naverage time : " << averageWaitingTime(customers) << endl;
}
