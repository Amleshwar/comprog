//
// Created by user on 1/26/2019.
//
#include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector <int> vi;
typedef pair < int, int > ii;

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int value, Node*left, Node* right) {
        this->value = value;
        this->left = left;
        this.right = right;
    }
};


typedef vector<Node*> vn;
bool canStillMove(vn & pointers);

void mergeKSortedList(vn & headsOfKLists) {
    Node* merged = new Node(0, NULL, NULL);
    vn pointers(headsOfKLists);
    int k = headsOfKLists.size();
    priority_queue<ii> queue;
    rep(i, 0, k)
        queue.push(make_pair(pointers[i].value, i));
    while(canStillMove(pointers)) {
        ii minElement = queue.top();
        merged -> right = new Node(minElement.first, merged, NULL);
        merged = merged -> right;
        pointers[minElement.second] = pointers[minElement.second]->right;
    }


}

bool canStillMove(vn & pointers) {
    rep(i, 0, pointers.size())
        if(pointers[i])
            return true;
    return false;
}