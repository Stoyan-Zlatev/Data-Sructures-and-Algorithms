#include <bits/stdc++.h>

using namespace std;

const size_t MAX_SIZE = 2 * 1e5 + 5;
vector<pair<size_t, pair<size_t, size_t>>> graph;
size_t parent[MAX_SIZE];
size_t counter, tempMax, tempMin;
pair<size_t, size_t> balancedTime;

size_t findVertex(const size_t &v) {
    if (v == parent[v]) {
        return v;
    }
    parent[v] = findVertex(parent[v]);
    return parent[v];
}

bool unionVertexes(const size_t &from, const size_t &to, const size_t &distance) {
    size_t u = findVertex(from);
    size_t v = findVertex(to);

    if (u == v) {
        return false;
    }

    tempMax = max(tempMax, distance - tempMin);
    counter++;
    parent[v] = u;
    return true;
}

void resetParents(const size_t &N) {
    for (size_t i = 1; i <= N; ++i) {
        parent[i] = i;
    }
}

void kruskal() {
    size_t u, v;
    sort(graph.begin(), graph.end());
    for (size_t i = 0; i < graph.size(); i++) {
        u = findVertex(graph[i].second.first);
        v = findVertex(graph[i].second.second);
        if (u != v) {
            unionVertexes(u, v, graph[i].first);
        }
    }
}

int main() {
    size_t N, M, from, to, speed;
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> speed;
        graph.push_back({speed, {from, to}});
    }

    sort(graph.begin(), graph.end());
    balancedTime = {-1, LLONG_MAX};
    for (auto i = graph.begin(); i != graph.end(); ++i) {
        tempMax = 0;
        tempMin = i->first;
        counter = 1;
        bool flag = false;
        resetParents(N);

        for (auto j = i; j != graph.end(); ++j) {
            if (unionVertexes(j->second.first, j->second.second, j->first) &&
                tempMax > balancedTime.second) {
                flag = true;
                break;
            }
        }

        if (!flag && counter == N && tempMax < balancedTime.second) {
            balancedTime = {tempMin, tempMax};
        }
    }

    cout << balancedTime.first << " " << balancedTime.first + balancedTime.second;
    return 0;
}
