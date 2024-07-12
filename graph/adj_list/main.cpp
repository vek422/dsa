#include "adj_list.h"
#include <iostream>
using namespace std;
int main() {
  int size;
  cout << "Size Of Graph : ";
  cin >> size;
  Graph g(size);
  int flag = 1;
  int tmpsrc, tmpdest;
  while (flag) {
    cout << "\nsrc dest" << endl;
    cin >> tmpsrc >> tmpdest;
    g.addEdge(tmpsrc, tmpdest);
    cout << "continue(1/0)? : ";
    cin >> flag;
  }

  g.printGraph();
}
