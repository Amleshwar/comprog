//
// Created by user on 1/26/2019.
//
#include <bits/stdc++.h>

# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
# define N 100
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<ii> > vvii;
vi dist(N, numeric_limits<int>::max());

void dijkstra(vvii &graph, int start) {
    dist[start] = 0;
    set<ii> s;
    s.insert({0, start});
    while (!s.empty()) {
        ii top = *s.begin();
        int u = top.second;
        s.erase(s.begin());
        cout << top.first << " : " << top.second << endl;
        tr(graph[u], it) {
            int v = (*it).first;
            int cost = (*it).second;
            cout << "Dest: " << v << " Cost: " << cost << endl;
            if (dist[v] > dist[u] + cost) {
                if (dist[v] != numeric_limits<int>::max())
                    s.erase(s.find({dist[v], v}));
                cout << "Reslax " << (dist[u] + cost) << " : " << v << endl;
                dist[v] = dist[u]+cost;
                s.insert({dist[u] + cost, v});
            }
        }

    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vvii graph(n);
    rep(i, 0, m) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});

    }
    cout << "HEREW" <<endl;
    dijkstra(graph, 0);
    cout << "HI" << endl;
    rep(i, 0, n)
        cout << dist[i] << endl;
}


