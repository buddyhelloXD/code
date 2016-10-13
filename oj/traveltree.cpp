/*************************************************************************
    > File Name: traveltree.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月12日 星期三 22时57分10秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <stack>

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

struct TreeNodePlus {
    TreeNodePlus *rChild;
    TreeNodePlus *lChild;
    EleType value;
    int visited;
};

struct TreePlus {
    TreeNodePlus *root;
};

TreeNodePlus *CreateTreeNodePlus (EleType k) {
    TreeNodePlus *temp = (TreeNodePlus *) malloc (sizeof (TreeNodePlus));

    temp->lChild = nullptr;
    temp->rChild = nullptr;
    temp->value = k;
    temp->visited = 0;

    return temp;
}

void CreateTreePlus (TreeNodePlus **root) {
    int t;

    cin >> t;
    if (t != 0) {
        *root = CreateTreeNodePlus (t);
        CreateTreePlus (&((*root)->lChild));
        CreateTreePlus (&((*root)->rChild));
    }
}

TreeNode *CreateTreeNode (EleType k) {
    TreeNode *temp = (TreeNode *) malloc (sizeof (TreeNode));
    temp->lChild = nullptr;
    temp->rChild = nullptr;
    temp->value = k;

    return temp;
}

void CreateTree (TreeNode **root) {
    int t;

    cin >> t;
    if (t != 0) {
        *root = CreateTreeNode (t);
        CreateTree (&((*root)->lChild));
        CreateTree (&((*root)->rChild));
    }
}

void PreTravelTree (TreeNode *node) {
    if (node != nullptr) {
        cout << node->value << " ";
        PreTravelTree (node->lChild);
        PreTravelTree (node->rChild);
    }
}

void PreTravelTreeNonRecur (TreeNode *node) {
    stack<TreeNode *> nodeStack;
    TreeNode *cur = node;

    while (cur != nullptr || !nodeStack.empty ()) {
        while (cur != nullptr) {
            cout << cur->value << " ";
            nodeStack.push (cur);
            cur = cur->lChild;
        }
        if (!nodeStack.empty ()) {
            cur = nodeStack.top ();
            nodeStack.pop ();
            cur = cur->rChild;
        }
    }
}

void MidTravelTree (TreeNode *node) {
    if (node != nullptr) {
        MidTravelTree (node->lChild);
        cout << node->value << " ";
        MidTravelTree (node->rChild);
    }
}

void MidTravelTreeNonRecur (TreeNode *node) {
    stack<TreeNode *> nodeStack;
    TreeNode *cur = node;

    while (cur != nullptr || !nodeStack.empty ()) {
        while (cur != nullptr) {
            nodeStack.push (cur);
            cur = cur->lChild;
        }
        if (!nodeStack.empty ()) {
            cur = nodeStack.top ();
            cout << cur->value << " ";
            nodeStack.pop ();
            cur = cur->rChild;
        }
    }
}

void PosTravelTree (TreeNode *node) {
    if (node != nullptr) {
        PosTravelTree (node->lChild);
        PosTravelTree (node->rChild);
        cout << node->value << " ";
    }
}

void PosTravelTreeNonRecur (TreeNode *node) {
    stack<pair<TreeNode * , bool>> nodeStack;
    TreeNode *cur = node;

    nodeStack.push (make_pair (cur , false));
    bool visited;
    while (!nodeStack.empty ()) {
        cur = nodeStack.top().first;
        visited = nodeStack.top().second;
        nodeStack.pop ();

        if (cur == nullptr)
            continue;
        if (visited)
            cout << cur->value << " ";
        else {
            nodeStack.push (make_pair(cur , true));
            nodeStack.push (make_pair(cur->rChild , false));
            nodeStack.push (make_pair(cur->lChild , false));
        }
    }
}

void PosTravelTreeNonRecurSec (TreeNodePlus *node) {
    stack<TreeNodePlus *> nodeStack;
    TreeNodePlus *cur = node;

    while (cur != nullptr || !nodeStack.empty ()) {
        while (cur != nullptr) {
            cur->visited++;
            nodeStack.push (cur);
            if (cur->lChild == nullptr) {
                break;
            }else if (cur->lChild->visited > 0) {
                break;
            }else {
                cur = cur->lChild;
            }
        }
        if (!nodeStack.empty ()) {
            cur = nodeStack.top ();
            cur->visited++;
            if (cur->visited == 3) {
                cout << cur->value << " ";
                nodeStack.pop ();
                cur = nullptr;
            }else {
                cur = cur->rChild;
            }
        }
    }
}

int main () {
    TreePlus T;
    CreateTreePlus (&T.root);
    
    PosTravelTreeNonRecurSec (T.root);
    cout << endl;
}
