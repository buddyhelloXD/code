/*************************************************************************
  O
    > File Name: tree_reconstruction.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月07日 星期五 20时37分06秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int EleType;

struct TreeNode {
    TreeNode *lChild;
    TreeNode *rChild;
    EleType value;
};

struct Tree {
    TreeNode *root;
};

enum {MAXSIZE = 1000};
EleType preArray[MAXSIZE];
EleType midArray[MAXSIZE];

TreeNode *CreatNode (EleType x) {
    TreeNode *temp = (TreeNode *) malloc (sizeof (TreeNode));
    temp->rChild = nullptr;
    temp->lChild = nullptr;
    temp->value = x;

    return temp;
}

void CreatTree (TreeNode **root , EleType *preArray , EleType *midArray , EleType length) {
    if (length <= 0)
        return;

    if (length == 1) {
        *root = CreatNode (*preArray);
        return;
    }

    int i;
    EleType rootValue = *preArray;
    EleType *midPtr = midArray;

    *root = CreatNode (rootValue);

    for (i = 0 ; i < length ; i++) {
        if (*(midArray+i) == rootValue)
            break;
    }
    
    CreatTree (&((*root)->lChild) , preArray+1 , midArray , i);;
    CreatTree (&((*root)->rChild) , preArray+1+i , midArray+1+i , length-1-i);
}

void PostTravelTree (TreeNode *root) {
    if (root != nullptr) {
        PostTravelTree (root->lChild);
        PostTravelTree (root->rChild);
        cout << root->value << " ";
    }
}

int main () {
    int n;
    EleType tempValue;
    int count = 0;
    Tree T;

    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cin >> tempValue;
        preArray[count++] = tempValue;
    }
    count = 0;

    for (int i = 0 ; i < n ; i++) {
        cin >> tempValue;
        midArray[count++] = tempValue;
    }
    CreatTree (&T.root , preArray , midArray , n);

    cout << "the root's value is " << T.root->value << endl;

    PostTravelTree (T.root);
    cout << endl;
}
