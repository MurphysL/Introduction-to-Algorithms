#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct AVLNode{
    int num;
    AVLNode *left;
    AVLNode *right;
    int height;
}AVLNode;

int MaxHight(AVLNode *node){
    if(node == NULL){
        return 0;
    }else{
        int leftH = MaxHight(node->left);
        int rightH = MaxHight(node->right);
        return leftH > rightH ? leftH : rightH;
    }
}

int AVLNodeBF(AVLNode *node){
    if(node->left == NULL && node->right == NULL){
        return 0;
    }else if(node->left == NULL){
        return node->right->height;
    }else{
        return node->left->height;
    }
}

/**
 * LL
 */
AVLNode *SigleLeftRotation(AVLNode *A){
    AVLNode *B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = MaxHight(A);
    B->height = MaxHight(B);

    return B;
}

/**
 * RR
 */
AVLNode *SigleRightRotation(AVLNode *A){
    AVLNode *B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = MaxHight(A);
    B->height = MaxHight(B);
    return B;
}

/**
 *LR
 */
AVLNode *DoubleLeftRightRotation(AVLNode *A){
    A->left = SigleRightRotation(A->left);
    return SigleLeftRotation(A);
}

/**
 *RL
 */
AVLNode *DoubleRightLeftRotation(AVLNode *A){
    A->right = SigleLeftRotation(A->right);
    return SigleRightRotation(A);
}

AVLNode *InsertNode(AVLNode *node , int n){
    if(node == NULL){
        node = new AVLNode;
        node->num = n;
        node->left = NULL;
        node->right = NULL;
        node->height = MaxHight(node);
        return node;
    }else if(node->num < n){
        node->right = InsertNode(node->right , n);
    }else if(node->num > n){
        node->left = InsertNode(node->left , n);
    }else{
        return NULL;
    }

    int BF = AVLNodeBF(node);
    if(BF == -2){
        if(node->right->height == 1){
            node = DoubleRightLeftRotation(node);
        }else{
            node = SigleRightRotation(node);
        }
    }else if(BF == 2){
        if(node->left->height == 1){
            node = SigleLeftRotation(node);
        }else{
            node = DoubleLeftRightRotation(node);
        }
    }else{
        node->height = MaxHight(node);
    }
    return node;
}

void CreateBST(AVLNode **node){
    int n ;
    cin >>n;
    while(n != 0){
        *node = InsertNode(*node , n);
        cin >> n;
    }
}

void PreOrderTraversal(AVLNode *node){
    if(node != NULL){
        PreOrderTraversal(node->left);
        cout << node->num <<endl;
        PreOrderTraversal(node->right);
    }
}

int main(){
    AVLNode *node = NULL;
    CreateBST(&node);

    cout <<"ÖÐÐò±éÀú:" <<endl;
    PreOrderTraversal(node);

    return 0;
}
