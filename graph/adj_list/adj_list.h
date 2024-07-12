#ifndef ADJ_LIST
#define ADJ_LIST
#include <list>
#include <vector>
using namespace std;
class Graph {
public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void printGraph();
  int vertices;
  vector<list<int>> adjList;
};

#endif // !ADJ_LIST
