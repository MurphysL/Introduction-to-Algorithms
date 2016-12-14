#include <iostream>
using namespace std;

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
 * best T=O(N)
 * worst T=O(N^2)
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
 * 插入排序
 * best T=O(N)
 * worst T=O(N^2)
 *
 * T(N,I)=O(N+I)
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
 *希尔排序
 */
void Sell_Sort(int *a , int len){
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};//增量序列
    int  i , n;
    for(i = 0 ;Sedgewick[i] > len ; i ++){}

    for(int j = i ; j <= 9;j ++){
        for(int m = j ;m < len;m ++){
            int temp = a[m];
            for(n = m;n >0 && a[n - Sedgewick[j]] > temp ;n += Sedgewick[j]){
                a[n] = a[n - Sedgewick[j]];
            }
            a[n] = temp;
        }
    }
}

void printArray(int *a , int len){
    for(int i = 0 ;i < len ;i ++){
        cout << a[i] <<" ";
    }
    cout <<""<<endl;
}

int main(){
    int a[] = {5 , 2 , 8 ,1 ,9 , 0 , 4 ,3 ,7 ,6};
    Bubble_Sort(a , 10);
    printArray(a , 10);

    Insertion_Sort(a , 10);
    printArray(a , 10);

    Sell_Sort(a , 10);
    printArray(a , 10);
    return 0;
}
