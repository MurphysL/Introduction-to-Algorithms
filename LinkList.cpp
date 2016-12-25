#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LList{
    int num;
    LList *next;
}LList;

LList * initList(LList *head){
    LList *p1 , *p2;
    p1 = p2 = (LList *)malloc(sizeof(LList));
    cout << "输入初始值,以0结尾" <<endl;
    cin >> p1->num;
    p1->next = NULL;
    while(p1->num != 0){
        if(head == NULL){
            head = p1;
        }else{
            p2->next = p1;
        }
        p2 = p1;

        p1 = (LList *)malloc (sizeof(LList));
        cin >> p1->num;
    }

    free(p1);
    p2->next = NULL;

    return head;
}

void printList(LList *llist){
    LList *temp = llist;
    cout << " " <<endl;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }

    cout << "打印完成" <<endl;
}

int GetElem(LList *llist , int pos){
    int i = 1;
    LList *temp = llist;
    if(pos <= 0){
        return -1;
    }
    while(temp != NULL){
        if(i == pos){
            return temp->num;
        }
        temp = temp->next;
        i ++;
    }
    return -1;
}

int DeleteList(LList *llist , int pos){
    LList *temp = llist;
    int i = 1;
    if(pos <= 0){
        return -1;
    }
    while(temp != NULL){
        if(i == pos -1){
            temp ->next = temp->next->next;
            return 0;
        }
        temp = temp->next;
        i ++;
    }
    return -1;
}

/**
 * 删除链表中所有值为num的数据
 */
void DeleteList2(LList *llist , int num){
    while(llist){
        if(llist->num == num){
            LList *t = llist->next;
            llist->num = llist->next->num;
            llist->next = llist->next->next;
        }
        llist = llist->next;
    }
}

/**
 * 逆转矩阵(**)
 */
void Contrary(LList **llist){
    LList *current = *llist;
    LList *left = NULL;
    LList *right = NULL;
    while(current){
        right = current->next;
        current->next = left;
        left = current;
        current = right;
    }
    *llist = left;
}

/**
 * 插入数据
 */
int InsertList(LList *llist , int pos , int n){
    LList *temp = llist;
    int i = 1;
    if(pos <= 0){
        return -1;
    }
    while(temp != NULL){
        if(i == pos - 1){
            LList *t = (LList *)malloc(sizeof(LList));
            t->num = n;
            t->next = temp->next;
            temp->next = t;
            return 0;
        }
        temp = temp ->next;
        i ++;
    }
    return -1;
}

int main(){
    int pos , i;
    LList *head = NULL;
    LList *llist = NULL;

    llist = initList(head);

//    cout << "查找的位置" << endl;
//    cin >> pos;
//    if(-1 == (i = GetElem(llist , pos))){
//       cout << "错误位置";
//    }else{
//        cout << i << endl;
//    }

//    cout << "插入的位置与值" <<endl;
//    cin >> pos;
//    cin >> i;
//
//    if(-1 == InsertList(llist , pos , i)){
//        cout << "位置错误" <<endl;
//    }else{
//        printList(llist);
//    }

//    cout << "输入删除的位置" <<endl;
//    cin >>i;
//    if(-1 == DeleteList(llist , i)){
//        cout << "错误位置" <<endl;
//    }else{
//        cout << "删除成功" << endl;
//        printList(llist);
//    }

      //cout << "输入要删除的值:" <<endl;
      //cin >> i;
      //DeleteList2(llist , i);
      //printList(llist);

    Contrary(&llist);
    printList(llist);

    return 0;
}
