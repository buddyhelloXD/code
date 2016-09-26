/*************************************************************************
> File Name: avl_tree.cpp
> Author: jeff zhu
> Mail: 908190355@qq.com 
> Created Time: 2016年09月26日 星期一 19时20分35秒
************************************************************************/
me: rb_tree.c 
> Author: jeff zhu 
> Mail: 908190355@qq.com  
> Created Time: 2016年08月30日 星期二 22时08分53秒 
************************************************************************/  

#include <stdio.h>  
#include <limits.h>  
#include <malloc.h>  

#define RED 1  
#define BLACK 2  
#define NIL INT_MIN  

typedef int EleType;  
typedef struct rb_tree_node {  
struct rb_tree_node *parent;  
struct rb_tree_node *left;  
struct rb_tree_node *right;  
EleType key;  
int color;  
}NODE;  

typedef struct rb_tree {  
NODE *root;  
NODE *nil;  
}RBTREE;  

void init_rb_tree_root (RBTREE *T) ;  
NODE *create_rb_tree_node (RBTREE T , EleType key) ;  
void rb_tree_insert (RBTREE *T , NODE *x) ;  
void rotate_right (RBTREE *T , NODE *y) ;  
void rotate_left (RBTREE *T , NODE *x) ;  
void rb_tree_insert_fixup (RBTREE *T , NODE *x) ;  
void travel_tree (RBTREE *T , NODE *node) ;  
NODE* minimum_rb_tree (RBTREE *T , NODE *x) ;  
void rb_tree_delete_fixup (RBTREE *T , NODE *x) ;  
void rb_tree_delete (RBTREE *T , NODE *z) ;  

int main () {  
    RBTREE T;  
    init_rb_tree_root (&T);  
    NODE *temp;  

    int flag;  
    while (scanf ("%d" , &flag) , flag != -1) {  
        NODE *temp = create_rb_tree_node (T , flag);  
        rb_tree_insert (&T , temp);  
    }  
    rb_tree_delete (&T , T.root);  
    travel_tree (&T , T.root);  
}  

void init_rb_tree_root (RBTREE *T) {  
    T->root = NULL;  
    T->nil = (NODE *) malloc (sizeof (NODE));  
    T->nil->parent = NULL;  
    T->nil->left = NULL;  
    T->nil->right = NULL;  
    T->nil->key = NIL;  
    T->nil->color = BLACK;  
}  

NODE *create_rb_tree_node (RBTREE T , EleType key) {   
// create a red-black-tree and its default color is RED  
    NODE *temp = (NODE *) malloc (sizeof (NODE));  
    temp->key = key;  
    temp->color = RED;  
    temp->parent = NULL;  
    temp->left = T.nil;  
    temp->right = T.nil;  

    return temp;  
}  

void rb_tree_insert (RBTREE *T , NODE *x) {  
    NODE *temp = T->root;  
    NODE *log = T->nil;  

    if (temp == NULL) {  
        T->root = x;  
        x->left = T->nil;  
        x->right = T->nil;  
        x->parent = T->nil;  
    }else {  
        while (temp != T->nil) {  
            log = temp;  
            if (x->key > temp->key)  
                temp = temp->right;  
            else  
            temp = temp->left;  
        }  
        if (log->key < x->key)  
            log->right = x;  
        else  
            log->left = x;  
        x->parent = log;  
    }  
    rb_tree_insert_fixup (T , x);  
}  

void rb_tree_insert_fixup (RBTREE *T , NODE *x) {  
// this function is to fixup the rb-tree after calling rb_tree_insert  
    while (x->parent->color == RED) {  
        if (x->parent == x->parent->parent->left) {  
            NODE *y = x->parent->parent->right;  
            if (y->color == RED) {  
                y->color = BLACK;  
                x->parent->color = BLACK;  
                x->parent->parent->color = RED;  
                x = x->parent->parent;  
            }else if (y->color == BLACK) {  
                if (x == x->parent->right) {  
                    x = x->parent;  
                    rotate_left (T , x);  
                }  
                x->parent->color = BLACK;  
                x->parent->parent->color = RED;  
                rotate_right (T , x->parent->parent);  
            }  
        }else {  
            NODE *y = x->parent->parent->left;  
            if (y->color == RED) {  
                y->color = BLACK;  
                x->parent->color = BLACK;  
                x->parent->parent->color = RED;  
                x = x->parent->parent;  
            }else if (y->color == BLACK) {  
                if (x == x->parent->left) {  
                    x = x->parent;  
                    rotate_right (T , x);  
                }  
                x->parent->color = BLACK;  
                x->parent->parent->color = RED;  
                rotate_left (T , x->parent->parent);  
            }  
        }  
    }  
    T->root->color = BLACK;  
}     

void rotate_left (RBTREE *T , NODE *x) {  
    NODE *y = x->right;  

    x->right = y->left;  
    if (y->left != T->nil)  
        y->left->parent = x;  
        y->parent = x->parent;  
    if (x->parent == T->nil)  
        T->root = y;  
    else if (x == x->parent->left)  
        x->parent->left = y;  
    else  
        x->parent->right = y;  
    x->parent = y;  
    y->left = x;  
}  

void rotate_right (RBTREE *T , NODE *y) {  
    NODE *x = y->left;  

    y->left = x->right;  
    if (x->right != T->nil)  
        x->right->parent = y;  
    x->parent = y->parent;  
    if (y->parent == T->nil)  
        T->root = x;  
    else if (y == y->parent->left)  
        y->parent->left = x;  
    else  
        y->parent->right = x;  
    y->parent = x;  
    x->right = y;  
}  

void travel_tree (RBTREE *T , NODE *node) {  
    if (node != T->nil) {  
        travel_tree (T , node->left);  
        printf ("this node's color is %d\n" , node->color);  
        printf ("this node's key is %d\n" , node->key);  
        printf ("\n");  
        travel_tree (T , node->right);  
    }  
}  

void transplant (RBTREE *T , NODE *x , NODE *y) {  
    if (x->parent == T->nil)  
        T->root = y;  
    else if (x == x->parent->left)  
        x->parent->left = y;  
    else  
        x->parent->right = y;  

    if (y != T->nil)  
        y->parent = x->parent;  
    }  

    NODE* minimum_rb_tree (RBTREE *T , NODE *x) {  
    NODE *y = T->nil;  
    NODE *temp = x;  

    while (temp != T->nil) {  
        y = temp;  
        temp = temp->left;  
    }  
    return y;  
}  

void rb_tree_delete (RBTREE *T , NODE *z) {  
    NODE *y = z;  
    NODE *x;  
    int y_original_color = y->color;  

    if (z->left == T->nil) {  
        x = z->right;  
        transplant (T , z , z->right);  
        free (z);  
    }else if (z->right == T->nil) {  
        x = z->right;  
        transplant (T , z , z->left);  
        free (z);  
    }else  {  
        y = minimum_rb_tree (T , z->right);  
        y_original_color = y->color;  
        x = y->right;  
        if (y->parent == z) {  
            x->parent = y;  
            transplant (T , z , y);  
            y->left = z->left;  
            z->left->parent = y;  
            y->color = z->color;  
            free (z);  
        }else {  
            transplant (T , y , y->right);  
            y->right = z->right;  
            y->right->parent = y;  
            transplant (T , z , y);  
            y->left = z->left;  
            y->left->parent = y;  
            y->color = z->color;  
            free (z);  
        }  
    }  
    if (y_original_color == BLACK)  
    rb_tree_delete_fixup (T , x);  
}  

void rb_tree_delete_fixup (RBTREE *T , NODE *x) {  
    NODE *w;  

    while (x != T->root && x->color == BLACK) {  
        if (x == x->parent->left) {  
            w = x->parent->right;  
        if (w->color == RED) {  
            w->color = BLACK;  
            x->parent->color = RED;  
            rotate_left (T , x->parent);  
            w = x->parent->right;  
        }  
        if (w->left->color == BLACK && w->right->color == BLACK) {  
            w->color == BLACK;  
            x = x->parent;  
        }else {  
            if (w->left->color == RED && w->right->color == BLACK) {  
                w->left->color == BLACK;  
                w->color == RED;  
                rotate_right (T , w);  
                w = x->parent->right;  
            }  
                w->color = w->parent->color;  
                w->parent->color = BLACK;  
                w->right->color = BLACK;  
                rotate_left (T , x->parent);  
                x = T->root;  
            }   
        }  
        else {  
            w = x->parent->left;  
            if (w->color == RED) {  
            w->color = BLACK;  
            x->parent->color = RED;  
            rotate_right (T , x->parent);  
            w = x->parent->left;  
            }  
            if (w->left->color == BLACK && w->right->color == BLACK) {  
                w->color = RED;  
                x = x->parent;  
            }else {  
                if (w->left->color == BLACK && w->right->color == RED) {  
                    w->color = RED;  
                    w->right->color = BLACK;  
                    rotate_right (T , w);  
                    w = x->parent->left;  
                }  
                w->color = w->parent->color;  
                w->parent->color = BLACK;  
                w->left->color = BLACK;  
                rotate_right (T , x->parent);  
                x = T->root;  
            }  
        }  
    }  
    if (x != T->nil)  
    x->color = BLACK;  
}  
