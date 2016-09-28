/*************************************************************************
    > File Name: Oil_Deposits.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年09月28日 星期三 20时11分16秒
 ************************************************************************/

#include <iostream>

using namespace std;

enum {COUNT = 105};

int m , n;
int pic[COUNT][COUNT];
int flag[COUNT][COUNT];

void dfs (int x , int y , int cnt) {
    if (x < 0 || y < 0 || x>= m , y>= n)
        return;
    if (pic[x][y] != '@' || flag[x][y] != 0)
        return;
    flag[x][y] = cnt;
    for (int i = -1 ; i <= 1 ; i++) {
        for (int j = -1 ; j <= 1 ; j++) {
            if (j == 0 && i == 0)
                continue;
            else
                dfs (x+i , y+j , cnt);
        }
    }
}

int main () {
    cin >> m >> n;

    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            char temp;
            cin >> temp;
            pic[i][j] = (int)temp;
        }
    }

    int cnt = 1;
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j< n ; j++) {
            if (flag[i][j] == 0 && pic[i][j] == '@') {
                 dfs (i , j , cnt);
                 cnt++;
            }
        }
    }
    cout << cnt - 1;
}
