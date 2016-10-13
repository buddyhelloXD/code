/*************************************************************************
    > File Name: bellman_ford.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月13日 星期四 22时19分12秒
 ************************************************************************/

#include <iostream>

using namespace std;

enum {maxnum = 100};
enum {maxint = 99999};

struct Edge {
    int u , v;
    int weight;
};

Edge edge[maxnum];
int res[maxnum];

int nodenum , edgenum , source;

void relax (int u , int v , int weight) {
    if (res[v] == maxint && res[u] == maxint)
        return;
    if (res[v] > res[u] + weight)
        res[v] = res[u] + weight;
}

bool bellman_ford () {
    for (int i = 0 ; i < nodenum-1 ; i++) {
        for (int j = 0 ; j < edgenum ; j++) {
            relax (edge[j].u , edge[j].v , edge[j].weight);
        }
    }
    for (int i = 0 ; i < nodenum ; i++) {
        if (res[edge[i].v] > res[edge[i].u] + edge[i].weight)
            return false;
    }
    return true;
}

int main () {
    cin >> nodenum >> edgenum >> source;

    for (int i = 0 ; i < nodenum ; i++) {
        res[i] = maxint;
    }
    res[source] = 0;
    for (int i = 0 ; i < edgenum ; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;
    }
    bellman_ford ();
    for (int i = 0 ; i < nodenum ; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
