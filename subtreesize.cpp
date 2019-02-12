//
// Created by user on 2/2/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;
typedef vector < vector <int> > vvi;
vi visited;
vi subTreeSize;
void calculateSubTreeSize(vvi & tree);
void dfs(int node, vvi & graph);

void calculateSubTreeSize(vvi & tree) {
    rep(i, 0, tree.size()) {
        if(!visited[i]) {
            dfs(i, tree);
        }
    }
}

void dfs(int node, vvi & graph) {
    visited[node] = 1;
    int s = 1;
    tr(graph[node], it) {
        if(!visited[*it]) {
            dfs(*it, graph);
            s += subTreeSize[*it];
        }
    }
    subTreeSize[node] = s;
}

int main() {
    int n;
    cin >> n;
    vvi tree(n);
    visited = vi(n, 0);
    subTreeSize = vi(n, 0);
    rep(i, 0, n-1) {
        int x , y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    calculateSubTreeSize(tree);
    rep(i, 0, n)
        cout << subTreeSize[i] << " : ";

}