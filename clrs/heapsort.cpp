/*************************************************************************
    > File Name: heapsort.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月23日 星期日 23时51分49秒
 ************************************************************************/

#include <iostream>

using namespace std;

void swap (int &a , int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heap_max (int *arr , int length , int pos) {
    int lChild = pos*2;
    int rChild = pos*2+1;
    int maxnode = pos;

    if (lChild <= length) {
        if (arr[lChild-1] > arr[maxnode-1])
            maxnode = lChild;
    }
    if (rChild <= length) {
        if (arr[rChild-1] > arr[maxnode-1])
            maxnode = rChild;
    }
    if (maxnode != pos) {
        swap (arr[maxnode-1] , arr[pos-1]);
        heap_max (arr , length , maxnode);
    }
}

void build_heap (int *arr , int length) {
    int half = length/2;

    for (int i = half ; i >= 1 ; i--) {
        heap_max (arr , length , i);
    }
}

void heapsort (int *arr , int length) {
    build_heap (arr , length);

    for (int i = 0 ; i < length ; i++) {
        swap (arr[0] , arr[length-1-i]);
        heap_max (arr , length-1-i , 1);
    }
}

int main () {
    int arr[30];

    for (int i = 0 ; i < 30 ; i++)
        arr[i] = 29 - i;

    heapsort (arr , 30);

    for (int i = 0 ; i < 30 ; i++)
        cout << arr[i] << " ";
    cout << endl;
}
