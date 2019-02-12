//
// Created by user on 1/26/2019.
//
# include <bits/stdc++.h>

# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
# define N 10000
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vi color(N, -1);
vi visited(N, 0);

bool twoColorable(vvi &graph);

bool twoColorable(vvi &graph, int node);


bool twoColorable(vvi &graph) {
    bool isTwoColorable = true;
    rep(i, 0, graph.size()) {
        if (!visited[i])
            isTwoColorable && twoColorable(graph, i);
    }
    return isTwoColorable;
}

bool twoColorable(vvi &graph, int node) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    visited[node] = 1;
    while (!q.empty()) {
        int nodeBeingExplored = q.front();
        q.pop();
        tr(graph[nodeBeingExplored], it) {
            cout << "The node being explored : " << nodeBeingExplored << " edge to : " << *it << endl;
            if (color[*it] == -1)
                color[*it] = !color[nodeBeingExplored];
            else if (color[*it] == color[nodeBeingExplored])
            {
                cout << "HERE :" << nodeBeingExplored << " " << *it << endl;
                return false;
            }
            if(!visited[*it]) {
                visited[*it] = 1;
                q.push(*it);
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vvi graph(n);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    rep(i, 0, n) {
        tr(graph[i], it) {
            cout << i << " -> " << *it << ", " ;
        }
        cout << endl;
    }
    cout << "Is the graph two colorable: " << twoColorable(graph,0);
    rep(i, 0, n)
        cout << "the color of node " << i << " is : " << color[i] << endl;
}
