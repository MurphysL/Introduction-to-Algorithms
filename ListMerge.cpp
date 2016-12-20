#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * 增序链表合并
 */

typedef struct List{
    int num;
    List *next;
}List;

void print(List *list){
    List *t = list;
    while(t != NULL){
        cout <<t->num << " ";
        t = t->next;
    }
    cout <<""<<endl;
}

void print2(List *PC){
    while(PC->next){
        cout <<PC->next->num<< " ";
        PC = PC->next;
    }
    cout << "" <<endl;
}

/**
 * 递归合并
 */
List *MergeList(List *list , List *list2){
    if(list == NULL)
        return list2;
    else if(list2 == NULL)
        return list;

    List *temp = NULL;
    if(list->num < list2->num){
        temp = list;
        temp->next = MergeList(list->next , list2);
    }else{
        temp = list2;
        temp->next = MergeList(list , list2->next);
    }

    return temp;
}

/**
 * 普通合并
 */
List *MergeList2(List *PA , List *PB , List *PC){
    List *pa = PA->next;
    List *pb = PB->next;
    PC = PA;
    List *pc = PC;
    while(pa&&pb){
        if(pa->num >= pb->num){
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }else{
            pc->next = pa;
            pc= pc->next;
            pa = pa->next;
        }
    }

    pc->next = pa?pa:pb;
    return PC;
}

/**
 * 初始化链表
 */
void InitList(List **l1 , List **l2){
    (*l1) = new List;
    (*l1)->next = NULL;
    (*l1)->num = 0;
    (*l2) = new List;
    (*l2)->next = NULL;
    (*l2)->num = 1;
    for(int i = 10 ;i >= 2 ;i -= 2){
        List *t = new List;
        t->next = (*l1)->next;
        (*l1)->next = t;
        t->num = i;
    }

    for(int i = 11 ;i >= 3 ;i -= 2){
        List *t = new List;
        t->next = (*l2)->next;
        (*l2)->next = t;
        t->num = i;
    }
}

/**
 * 初始化带头结点链表
 */
void InitListWithHead(List **LA , List **LB){
    *LA = new List;
    *LB = new List;
    (*LA)->next = NULL;
    (*LB)->next = NULL;
    for(int i = 10;i >= 0 ;i -=2){
        List *t = new List;
        t->num = i;
        t->next = (*LA)->next;
        (*LA)->next = t;
    }
    for(int i = 11 ;i >= 1 ;i -=2){
        List *t = new List;
        t->num = i;
        t->next = (*LB)->next;
        (*LB)->next = t;
    }
}

int main(){
    cout << "递归合并" <<endl;
    List *l1,*l2,*l3;
    InitList(&l1 , &l2);
    print(l1);
    print(l2);
    print(MergeList(l1 ,l2));

    cout << "普通合并" <<endl;
    List *LA , *LB, *LC;
    InitListWithHead(&LA , &LB);
    print2(LA);
    print2(LB);
    print2(MergeList2(LA,LB,LC));

    return 0;
}
