/*************************************************************************
    > File Name: package01.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年11月24日 星期四 23时45分45秒
 ************************************************************************/

#include<iostream>
#define MAXN 10000
#define MAXV 99999
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int s,n;
int w[MAXN],v[MAXN];
int dp[MAXN][MAXV];

void dp_func () {
    for (int i = 0 ; i <= s ; i++)
        dp[0][i] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= s ; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i][j]);
        }
    }
}

int main () {
    cin >> s >> n;

    for (int i = 0 ; i < n ; i ++) {
        cin >> w[i] >> v[i];
    }
    dp_func();
    cout << dp[n][s] << endl;
}
