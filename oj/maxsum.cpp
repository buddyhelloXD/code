/*************************************************************************
    > File Name: maxsum.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月22日 星期六 22时12分58秒
 ************************************************************************/

#include <iostream>

using namespace std;

enum {MAXSIZE = 1000};
int a[MAXSIZE];

int main () {
    int n;
    int sum , res;
    cin >> n;

    for (int i = 0 ; i < n ; i++)
        cin >> a[i];

    sum = a[0];
    res = a[0];
    for (int i = 1 ; i < n ; i++) {
        if (sum > 0)
            sum += a[i];
        else 
            sum = a[i];
        if (sum > res)
            res = sum;
    }
    cout << res << endl;
}
