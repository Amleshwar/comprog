//
// Created by user on 2/7/2019.
//
#include <bits/stdc++.h>
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector <int> vi;
vi fail;

void computeFailure(vi & fail, string pattern) {
    int j = -1;
    rep(i, 0, fail.size()) {
        fail[i] = j;
        while(j >= 0 && pattern[i] != pattern[j])
            j = fail[j];
        j++;
    }
}

void kmp(string text, string pattern) {
    int j = 0;
    rep(i, 0, text.length()) {
        while(j > 0 && text[i] != pattern[j])
            j = fail[j];
        if(j = pattern.length())
            cout << "Found the pattern: " << endl;
        j++;
    }
}

int main() {
    string pattern = "abracadabra";
   /* cout << "Enter the pattern : " << endl;
    cin >> pattern;
   */ fail = vi(pattern.length(), 0);
    computeFailure(fail, pattern);
    rep(i, 0, fail.size())
        cout << fail[i] << " : " ;
    cout << endl;
}