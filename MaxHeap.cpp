#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
using namespace std;

typedef struct Heap{
    int *num;
    int Size;
    int Capacity;
}Heap;

bool isFull(Heap *heap){
    return heap->Size == heap->Capacity;
}

bool isEmpty(Heap *heap){
    return heap->Size == 0;
}

void CreateHeap(Heap *heap){
    int n;
    cin >> n;
    while(n != 0 && heap->Capacity != heap->Size){
        heap->num[ ++ heap->Size] = n;
        cin >> n;
    }
}

void InitHeap(Heap **heap){
    *heap = new Heap;
    cout << "����ѵ��������:" <<endl;
    cin >> (*heap)->Capacity;
    (*heap)->num = (int *)malloc(((*heap)->Capacity + 1) * sizeof(int));//�����ʼ��
    (*heap)->num[0] = MAX;
    (*heap)->Size = 0;
}

void PrintHeap(Heap *heap){
    for(int i = 1 ;i <= heap->Size ; i++){
        cout << heap->num[i] << " ";
    }
    cout <<""<<endl;
}

int DeleteMax(Heap *heap){
    int MaxItem = heap->num[0];
    heap->num[1] = heap->num[heap->Size];
    heap->Size --;
    int X = heap->num[1];

    int Child , Parent;
    for(Parent = 1;Parent * 2 <= heap->Size ;Parent = Child){
        Child = Parent *2;
        if(Child != heap->Size && heap->num[Child] < heap->num[Child + 1]){
            Child ++;
        }
        if(heap->num[Child] > X){
            heap->num[Parent] = heap->num[Child];
        }else{
            break;
        }
    }
    cout << "ջ��" <<Child <<endl;
    heap->num[Parent] = X;

    return MaxItem;
}

/**
 *������
 */
void PercDown(Heap *heap ,int p){
    int X  = heap->num[p];
    int Child , Parent;
    for(int Parent = p ;Parent *2 <= heap->Size ;Parent = Child){
        Child = Parent * 2;//������
        if(Child != heap->Size && heap->num[Child] < heap->num[Child + 1]){
            Child ++;
        }
        if(X < heap->num[Child]){
            heap->num[Parent] = heap->num[Child];
        }else{
            break;
        }
    }
    heap->num[Child] = X;
}

int main(){
    Heap *heap = NULL;
    InitHeap(&heap);
    CreateHeap(heap);

    cout <<"ԭʼ��:" <<endl;
    PrintHeap(heap);

    for(int i = heap->Size /2 ; i > 0 ;i --)
        PercDown(heap , i);

    cout << "����:" <<endl;
    PrintHeap(heap);

    cout <<"ɾ����:"<<endl;
    DeleteMax(heap);
    PrintHeap(heap);

    return 0;
}
