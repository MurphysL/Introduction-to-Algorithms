#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BinTree{
    int num;
    BinTree *left;
    BinTree *right;
}BinTree;

typedef struct Stack{
    int num;
    int top;
}Stack;

void InitTree(BinTree **head){
    int n;
    cin >> n;
    if(n != 0){
        *head = new BinTree;
        (*head)->num = n;
        InitTree(&(*head)->left);
        InitTree(&(*head)->right);
    }else{
        *head = NULL;
    }

}

int Depth(BinTree *bintree){
    if(bintree == NULL){
        return 0;
    }else{
        int m = Depth(bintree->left);
        int n = Depth(bintree->right);
        if(m >= n){
            return m+1;
        }else{
            return n+1;
        }
    }
}

int NodeNum(BinTree *bintree){
    if(bintree == NULL){
        return 0;
    }else{
        return NodeNum(bintree->left) + NodeNum(bintree->right) + 1;
    }
}

void PreOrderTraversal(BinTree *bintree){
    if(bintree != NULL){
        cout << bintree->num << endl;
        PreOrderTraversal(bintree->left);
        PreOrderTraversal(bintree->right);
    }
}

void InOrderTraversal(BinTree *bintree){
    if(NULL == bintree)
        return;
    InOrderTraversal(bintree->left);
    cout << bintree->num << endl;
    InOrderTraversal(bintree->right);
}


void PostOrderTraversal(BinTree *bintree){
    if(bintree != NULL){
        PostOrderTraversal(bintree->left);
        PostOrderTraversal(bintree->right);
        cout << bintree->num << endl;
    }
}


int main(){
    BinTree *bintree;
    InitTree(&bintree);

    cout<<"先序遍历"<<endl;
    PreOrderTraversal(bintree);
    cout<<"中序遍历"<<endl;
    InOrderTraversal(bintree);
    cout<<"后序遍历"<<endl;
    PostOrderTraversal(bintree);

    cout <<"树的深度:" << Depth(bintree) <<endl;
    cout <<"结点个数:" <<NodeNum(bintree) <<endl;

    return 0;
}
