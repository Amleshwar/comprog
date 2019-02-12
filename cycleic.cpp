//
// Created by user on 1/12/2019.
//

#include <bits/stdc++.h>
# define all(c) c.begin(), c.end()
# define rep(i, a, b) for(__typeof(a) i = a; i < b; i++)
# define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define MAX 1000
using namespace std;
typedef vector < int > vi;
typedef vector < vector <int> > vvi;
typedef pair < int, int > ii;
int marked[MAX] = {0};
int S[MAX] = {0};
int timer;
// Function declaration
void dfs(vvi &graph, int v);
void topSort(vvi &graph);

void dfs(vvi &graph, int v) {
    marked[v] = 1;
    rep(i, 0, graph[v].size()) {
        if(!marked[graph[v][i]]) {
            dfs(graph, graph[v][i]);
        }
    }
    S[timer] = v;
    cout << "Came to vertex : " << v;
    cout << " timer = " << timer << endl;
    timer--;
}

void topSort(vvi &graph) {
    rep(i, 0, graph.size()) {
        if(!marked[i])
            dfs(graph, i);
    }
}
int main() {
    int n ,m;
    cin >> n >> m;
    timer = n;
    vvi graph(n+1);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    topSort(graph);
    rep(i, 0, n+1) {
        cout << S[i] << " -> " ;
    }
    return 0;
}