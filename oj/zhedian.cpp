/*************************************************************************
    > File Name: zhedian.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月10日 星期一 19时07分39秒
 ************************************************************************/

#include <iostream>
#include <climits>

#define INF INT_MIN

using namespace std;

int main () {
    int flag[2] = {0,0};
    int n;
    int cur , pre;
    int count = 0;

    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cin >> cur;
        if (i == 0) {
            pre = cur;
            continue;
        }else {
            if (cur > pre) 
                flag[i%2] = 1;
            else 
                flag[i%2] = -1;

            if (flag[0] * flag[1] < 0)
                count++;
            pre = cur;
        }
    }

    cout << count << endl;

    return 0;
}
