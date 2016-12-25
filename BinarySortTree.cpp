#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BinTree{
    int num;
    BinTree *left;
    BinTree *right;
}BinTree;

/**
 *二叉排序树插入
 */
void InsertBST(BinTree **bintree , int num){
    if(*bintree == NULL){
        *bintree = new BinTree;
        (*bintree)->num = num;
        (*bintree)->left = NULL;
        (*bintree)->right = NULL;
    }else{
        if(num < (*bintree)->num){
            InsertBST(&(*bintree)->left , num);
        }else if(num > (*bintree)->num){
            InsertBST(&(*bintree)->right , num);
        }
    }
}

BinTree *FindMin(BinTree *bintree){
    while(bintree->left != NULL){
        bintree = bintree->left;
    }
    return bintree;
}

/**
 *二叉排序树删除
 */
BinTree *DeleteBST(BinTree *bintree , int n){

    if(bintree == NULL){
        cout << "未找到该元素" <<endl;
    }else{
        if(n < bintree->num){
            bintree->left = DeleteBST(bintree->left , n);
        }else if(n > bintree->num){
            bintree->right = DeleteBST(bintree->right , n);
        }else{
            if(bintree->left != NULL && bintree->right != NULL){
                //获取右子树的最小值
                BinTree *minNode = FindMin(bintree->left);
                bintree->num = minNode->num;
                DeleteBST(bintree->left , minNode->num);
            }else{
                BinTree *tmp;
                tmp = bintree;
                if(bintree->left == NULL){
                    bintree = bintree->right;
                }else{
                    bintree = bintree->left;
                }
                free(tmp);
            }
        }
    }

    return bintree;
}

void CreateBST(BinTree **bintree){
    int n ;
    cin >>n;
    while(n != 0){
        InsertBST(bintree , n);
        cin >>n;
    }
}

void  InOrderTraversal(BinTree *bintree){
    if(bintree == NULL){
        return;
    }else{
        InOrderTraversal(bintree->left);
        cout << bintree->num <<endl;
        InOrderTraversal(bintree->right);
    }
}

int main(){
    BinTree *bintree = NULL;
    CreateBST(&bintree);

    cout << "前序遍历:" <<endl;
    InOrderTraversal(bintree);

    int n;
    cout << "随机插入一个数:" <<endl;
    cin >>n;
    InsertBST(&bintree , n);

    cout << "中序遍历:" <<endl;
    //InOrderTraversal(bintree);

    cin >>n;
    cout <<"输入要删除的数:" <<endl;
    BinTree *newTree = DeleteBST(bintree , n);

    cout <<"中序遍历:" <<endl;
    InOrderTraversal(newTree);

    return 0;
}
