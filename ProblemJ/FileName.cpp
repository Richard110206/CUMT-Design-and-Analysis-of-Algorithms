#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int INF = 0x3f3f3f3f;

struct Node {
    int u;
    int dist;
    int score;

    bool operator<(const Node& other) const {
        if (dist != other.dist) return dist > other.dist;
        return score < other.score;  
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, start, end;
    std::cin >> n >> m >> start >> end;

    std::vector<int> val(n);
    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        graph[x].push_back(std::make_pair(y, z));
        graph[y].push_back(std::make_pair(x, z));
    }

    std::vector<int> dist(n, INF);
    std::vector<int> score(n, -INF);

    std::priority_queue<Node> pq;

    dist[start] = 0;
    score[start] = val[start];
    pq.push({ start, 0, score[start] });

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int u = cur.u;
        int d = cur.dist;
        int s = cur.score;

        if (d > dist[u]) continue;
        if (d == dist[u] && s < score[u]) continue;

        for (std::size_t i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            int nd = d + w;
            int ns = s + val[v];

            if (nd < dist[v]) {
                dist[v] = nd;
                score[v] = ns;
                pq.push({ v, nd, ns });
            }
            else if (nd == dist[v] && ns > score[v]) {
                score[v] = ns;
                pq.push({ v, nd, ns });
            }
        }
    }

    std::cout << dist[end] << ' ' << score[end] << '\n';

    return 0;
}