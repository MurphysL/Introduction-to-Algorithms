#include <iostream>
#define Cutoff 100
using namespace std;

/**
 * ������
 *
 * if A[i]>A[j] (i,j)��һ��inversion(�����)
 * ��������Ԫ����ȥһ�������
 *
 * ����N����ͬԪ����ɵ�����ƽ������ N(N-1)/4 �������
 * ������Խ�������Ԫ�ص������㷨,ƽ��ʱ�临�Ӷ�Ϊ��(N^2)
 *
 * ���Ч��:
 * 1.��ȥ��ֹһ�������
 * 2.���������Զ��2Ԫ��
 */

/**
 * ð������
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
 * ��������
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
 *ϣ������(�����������
 */
void Sell_Sort(int *a , int len){
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};//��������
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
 * ��������
 * best pivot�з� T=O(NlogN)
 * worst pivot[0] T=O(N^2)
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

    Sell_Sort(a , 10);
    printArray(a , 10);

    //QSort(a , 10);
    //printArray(a , 10);
    return 0;
}
