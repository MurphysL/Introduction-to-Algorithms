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
    cout << "�����ʼֵ,��0��β" <<endl;
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

    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }

    cout << "��ӡ���" <<endl;
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

    cout << "���ҵ�λ��" << endl;
    cin >> pos;
    if(-1 == (i = GetElem(llist , pos))){
       cout << "����λ��";
    }else{
        cout << i << endl;
    }

    cout << "�����λ����ֵ" <<endl;
    cin >> pos;
    cin >> i;

    if(-1 == InsertList(llist , pos , i)){
        cout << "λ�ô���" <<endl;
    }else{
        printList(llist);
    }

    cout << "����ɾ����λ��" <<endl;
    cin >>i;
    if(-1 == DeleteList(llist , i)){
        cout << "����λ��" <<endl;
    }else{
        cout << "ɾ���ɹ�" << endl;
        printList(llist);
    }


    return 0;
}
