/*************************************************************************
    > File Name: dijkstra.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年11月24日 星期四 00时52分58秒
 ************************************************************************/

#include<iostream>
#define MAXN 1000
#define INF 9999
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int cnte,cntn;
int d[MAXN];
int w[MAXN][MAXN] , v[MAXN];

void dijkstra () {
    for (int i = 0 ; i < cntn ; i++) d[i] = INF;
    d[0] = 0;
    for (int i = 0 ; i < cntn ; i++) {
        int m = INF,x;
        for (int y = 0 ; y < cntn ; y++) if (!v[y] && d[y] <= m) m = d[x=y];
        v[x] = 1;
        for (int y = 0 ; y < cntn ; y++) d[y] = min(d[y],d[x]+w[x][y]);
    }
}

int main () {
    cin >> cnte >> cntn;

    for (int i = 0 ; i < cntn ; i++)
        for (int j = 0 ; j < cntn ; j++)
            w[i][j] = INF;
    for (int i = 0 ; i < cnte ; i++) {
        int x,y,t;
        cin >> x >> y >> t;
        w[x][y] = t;
    }
    dijkstra ();
    for (int i = 0 ; i < cntn ; i++)
        cout << d[i] << " ";
    cout << endl;
}
