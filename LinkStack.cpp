#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LStack{
    int num;
    LStack *next;
}LStack;

LStack *InitStack(LStack *head){
    head = (LStack *)malloc(sizeof(LStack));
    head->next = NULL;
    return head;
}

int IsNull(LStack *lstack){
    if(lstack->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

void PushElem(LStack *lstack , int num){
    LStack *temp = (LStack*)malloc(sizeof(LStack));
    temp->num = num;
    temp->next = lstack->next;
    lstack->next = temp;
}

void PopElem(LStack *lstack){
    if(IsNull != 0){
        LStack *temp;
        temp = lstack->next;//����ɾ����,����free
        lstack->next = temp->next;
        free(temp);
    }else{
        cout << "ջ��" <<endl;
    }
}

void PrintStack(LStack *lstack){
    while(lstack->next != NULL){
        lstack = lstack->next;
        cout << lstack->num <<endl;
    }
}

int main(){
    LStack *head;
    LStack *lstack;
    lstack = InitStack(head);

    cout <<"�������ĸ���" <<endl;
    int n , num;
    cin >>n;
    for(int i = 0 ; i< n ;i ++){
        cin >>num;
        PushElem(lstack , num);
    }

    cout <<"ɾ���ĸ���" <<endl;
    cin >>n;
    for(int i = 0 ; i < n ; i ++){
        PopElem(lstack);
    }

    PrintStack(lstack);

    return 0;
}
