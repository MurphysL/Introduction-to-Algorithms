#include <iostream>
#include <stdlib.h>
#define MAX 1000
using namespace std;

/**
 * 拓扑排序
 *
 * 有向无环图
 */

typedef struct ENode{
    int adj;
    int num;
    ENode *next;
}ENode;

typedef struct VNode{
    int num;
    string className;
    ENode *firstNode;
}VNode , AdjList[MAX];

typedef struct Graph{
    int vexnum , arcnum;
    AdjList adjlist;
}Graph;

typedef struct Queue{
    int front;
    int Capacity;
    int rear;
    int *num;
}Queue;

int *InDegree;

void InitGraph(Graph **graph){
    *graph = new Graph;
    cout << "输入课程数目及关联数:" <<endl;
    cin >> (*graph)->vexnum >> (*graph)->arcnum;

    InDegree = (int *)malloc(((*graph)->vexnum) * sizeof(int));
    for(int i =0 ;i < (*graph)->vexnum ;i ++)
        InDegree[i] = 0;

    cout << "输入课程名称及编号:" <<endl;
    for(int i = 0 ;i < (*graph)->vexnum ;i ++){
        cin >> (*graph)->adjlist[i].className;
        cin >> (*graph)->adjlist[i].num;
        (*graph)->adjlist[i].firstNode = NULL;
    }

    cout << "输入先修课程与后修课程序号:" <<endl;
    int v1 , v2;
    for(int i = 0 ;i < (*graph)->arcnum ;i ++){
        cin >> v1 >> v2;
        ENode *enode = new ENode;
        enode->adj = v1;
        enode->num = v2;
        enode->next = (*graph)->adjlist[v1].firstNode;
        (*graph)->adjlist[v1].firstNode= enode;

        ++ InDegree[v2];
    }
}

void PrintGraph(Graph *graph){
    for(int i = 0 ;i < graph->vexnum ;i ++){
        ENode *node = graph->adjlist[i].firstNode;
        cout << i << " ";
        while(node){
            cout << graph->adjlist[node->num].className;
            node = node->next;
        }
        cout << " " <<endl;
    }
}

void InitQueue(Queue **queue , Graph *graph){
    (*queue)->front =0;
    (*queue)->rear = 0;
    (*queue)->Capacity = graph->vexnum;
    (*queue)->num = (int *)malloc(sizeof(int) * graph->vexnum);
}

bool isEmpty(Queue *queue){
    return queue->rear == queue->front;
}

bool isFull(Queue *queue){
    return queue->rear == queue->Capacity;
}

void InQueue(Queue *queue , int num){
    if(!isFull(queue)){
        queue->num[++ queue->rear] = num;
    }
}

int DeQueue(Queue *queue){
    if(!isEmpty(queue)){
        int num = queue->num[++queue->front];
    }
}

void TopSort(Graph *graph , Queue *queue){
    cout << "拓扑序:" <<endl;
    for(int i = 0 ; i < graph->vexnum ;i ++){
        if(InDegree[i] == 0)
            InQueue(queue , i);
    }

    while(!isEmpty(queue)){
        int num = DeQueue(queue);
        cout << graph->adjlist[num].className;
        ENode *node = graph->adjlist[num].firstNode;
        while(node){
            if((--InDegree[node->num])== 0)
                InQueue(queue , node->num);
            node = node->next;
        }
    }

}

int main(){
    Graph *graph;
    Queue *queue;

    InitGraph(&graph);
    InitQueue(&queue , graph);

    TopSort(graph , queue);
    return 0;
}
