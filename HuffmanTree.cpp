#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 1000
#define MIN -1000
using namespace std;

typedef struct Bean{
    int num;
    char c;
}Bean;

typedef struct HuffmanTree{
    int weight;
    char c;
    HuffmanTree *left , *right;
}HuffmanTree;

typedef struct MinHeap{
    int *num;
    char *c;
    int Size;
    int Capacity;
}MinHeap;

void InitHeap(MinHeap **heap){
    *heap = new MinHeap;
    int n;
    cout <<"请输入最大容量:" <<endl;
    cin >>n;
    (*heap)->num = (int *)malloc(n * sizeof(heap));
    (*heap)->num[0] = MIN;
    (*heap)->Capacity = n;
    (*heap)->Size = 0;
    (*heap)->c = (char *)malloc(n * sizeof(heap));
    (*heap)->c[0] = '#';
}

bool isFull(MinHeap *heap){
    return heap->Size == heap->Capacity;
}

bool isEmpty(MinHeap *heap){
    return heap->Size == 0;
}

void CreateOriginHeap(MinHeap *heap){
    int n;
    char c;
    cout << "请输入字符及权值(以\"# 0\"结束):" <<endl;
    cin >> c >> n;
    while(c != '#' && !isFull(heap)){
        heap->num[++ heap->Size] = n;
        heap->c[heap->Size] = c;
        cin >> c >>n;
    }
}

void PrintHeap(MinHeap *heap){
    for(int i = 1 ;i <= heap->Size ;i ++){
        cout << heap->num[i] <<heap->c[i]<< " ";
    }
    cout << ""<<endl;
}

void PercDown(MinHeap *heap , int p){
    int Parent , Child;
    int X = heap->num[p];
    char c = heap->c[p];
    for(Parent = p; Parent*2 <= heap->Size;Parent = Child){
        Child = Parent *2;
        if(heap->num[Child] > heap->num[Child+ 1])
            Child ++;
        if(heap->num[Child] < X){
            heap->num[Parent] = heap->num[Child];
            heap->c[Parent] = heap->c[Child];
        }else{
            break;
        }
    }
    heap->num[Parent] = X;
    heap->c[Parent] = c;
}

Bean *DeleteNode(MinHeap *heap){
    int minNode = heap->num[1];
    char minc = heap->c[1];
    Bean *bean = new Bean;
    bean->c = minc;
    bean->num = minNode;

    cout << "未排序"<<endl;
    PrintHeap(heap);
    heap->num[1] = heap->num[heap->Size];
    heap->c[1] = heap->c[heap->Size];
    cout << "删除节点"<<endl;
    PrintHeap(heap);

    heap->Size --;
    PercDown(heap , 1);

    return bean;
}

void PreOrderTraversal(HuffmanTree *huffmanTree){
    if(huffmanTree != NULL){
        cout << huffmanTree->c << huffmanTree->weight << endl;
        PreOrderTraversal(huffmanTree->left);
        PreOrderTraversal(huffmanTree->right);
    }
}

MinHeap *InsertHeap(MinHeap *heap , int num , char c){
    if(!isFull(heap)){
        heap->num[++ heap->Size] = num;
        heap->c[heap->Size] = c;
        PercDown(heap , 1);
    }
    return heap;
}

HuffmanTree *CreateHuffmanTreeNode(Bean *num , HuffmanTree *huffmanTree ,MinHeap *heap , bool isleft){
    HuffmanTree *T = new HuffmanTree;
    T->c = '#';
    HuffmanTree *t = new HuffmanTree;
    if(isleft){
        t->weight = num->num;
        t->c = num->c;
        t->left = t->right = NULL;
        T->left = huffmanTree->left;
        T->right = t;
        T->weight = huffmanTree->left->weight + t->weight;
        huffmanTree->weight += num->num;
        huffmanTree->left = T;
        InsertHeap(heap , T->weight , T->c);
    }else{
        t->weight = num->num;
        t->c = num->c;
        t->left = t->right = NULL;
        T->right = huffmanTree->right;
        T->left = t;
        T->weight = huffmanTree->right->weight + t->weight;
        huffmanTree->weight += num->num;
        huffmanTree->right = T;
        InsertHeap(heap , T->weight ,T->c);
    }

    return huffmanTree;
}

HuffmanTree *InitHuffmanTree(MinHeap *heap){
    Bean *a , *b;
    a = DeleteNode(heap);
    b = DeleteNode(heap);

    HuffmanTree *huffmanTree = new HuffmanTree;
    HuffmanTree *left = new HuffmanTree;
    HuffmanTree *right = new HuffmanTree;
    huffmanTree->left = left;
    huffmanTree->right = right;
    huffmanTree->c = '#';

    HuffmanTree *t1 = new HuffmanTree;
    t1->left = t1->right = NULL;
    t1->weight = a->num;
    t1->c = a->c;
    HuffmanTree *t2 = new HuffmanTree;
    t2->left = t2->right = NULL;
    t2->weight = b->num;
    t2->c = b->c;
    left->weight = a->num + b->num;
    left->c = '#';

    left->left = t1;
    left->right = t2;

    right->left = right->right = NULL;
    right->weight = 0;
    right->c = '#';

    huffmanTree->weight = a->num + b->num;
    InsertHeap(heap , a->num + b->num , '#');

    return huffmanTree;
}

HuffmanTree *CreateHuffmanTree(HuffmanTree *huffmanTree ,MinHeap *heap){
    while(heap->Size > 2){
        Bean *a , *b;
        a = DeleteNode(heap);
        b = DeleteNode(heap);
        cout << "删除数" <<a->c<<a->num << b->c<<b->num<<endl;
        if(a->num > b->num){
            int t = a->num;
            char c = a->c;
            a->num = b->num;
            a->c = b->c;
            b->c = a->c;
            b->num = c;
        }
        if(a->num != huffmanTree->left->weight && b->num != huffmanTree->right->weight){
            HuffmanTree *t1 = new HuffmanTree;
            HuffmanTree *t2 = new HuffmanTree;
            t1->weight = a->num;
            t1->c = a->c;
            t1->left= t1->right = NULL;
            t2->weight = b->num;
            t2->c = b->c;
            t2->left= t2->right = NULL;
            huffmanTree->right->right = t1;
            huffmanTree->right->left = t2;
            huffmanTree->right->weight = huffmanTree->right->right->weight + huffmanTree->right->left->weight;
            huffmanTree->weight = huffmanTree->left->weight + huffmanTree->right->weight;
            InsertHeap(heap , a->num +b->num , '#');
        }else{
            if(a->num == huffmanTree->left->weight){
                if(a->c == '#')
                    CreateHuffmanTreeNode(b , huffmanTree,heap , true);
                else
                    CreateHuffmanTreeNode(a , huffmanTree,heap , true);
            }else{
                if(a->c == '#')
                    CreateHuffmanTreeNode(a , huffmanTree,heap , true);
                else
                    CreateHuffmanTreeNode(b , huffmanTree,heap , true);
            }
        }
    }
    return huffmanTree;
}

void PrintHuffmanCode(HuffmanTree *huffmanTree , char *code , int n){
    if(huffmanTree != NULL){
        if(huffmanTree->c != '#'){
            cout << huffmanTree->c <<endl;
            for(int i = 1;i <= n ;i ++){
                cout <<code[i];
            }
            cout <<""<<endl;
        }

        code[n] = '0';
        PrintHuffmanCode(huffmanTree->left , code , n + 1);
        code[n] = '1';
        PrintHuffmanCode(huffmanTree->right , code , n + 1);
    }
}

int main(){
    int num;
    MinHeap *minHeap;
    HuffmanTree *huffmanTree;
    InitHeap(&minHeap);
    CreateOriginHeap(minHeap);
    num = minHeap->Size;
    cout << "原始二叉树" <<endl;
    PrintHeap(minHeap);

    for(int i = minHeap->Size/2 ;i > 0 ;i --){
        PercDown(minHeap , i);
    }

    cout <<"最小堆" <<endl;
    PrintHeap(minHeap);

    cout << "HuffmanTree :" <<endl;
    huffmanTree = InitHuffmanTree(minHeap);
    huffmanTree = CreateHuffmanTree(huffmanTree , minHeap);
    PreOrderTraversal(huffmanTree);

    cout << "Huffman编码 :" <<endl;
    int n = 1;
    while(num < pow(2,n - 1) || num > pow(2 , n))
        n ++;
    char code[n];
    PrintHuffmanCode(huffmanTree , code , 1);
    return 0;
}
