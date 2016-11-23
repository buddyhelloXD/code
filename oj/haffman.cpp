/*************************************************************************
    > File Name: haffman.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年11月23日 星期三 18时54分03秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#define MAXSIZE 1000

using namespace std;

struct node {
    node *lchd;
    node *rchd;
    int color;
    float percentage;
};

int n;
node *q[MAXSIZE];

node *getnode (float a) {
    node *tmp = (node *) malloc (sizeof (node));
    tmp->lchd = nullptr;
    tmp->rchd = nullptr;
    tmp->color = 0;
    tmp->percentage = a;

    return tmp;
}

int cmp (const node *a , const node *b) {
    return (a->percentage < b->percentage);
}

void haffman () {
    int cnt = n-1;
    for (int i = 0 ; i < cnt ; i++) {
        node *tmp = getnode(q[0]->percentage + q[1]->percentage);
        tmp->lchd = q[0];
        tmp->rchd = q[1];
        for (int j = 0 ; j < n-2-i ; j++)
            q[j] = q[j+2];
        int index = 0;
        for (int j = 0 ; j < n-2-i ; j++) {
            if (q[j]->percentage > tmp->percentage) 
                break;
            index++;
        }
        for (int j = n-2-i ; j >= index ; j--)
            q[j+1] = q[j];
        q[index] = tmp;
    }
}

void getcolor (node *root) {
    if (root != nullptr) {
        if (root->lchd != nullptr) { 
            root->lchd->color = 0;
            getcolor (root->lchd);
        }
        if (root->rchd != nullptr) {
            root->rchd->color = 1;
            getcolor (root->rchd);
        }
    }
}

void travel_tree (node *root , string a) {
    string tmp = a;
    if (root != nullptr) {
        if (root != q[0]) {
            tmp += root->color+'0';
            if (root->rchd == nullptr && root->lchd == nullptr)
                cout << root->percentage << " " << tmp << endl;
        }
        travel_tree (root->lchd , tmp);
        travel_tree (root->rchd , tmp);
    }
}

int main () {
    cin >> n;
    float per;
    
    for (int i = 0 ; i < n ; i++) {
        cin >> per;
        q[i] = getnode(per);
    }

    sort (q,q+n,cmp);

    for (int i = 0 ; i < n ; i++)
        cout << q[i]->percentage << " ";
    cout << endl;
    cout << endl;

    haffman();
    getcolor (q[0]);
    travel_tree (q[0] , string(""));
}
