/*************************************************************************
    > File Name: youxi.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月10日 星期一 22时08分49秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int x , y;

struct node {
    int start;
    int end;
};

struct point {
    int x;
    int y;
    point (int a = 0 , int b = 0) : x(a),y(b) {}
};

node g[110][110];
int t[110][110];
int f[110][110];
point p[110][110];

queue<point> p_queue;

bool is_in (int a , int b) {
    if (a>= 1 && a <= y && b>= 1 && b <= x)
        return true;
    else
        return false;
}

int __bfs_aux (int x , int y , point par) {
    int curTime = t[par.x][par.y] + 1;

    if (is_in (x , y) && f[x][y] == 0) {
        node tempNode = g[x][y];
        if (tempNode.start == 0 && tempNode.end == 0) {
ok:
            p_queue.push (point (x , y));
            f[x][y] = -1;
            t[x][y] = t[par.x][par.y] + 1;
            p[x][y] = point (par.x , par.y);
            return 1;
        }else {
            if (tempNode.start > curTime || tempNode.end < curTime) {
                goto ok;             
            }else {
                return 0;
            }
        }
    }else {
        return 0;
    }
}

void zerodf () {
    for (int i = 1 ; i <= x ; i++) {
        for (int j = 1 ; j <= y ; j++) {
            f[i][j] = 0;
        }
    }
}

void bfs () {

    p_queue.push (point (1,1));
    t[1][1] = 0;
    f[1][1] = -1;

//    for (int i = 0 ; i < 10 ; i++) {
    while (!p_queue.empty ()) {
        if (t[x][y] != 0) {
            cout << t[x][y] << endl;
            return;
        }

        point temp = p_queue.front ();
        p_queue.pop ();
        int x1 = temp.x;
        int y1 = temp.y;
        point par(x1 , y1);
        
        int res1 = __bfs_aux (x1+1 , y1 , par);
        int res2 = __bfs_aux (x1-1 , y1 , par);
        int res3 = __bfs_aux (x1 , y1+1 , par);
        int res4 = __bfs_aux (x1 , y1-1 , par);

        if (!(res1 || res2 || res3 || res4)) {
            point t_Par = p[x1][y1];
            p_queue.push (point (t_Par.x , t_Par.y));
            t[t_Par.x][t_Par.y] = t[x1][y1] + 1;
//            memset (f , 0 , sizeof (f));
            if (p_queue.size () == 1)
                zerodf ();
            f[x1][y1] = 0;
            f[t_Par.x][t_Par.y] = -1;
        }else {
             f[x1][y1] = 1;
        }
    }
}

int main () {
    int m;

    cin >> x >> y >> m;

    for (int i = 0 ; i < m ; i++) {
        int a , b , c , d;
        cin >> a >> b >> c >> d;

        g[a][b].start = c;
        g[a][b].end = d;
    }
    bfs ();

/*    for (int i = 0 ; i < x ; i++) {
        for (int j = 0 ; j < y ; j++) {
            cout << t[i+1][j+1] << " ";
        }
        cout << endl;
    }*/
}
