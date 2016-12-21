#include <iostream>
#include <stdlib.h>
#define Cutoff 100
#define MAX 1000
using namespace std;

typedef struct Heap{
    int *num;
    int Size;
    int Capacity;
}Heap;

void Swap(int *a , int left , int right);
void printArray(int *a , int len);
void PrintHeap(Heap *heap);

/**
 * 简单排序
 *
 * if A[i]>A[j] (i,j)是一对inversion(逆序对)
 * 交换相邻元素消去一个逆序对
 *
 * 任意N个不同元素组成的序列平均具有 N(N-1)/4 个逆序对
 * 任意仅以交换相邻元素的排序算法,平均时间复杂度为Ω(N^2)
 *
 * 提高效率:
 * 1.消去不止一个逆序对
 * 2.交换相隔较远的2元素
 */

/**
 * 冒泡排序
 *
 * best T=O(N)
 * worst T=O(N^2)
 * 适用于链表
 */
void Bubble_Sort(int *a , int len){
    for(int i = 0 ;i <len ;i ++){
        bool flag = true;
        for(int j = 0 ; j <len - i - 1;j ++){
            if(a[j] > a[j +1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/**
 * 选择排序
 */
void Selection_Sort(int *a , int len){
    int i , j;
    for(i = 0;i < len -1;i ++){
        int min = i;
        for(j = i+1; j <len ;j ++){
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            Swap(a , i , min);
    }
}

/**
 * 插入排序
 *
 * best T=O(N)
 * worst T=O(N^2)
 * S=O(1)
 * 适用于基本有序
 * 适用于链表
 * 适用于N较小
 */
void Insertion_Sort(int *a , int len){
    int  j;
    for(int i = 1; i < len ;i ++){
        int temp = a[i];
        for(j = i ; j > 0 && a[j-1] > temp ;j --){
            a[j] = a[j -1];
        }
        a[j] = temp;
    }
}

/**
 * 折半插入排序(哨兵)
 *
 * T=O(N^2)
 * S=O(1)
 * 不适用于链表
 * 适用于N较大
 */
void printArray2(int *a , int len){
    for(int i = 1 ;i <= len ;i ++){
        cout << a[i] <<" ";
    }
    cout <<""<<endl;
}
void Bin_Insertion_Sort(int *a , int len){
    for(int i = 2 ;i <=len;i ++){
        a[0] = a[i];
        int low = 1 , high = i-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(a[mid] > a[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(int j = i-1 ;j >=high ;j --)
            a[j+1] = a[j];
        a[high+1] = a[0];
    }
}

/**
 * 希尔排序(特殊插入排序)
 *
 * 不适用于链表
 * 适用于N较大,无序
 */
void Sell_Sort(int *a , int len){
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};//增量序列
    int  k , n , i;
    for(k = 0 ;Sedgewick[k] > len ; k ++){}

    for(int D = Sedgewick[k] ; D > 0 ; D = Sedgewick[++k]){
        for(int j = D;j < len ;j ++){
            int temp = a[j];
            for(i = j ; i > 0 && a[i-1] > temp;i --){
                a[i] = a[i-1];
            }
            a[i] = temp;
        }
    }
}

/**
 * 堆排序
 *
 * T=O(NLOG2N)
 * S=O(1)
 * 不适用于链表
 * 适用于数据较多时
 */
bool isEmpty(Heap *heap){
    return heap->Size == 0;
}
bool isFull(Heap *heap){
    return heap->Size == heap->Capacity;
}
void InitHeap(Heap **heap ,int len , int *a){
    *heap = new Heap;
    (*heap)->num = (int *)malloc(11*sizeof(int));
    (*heap)->Capacity = 100;
    (*heap)->Size = len;
    (*heap)->num[0] = MAX;
    for(int i = 1 ;i <= len ;i ++)
        (*heap)->num[i] = a[i-1];
}
void PercDown(Heap *heap , int node){
    int X = heap->num[node];
    int Parent , Child;
    for(Parent = node ;Parent*2 <= heap->Size ;Parent = Child){
        Child = Parent * 2;
        if(Child + 1 <= heap->Size && heap->num[Child] > heap->num[Child +1])
            Child ++;
        if(X > heap->num[Child])
            heap->num[Parent] = heap->num[Child];
        else
            break;
    }
    heap->num[Parent] = X;
}
int DeleteNode(Heap *heap){
    int node = heap->num[1];
    heap->num[1] = heap->num[heap->Size];
    heap->num[heap->Size] = node;
    heap->Size --;
    PercDown(heap , 1);
    return node;
}
void PrintHeap(Heap *heap){
    for(int i = 1 ;i <=heap->Size;i ++)
        cout << heap->num[i]<< " ";
    cout <<""<<endl;
}
void Heap_Sort(int *a , int len){
    Heap *heap;
    InitHeap(&heap , len , a);
    //建初堆
    for(int i = heap->Size/2 ;i > 0 ;i--)
        PercDown(heap , i);
    PrintHeap(heap);
    int t[10];
    for(int j = 0 ;j < 10 ;j ++){
        a[j] = DeleteNode(heap);
    }
}

/**
 * 快速排序
 *
 * S=O(LOG2N)
 * best pivot中分 T=O(NlogN) S=O(NLOG2N)
 * worst pivot[0] T=O(N^2) S=O(N)
 * 不适用于链表
 * 适用于N较大,无序
 */
void Swap(int *a , int left , int right){
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}
int Median3(int *a , int left , int right){
    int median = (left +right)/2;
    if(a[median] < a[left])
        Swap(a , left , median);
    if(a[right] < a[left])
        Swap(a , left , right);
    if(a[median] > a[right])
        Swap(a , median , right);
    Swap(a , median , right-1);
    return a[right -1];
}
void Quick_Sort(int *a , int left , int right){
    if(Cutoff < right -left){
        int pivot = Median3(a , left , right);
        int Low = left , High = right -1;
        for(;;){
            while(a[++Low] < pivot);
            while(pivot < a[--High]);
            if(High < Low)
                break;
            else
                Swap(a , Low , High);
        }

        Swap(a , Low , right - 1);
        Quick_Sort(a , left , Low-1);
        Quick_Sort(a , Low + 1 , right);
    }else{
        Insertion_Sort(a + left , right -left + 1);
    }

}
void QSort(int *a , int len){
    Quick_Sort(a , 0 , len -1);
}

void printArray(int *a , int len){
    for(int i = 0 ;i < len ;i ++){
        cout << a[i] <<" ";
    }
    cout <<""<<endl;
}

int main(){
    int a[] = {5 , 2 , 8 ,1 ,9 , 0 , 4 ,3 ,7 ,6};
    //Bubble_Sort(a , 10);
    //printArray(a , 10);

    //Insertion_Sort(a , 10);
    //printArray(a , 10);

    //int a1[] = {100 , 5 , 2 , 8 , 1 , 9 , 0 ,4 , 3 , 7 , 6};
    //Bin_Insertion_Sort(a1 , 10);
    //printArray2(a1 , 10);

    //Sell_Sort(a , 10);
    //printArray(a , 10);

    //QSort(a , 10);
    //printArray(a , 10);

    //Selection_Sort(a , 10);
    //printArray(a , 10);

    Heap_Sort(a , 10);
    printArray(a , 10);

    return 0;
}
