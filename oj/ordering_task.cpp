/*************************************************************************
    > File Name: ordering_task.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月30日 星期五 21时53分40秒
 ************************************************************************/

//拓扑排序最重要的一点是将入度为0的解决掉

#include <iostream>

using namespace std;

enum {MAX = 100};
int G[MAX][MAX];
int m , n;
int c[MAX];
int count[MAX];
int number = 0;

bool toposort (int x) {
    if (c[x] != 0)
        return true;
    c[x] = -1;
    for (int i = 1 ; i <= m ; i++) {
        if (G[x][i]) {
            if (c[i] < 0)
                return false;
            if (c[i] > 0)
                continue;
            if (!toposort (i))
                return false;
        }
    }
    c[x] = 1;
    count[number++] = x;
    return true;
}

int main () {
    cin >> m >> n;

    for (int i = 0 ; i < n ; i++) {
        int x , y;
        cin >> x >> y;
        G[x][y] = 1;
    }

    for (int i = 1 ; i <= m ; i++) {
            if (!toposort (i))
                cerr << "error" << endl;
    }
    for (int i = m-1 ; i >=0 ; i--)
        cout << count[i] << " ";
    cout << endl;
}
