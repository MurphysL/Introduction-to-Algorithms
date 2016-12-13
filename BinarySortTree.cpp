#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BinTree{
    int num;
    BinTree *left;
    BinTree *right;
}BinTree;

/**
 *��������������
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
 *����������ɾ��
 */
BinTree *DeleteBST(BinTree *bintree , int n){

    if(bintree == NULL){
        cout << "δ�ҵ���Ԫ��" <<endl;
    }else{
        if(n < bintree->num){
            bintree->left = DeleteBST(bintree->left , n);
        }else if(n > bintree->num){
            bintree->right = DeleteBST(bintree->right , n);
        }else{
            if(bintree->left != NULL && bintree->right != NULL){
                //��ȡ����������Сֵ
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

void PreOrderTraversal(BinTree *bintree){
    if(bintree == NULL){
        return;
    }else{
        PreOrderTraversal(bintree->left);
        cout << bintree->num <<endl;
        PreOrderTraversal(bintree->right);
    }
}

int main(){
    BinTree *bintree = NULL;
    CreateBST(&bintree);

    cout << "ǰ�����:" <<endl;
    PreOrderTraversal(bintree);

    int n;
    cout << "�������һ����:" <<endl;
    cin >>n;
    InsertBST(&bintree , n);

    cout << "�������:" <<endl;
    InOrderTraversal(bintree);

    cin >>n;
    cout <<"����Ҫɾ������:" <<endl;
    BinTree *newTree = DeleteBST(bintree , n);

    cout <<"�������:" <<endl;
    PreOrderTraversal(newTree);

    return 0;
}
