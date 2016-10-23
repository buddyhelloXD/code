/*************************************************************************
    > File Name: insertsort.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月24日 星期一 00时49分00秒
 ************************************************************************/

#include <iostream>

using namespace std;

void insertsort (int *arr , int start , int end) {
    if (end - start <= 1)
        return;
    for (int i = start+1 ; i < end ; i++) {
        int target = arr[i];
        int j = i;

        while (j > start && target < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = target;
    }
}

int main () {
    int arr[10];

    for (int i = 0 ; i < 10 ; i++)
        arr[i] = 9 - i;

    insertsort (arr , 0 , 10);
    for (int i = 0 ; i < 10 ; i++)
        cout << arr[i] << " ";
    cout << endl;
}
