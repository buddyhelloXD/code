/*************************************************************************
    > File Name: fibonacii_dijkstra.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月18日 星期二 00时32分54秒
 ************************************************************************/

#include <iostream>
#include <climits>
#include <cstring>

typedef int EleType;
typedef bool InsertType;

struct FibNode {
    FibNode *parent;
    FibNode *child;
    FibNode *right;
    FibNode *left;
    EleType value;
    bool marked;
    int degree;

    FibNode (int k) : value(k) {
        parent = nullptr;
        child = nullptr;
        right = nullptr;
        left = nullptr;
        marked = false;
        degree = 0;
    }
};

class FibHeap {
    public:
        friend class FibNode;
        FibHeap () : min(nullptr),nodeNum(0) {}
        void InsertNode (EleType );
        void InsertNode (FibNode *);
        EleType ExtractMin ();
    public:
        void __InsertNode (FibNode * , InsertType);
        size_t __GetDn ();
        void __DeleteNodeFromList (FibNode *);
        void __ExtractMin ();
        void __InsertChild (FibNode * , FibNode *);
        void __FixMin ();
        FibNode *min;
        size_t nodeNum;
};

void FibHeap::InsertNode (EleType k) {
    FibNode *node = new FibNode (k);
    __InsertNode (node , 1);
}

void FibHeap::InsertNode (FibNode *node) {
    __InsertNode (node , 1);
}

void FibHeap::__InsertNode (FibNode *node , InsertType k) {
    if (node == nullptr)
        return;
    if (min == nullptr) {
        min = node;
        min->right = min;
        min->left = min;
    }else {
        FibNode *tmp = min;
        while (tmp->right != min) 
            tmp = tmp->right;
        node->right = tmp->right;
        tmp->right->left = node;
        tmp->right = node;
        node->left = tmp;
    }
    if (node->value < min->value)
        min = node;
    if (k)
        nodeNum++;
}

void FibHeap::__DeleteNodeFromList (FibNode *node) {
    if (node == nullptr)
        return;
    node->right->left = node->left;
    node->left->right = node->right;
}

EleType FibHeap::ExtractMin () {
    if (min != nullptr) {
        EleType minValue = min->value;
        FibNode *x = min->child;
        //if (x == nullptr)
        //    std::cout << "x is nullptr" << std::endl;
        FibNode *pre;
        if (x != nullptr) {
            if (x != x->right) {
                FibNode *z = x->right;
                while (z != x) {
                    pre = z;
                    z = z->right;
                    __DeleteNodeFromList (pre);
                    __InsertNode (pre,0);
                    pre->parent = nullptr;
                }
            }
            min->child = nullptr;
            x->parent = nullptr;
            __InsertNode (x,0);
        }
        if (min == min->right) {
            delete min;
            min = nullptr;
            nodeNum = 0;
        }else {
            pre = min->right;
            __DeleteNodeFromList (min);
            delete (min);
            min = pre;

            /*FibNode *haha = min->right;
            std::cout << "haha's value is : " << min->value << " ";
            std::cout << "haha's degree is : " << min->degree << " ";
            if (haha != nullptr) {
                while (haha != min) {
                    std::cout << "haha's value is : " << haha->value << " ";
                    std::cout << "haha's degree is : " << haha->degree << " ";
                    haha = haha->right;
                }
                std::cout << std::endl;
            }else {
                std::cout << "caonima" << std::endl;
            }*/

            __FixMin ();
            __ExtractMin ();
            nodeNum--;
        }
        return minValue;
    }else {
        return -1;
    }
}

void FibHeap::__ExtractMin () {
    size_t Dn = __GetDn ();
    FibNode *nodeArr[Dn];

    for (int i = 0 ; i < Dn ; i++)
        nodeArr[i] = nullptr;

//    std::cout << "min's value is : " << min->value << std::endl; 

    nodeArr[min->degree] = min;
    FibNode *tmpNode = min->right;
    while (tmpNode != min) {
        FibNode *x = tmpNode;
        size_t d = tmpNode->degree;
        tmpNode = tmpNode->right;
        while (nodeArr[d] != nullptr) {
            
            FibNode *y = nodeArr[d];
            if (x->value > y->value) {
                FibNode *tmp = x;
                x = y;
                y = tmp;
            }
            __DeleteNodeFromList (y);
            __InsertChild (x , y);
            nodeArr[d] = nullptr;
            d++;
        }
        nodeArr[d] = x;
    }
}

void FibHeap::__InsertChild (FibNode *root , FibNode *node) {
    FibNode *tmp = root->child;
    if (tmp == nullptr) {
        node->parent = root;
        root->child = node;
        node->left = node;
        node->right = node;
    }else {
        node->right = tmp->right;
        node->left = tmp;
        tmp->right->left = node;
        tmp->right = node;
        node->parent = root;
    }
    root->degree++;
}

void FibHeap::__FixMin () {
    EleType minValue = min->value;
    FibNode *minNode = min;
    FibNode *tmpNode = min->right;

    while (tmpNode != min) {
        if (tmpNode->value < minValue) {
            minValue = tmpNode->value;
            minNode = tmpNode;
        }
        tmpNode = tmpNode->right;
    }
    min = minNode;
}

size_t FibHeap::__GetDn () {
    size_t count = 0;
    size_t tmp = nodeNum;
        
    while (tmp != 0) {
        tmp /= 2;
        count++;
    }
    return count;
}

int main () {
    FibHeap fibtest;
    for (int i = 0 ; i < 10 ; i++) {
        fibtest.InsertNode (i);
    }

    //std::cout << (fibtest.min)->value << std::endl;
    //std::cout << fibtest.nodeNum << std::endl;
    
    //fibtest.__ExtractMinAux (fibtest.min , fibtest.min->right);
/*    FibNode *tmp = fibtest.min->right;
    std::cout << fibtest.min->value << " ";
    while (tmp != fibtest.min) {
        std::cout << tmp->value << " ";   
        tmp = tmp->right;
    }*/
    //for (int i = 0 ; i < 10 ; i++) {
    //}
    for (int i = 0 ; i < 10 ; i++) {
        std::cout << fibtest.ExtractMin () << std::endl;
    }
    /*std::cout << "value is : " << fibtest.min->value << std::endl;
    std::cout << "degree is : " << fibtest.min->degree << std::endl;
        std::cout << fibtest.ExtractMin () << std::endl;
    std::cout << "value is : " << fibtest.min->value << std::endl;
    std::cout << "degree is : " << fibtest.min->degree << std::endl;*/
}
