/*************************************************************************
    > File Name: undraw_the_tree.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月19日 星期三 21时48分00秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

enum {MAXSIZE = 100};

char buf[MAXSIZE][MAXSIZE];
queue<char> q;

void dfs (int m , int n) {
    q.push (buf[m][n]);
    q.push ('(');
    if (buf[m+1][n] == '|') {
        int i;
        int r1,r2;
        vector<int> a;
        for (i = 0 ; ; i++) {
                if (buf[m+2][n+i] != '-')
                    break;
        }
        r1 = n+i-1;
        for (i = 0 ; ; i--) {
                if (buf[m+2][n+i] != '-')
                    break;
        }
        r2 = n+i+1;
        for (int j = r2 ; j <= r1 ; j++) {
            if (buf[m+3][j] != ' ')
                a.push_back (j);
        }
        for (int k = 0 ; k < a.size () ; k++) {
            dfs (m+3 , a[k]);
        }
    }
    q.push (')');
}

void printres () {
    cout << "(";
    while (!q.empty ()) {
        cout << q.front ();
        q.pop ();
    }
    cout << ")";
}

void readdata () {
    int i = 0;
    while (fgets(buf[i],MAXSIZE,stdin)) {
        if (buf[i][0] == '#')
            break;
        i++;
    }
}

int main () {
    readdata ();
    int f;
    for (int i = 0 ; i < MAXSIZE ; i++) {
        if (buf[0][i] != ' ') {
            f = i;
            break;
        }
    }
    dfs (0 , f);
    printres ();
    cout << endl;
}
