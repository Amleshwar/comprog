//
// Created by user on 2/2/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;
typedef vector < set < int > > vsi;
vi subTreeSize;
vi parent;
vsi tree;
vi ans;


void update(int node) {

}

int query(int source) {

}

int dfs(int u, int p) {
    subTreeSize[u] = 1;
    tr(tree[u] , it) {
        if(*it != p)
            subTreeSize[u] += dfs(*it, u);
    }
    return subTreeSize[u];
}

int centroid(int u, int p, int n) {
    tr(tree[u], it) {
        if(*it != p && subTreeSize[*it] > n/2)
            return centroid(*it, u, n);
    }
    return u;
}

void build(int u, int p) {
    int n = dfs(u, p);
    int cent = centroid(u, p, n);
    cout << "Size aaya: " << n << endl;
    cout << "Centroid aaya " << cent << endl;
    if(p == -1) p = cent;
    parent[cent] = p;

    // removing the subtrees
    tr(tree[cent], it) {
        tree[*it].erase(cent);
        tree[cent].erase(*it);
        build(*it, cent);
    }
}
void addEdge(int u, int v) {
    tree[u].insert(v);
    tree[v].insert(u);
}

int main() {
    int n ;
    cin >> n;
    subTreeSize = vi(n);
    parent = vi(n);
    tree = vsi(n);
    ans = vi(n, numeric_limits<int> :: max());
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    build(0, -1);
    rep(i, 0, n)
        cout << i+1 << " : " << parent[i] + 1 << endl ;
    cout << endl;
}