#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct SQueue{
    int *num;
    int front , rear;
    int length;
}SQueue;

SQueue *InitQueue(SQueue *squeue , int length){
    squeue = (SQueue *)malloc(sizeof(SQueue));
    squeue->front = 0;
    squeue->rear = 0;
    squeue->length = length;

    return squeue;
}

bool IsNull(SQueue * squeue){
    if(squeue->rear == squeue->front){
        return true;
    }
    return false;
}

bool IsFull(SQueue *squeue){
    //cout << squeue->rear + 1 <<endl;
    if((squeue->rear + 1)% squeue->length == squeue->front){
        return true;
    }else{
        return false;
    }
}

void AddElem(SQueue *squeue , int num){
    if(!IsFull(squeue)){
        if(!IsNull(squeue)){
            squeue->num[(squeue->rear ++) % squeue->length] = num;
        }
    }else{
        cout << "队列满" <<endl;
    }
}

void PrintQueue(SQueue *squeue){
    for(int i = squeue->front ;i < abs(squeue->rear - squeue->front) + 1 ; i++){
        cout << squeue->num[i%squeue->length] <<endl;
    }
}

int main(){
    SQueue *head;
    SQueue *squeue;

    cout << "输入队列长" <<endl;
    int length;
    cin >>length;
    squeue = InitQueue(squeue , length);

    cout <<"输入插入个数" <<endl;
    cin >> length;
    int num;
    for(int i = 0 ;i < length ;i ++){
        //cin >>num;
        scanf("%d" , &num);
        AddElem(squeue , num);
    }

    PrintQueue(squeue);

    return 0;
}
