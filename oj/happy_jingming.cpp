/*************************************************************************
    > File Name: happy_jingming.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月20日 星期四 21时53分25秒
 ************************************************************************/

#include <iostream>

#define max(c,d) (((c)>(d))?(c):(d))

using namespace std;

int f[30][30020];
int a[30];
int b[30];

int m , n;

void dp () {
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            f[i][j] = f[i-1][j];
            if (j >= a[i]) {
                f[i][j] = max (f[i][j] , f[i-1][j-a[i]]+a[i]*b[i]);
            }
        }
    }
}

int main () {
    cin >> m >> n;

    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> b[i];
    }
    dp ();
    cout << f[n][m] << endl;
}
