/*************************************************************************
    > File Name: the_tower_of_babylon.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月08日 星期六 08时36分02秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>

#define max(a , b) ((a)>(b)) ? (a) : (b);

enum {MAXSIZE = 100};

struct Block {
    int length;
    int width;
    int height;
};

Block blockArray[3*MAXSIZE];

int compare (const void *a , const void *b) {
    Block *tempA = (Block *)a;
    Block *tempB = (Block *)b;

    return tempA->length * tempA->width < tempB->length * tempB->width;
}

void swap (int &a , int &b) {
    int temp;

    temp = a;
    a = b;
    b =temp;
}

void MaxHeap (int *h , int length , int index) {
    int nonLeaf = length / 2;

    if (index > nonLeaf)
        return;
    
    if (h[index-1] >= h[index*2-1] && h[index-1] >= h[index*2+1-1])
        return;
    else {
        int maxIndex;
        if (h[index*2-1] > h[index*2+1-1]) {
            swap (h[index-1] , h[index*2-1]);
            maxIndex = index*2;
        }else {
            swap (h[index-1] , h[index*2+1-1]);
            maxIndex = index*2+1;
        }
        MaxHeap (h , length , maxIndex);
    }
}

int GetMaxValue (int *h , int length) {
    int nonLeaf = length / 2;

    for (int i = nonLeaf ; i >= 1 ; i--) {
        MaxHeap (h , length , i);
    }
    return h[0];
}

int main () {
    int n;
    int tempLen , tempWid , tempHei;
    int count = 0;
    int h[3*MAXSIZE];

    while (std::cin >> n) {
        if (n == 0)
            break;
        for (int i = 0 ; i < n ; i++) {
            std::cin >> tempLen;
            std::cin >> tempWid;
            std::cin >> tempHei;

            blockArray[3*count].height = tempLen;
            blockArray[3*count].length = tempWid;
            blockArray[3*count].width = tempHei;
            blockArray[3*count+1].height = tempWid;
            blockArray[3*count+1].length = tempLen;
            blockArray[3*count+1].width = tempHei;
            blockArray[3*count+2].height = tempHei;
            blockArray[3*count+2].length = tempLen;
            blockArray[3*count+2].width = tempWid;

            count++;
        }
        qsort (blockArray , 3*count , sizeof (Block) , compare);

        h[0] = blockArray[0].height;
        for (int i = 1 ; i < 3*count ; i++) {
            h[i] = blockArray[i].height;
            for (int j = 0 ; j <= i-1 ; j++) {
                if ((blockArray[i].length < blockArray[j].length && 
                            blockArray[i].width < blockArray[j].width)
                            || (blockArray[i].length < blockArray[j].width && 
                            blockArray[i].width < blockArray[j].length)) {
                    h[i] = max (h[i] , h[j]+blockArray[i].height);
                }
            }
        }

        int maxHeight = GetMaxValue (h , 3*count);
        std::cout << "the max height is : " << maxHeight << std::endl;
        count = 0;
    }
}
