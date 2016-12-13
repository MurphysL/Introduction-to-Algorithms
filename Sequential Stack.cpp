#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct SStack{
    int *num;
    int top;
    int length;
}SStack;

SStack* InitStack(SStack *head , int length){
    head = (SStack *)malloc(sizeof(SStack));
    head->top = -1;
    head->length = length;
    return head;
}

void PushElem(SStack *sstack , int num){
    cout << sstack->length << " " << sstack->top <<endl;
    if(sstack->top == sstack->length - 1){
        cout << "栈满" <<endl;
    }else{
        cout << "aaaa" <<endl;
        sstack->num[++(sstack->top)] = num;
        cout << "bbbb" <<endl;
    }
}

void printStack(SStack *sstack){
    cout << "what" <<endl;
    for(int i = 0 ;i <= sstack->top ; i++){
        cout << sstack->num[i] << endl;
    }
}

int main(){
    SStack *head;
    SStack *sstack;

    cout << "输入栈长度" << endl;
    int length;
    cin >> length;
    sstack = InitStack(head , length);

    cout <<"插入值个数" <<endl;
    cin >> length;
    cout << "插入值:" << endl;
    int num = 0;
    for(int i =0 ;i < length ; i ++){

        scanf("%d" , &num);
        //cin >> num;
        cout << "dafa" << num <<endl;
        PushElem(sstack , num);
        cout <<"bbvvv" <<endl;
    }
    cout << "ppp" <<endl;
    printStack(sstack);
    return 0;
}
