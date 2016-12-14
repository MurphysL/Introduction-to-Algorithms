#include <iostream>
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
 *ϣ������
 */
void Sell_Sort(int *a , int len){
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};//��������
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
