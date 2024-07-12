#include <bits/stdc++.h>
#include <cmath>
#include <tuple>
using namespace std;

int cheapest_flight(int n, vector<vector<int>> &flights, int src, int dst,
                    int k) {
  vector<float> prices(n, INFINITY);
  prices[src] = 0;

  for (int i = 0; i <= k; i++) {
    vector<float> tmp = prices;
    for (auto flight : flights) {
      int s, d, w;
      s = flight[0];
      d = flight[1];
      w = flight[2];
      if (prices[s] == INFINITY)
        continue;
      if (prices[s] + w < tmp[d])
        tmp[d] = prices[s] + w;
    }
    prices = tmp;
  }

  if (prices[dst] == INFINITY)
    return -1;
  return prices[dst];
}

int main() {
  int n, src, dst, k;
  cin >> n;
  vector<vector<int>> flights;
  int w, s, d;
  for (int i = 0; i < n; i++) {
    cin >> s >> d >> w;
    flights.push_back({s, d, w});
  }

  cin >> src >> dst >> k;

  cout << cheapest_flight(n, flights, src, dst, k) << endl;
}
