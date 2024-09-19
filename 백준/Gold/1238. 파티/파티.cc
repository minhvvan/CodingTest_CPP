#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Graph {
public:
  Graph(int, int);
  int solution(int);

private:
  using Edge = std::pair<int, int>;

  std::vector<std::vector<Edge>> graph_;
  std::vector<std::vector<Edge>> reverse_graph_;
  int num_vertices_;

  void compute_minimum_distance_(const std::vector<std::vector<Edge>> &,
                                 std::vector<int> &, int);
};

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_vertices = 0, num_edges = 0, target = 0;
  std::cin >> num_vertices >> num_edges >> target;

  Graph graph = Graph(num_vertices, num_edges);
  std::cout << graph.solution(target) << '\n';

  return 0;
}

Graph::Graph(int num_vertices, int num_edges)
    : graph_(std::vector<std::vector<Edge>>(num_vertices + 1)),
      reverse_graph_(std::vector<std::vector<Edge>>(num_vertices + 1)),
      num_vertices_(num_vertices) {
  int u = 0, v = 0, weight = 0;
  while (num_edges--) {
    std::cin >> u >> v >> weight;
    graph_[u].push_back({v, weight});
    reverse_graph_[v].push_back({u, weight});
  }
}

int Graph::solution(int target) {
  std::vector<int> final_distance(num_vertices_ + 1, 0);
  compute_minimum_distance_(graph_, final_distance, target);
  compute_minimum_distance_(reverse_graph_, final_distance, target);

  return *std::max_element(final_distance.begin(), final_distance.end());
}

void Graph::compute_minimum_distance_(
    const std::vector<std::vector<Edge>> &graph,
    std::vector<int> &final_distance, int target) {
  int inf = std::numeric_limits<int>::max();
  std::vector<int> distance(num_vertices_ + 1, inf);

  auto cmp = [](const Edge &e1, const Edge &e2) {
    return e1.second > e2.second;
  };
  std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);

  pq.push({target, 0});
  distance[target] = 0;

  while (!pq.empty()) {
    auto [current_vertex, current_distance] = pq.top();
    pq.pop();

    if (distance[current_vertex] < current_distance)
      continue;

    for (auto [adjacent_vertex, weight] : graph[current_vertex]) {
      int new_distance = current_distance + weight;
      if (new_distance > distance[adjacent_vertex])
        continue;

      pq.push({adjacent_vertex, new_distance});
      distance[adjacent_vertex] = new_distance;
    }
  }

  for (int i = 1; i <= num_vertices_; i++)
    final_distance[i] += distance[i];
}
