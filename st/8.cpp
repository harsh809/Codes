#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Edge {
 public:
  int wt;
  int v;
  Edge(int nb, int w) {
    v = nb;
    wt = w;
  }
};

void dfs_printPaths(vector<vector<Edge *>> &graph, int src, vector<bool> &vis,
                    int endNode, int &count, string path) {
  if (src == endNode) {
    path += "N" + to_string(endNode);
    cout << "Path " << count++ << ": " << path << endl;
    return;
  }
  vis[src] = true;
  for (Edge *e : graph[src]) {
    if (vis[e->v] == false)
      dfs_printPaths(graph, e->v, vis, endNode, count,
                     path + "N" + to_string(src) + " -> ");
  }
  vis[src] = false;
}

void display_graph(vector<vector<Edge *>> &graph) {
  int n = graph.size();
  cout << "\n\nGraph in Edge Representation is:\n";
  for (int i = 0; i < n; i++) {
    cout << endl << "Vertex " << i << " ->";
    for (Edge *e : graph[i]) cout << "(" << e->v << "," << e->wt << "), ";
  }
  cout << endl << endl;
}

int main() {
  cout << "Enter the number of Decision nodes (Size of Matrix):";
  int n;
  cin >> n;
  cout << "Please input the graph matrix:\n";
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> mat[i][j];
  vector<vector<Edge *>> graph(n, vector<Edge *>());
  int P = 1;
  int e = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (mat[i][j] == 1) {
        graph[i].push_back(new Edge(j, 1));
        e++;
      }
  display_graph(graph);
  vector<bool> vis(n, false);
  int count = 1;
  cout << "Cyclomatic Complexity is: " << e - n + 2 * P << endl;
  cout << "\nPaths are:\n";
  dfs_printPaths(graph, 0, vis, n - 1, count, "");
  cout << endl;
  return 0;
}
