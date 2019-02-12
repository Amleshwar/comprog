//
// Created by user on 1/26/2019.
//
# include <bits/stdc++.h>
# define rep(i, a, b) for(auto i = a; i < b; i++)
# define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vi;

bool findCycle(vi & successor) {
    int a = successor[0];
    int b = successor[successor[0]];
    while(a != b) {
        a = successor[a];
        b = successor[successor[a]];
    }
}