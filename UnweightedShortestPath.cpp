#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

typedef struct ENode{
    int adjvex;
    ENode *next;
}ENode;

typedef struct VNode{
    int data;
    ENode *firstNode;
}VNode , AdjList[MAX];

typedef struct Graph{
    int vexnum , arcnum;
    AdjList adjlist;
}Graph;

typedef struct Queue{
    int front , rear;
    VNode vnode[MAX];
    int Capacity;
}Queue;

void CreateGraph(Graph **graph){
    *graph = new Graph;
    cout << "����ͼ�Ķ�����������:" <<endl;
    cin >> (*graph)->vexnum >>(*graph)->arcnum;
    for(int i = 0 ;i < (*graph)->vexnum ;i ++){
        (*graph)->adjlist[i].firstNode = NULL;
        (*graph)->adjlist[i].data = i;
    }
    cout << "����·���Ķ�����Ϣ(��0��ʼ):"<<endl;
    for(int i = 0 ;i < (*graph)->arcnum ;i ++){
        int v1 , v2;
        cin >> v1 >> v2;
        ENode *enode = new ENode;
        enode->adjvex = v2;
        enode->next = (*graph)->adjlist[v1].firstNode;
        (*graph)->adjlist[v1].firstNode = enode;
    }
}

void EnQueue(Queue *queue , VNode vnode){
    queue->vnode[++queue->rear] = vnode;
}

VNode DeQueue(Queue *queue){
    return queue->vnode[++queue->front];
}

bool isEmpty(Queue *queue){
    return queue->rear == queue->front;
}

int dist[MAX];
int path[MAX];
void UnWeight(Graph *graph , int origin){
    Queue *queue = new Queue;
    queue->front = 0;
    queue->rear = 0;
    queue->Capacity = graph->vexnum + 1;
    VNode vnode = graph->adjlist[origin];
    EnQueue(queue , vnode);

    for(int i = 0 ;i < graph->vexnum ;i ++){
        dist[i] = path[i] = -1;
    }
    dist[origin] = 0;

    while(!isEmpty(queue)){
        VNode vnode = DeQueue(queue);
        ENode *enode = vnode.firstNode;
        cout << "�ѱ���" <<vnode.data <<endl;
        while(enode != NULL){
            if(dist[enode->adjvex] == -1){
                EnQueue(queue , graph->adjlist[enode->adjvex]);
                dist[enode->adjvex] = dist[vnode.data] + 1;
                path[enode->adjvex] = vnode.data;
            }
            enode =enode->next;
        }
    }

    cout <<
}

int main(){
    Graph *graph;
    CreateGraph(&graph);

    cout << "��������ʼ���:" <<endl;
    int origin ;
    cin >>origin;
    UnWeight(graph, origin);
    for(int i = 0 ;i < graph->vexnum ;i ++){
        cout << dist[i] << " " <<path[i] <<endl;
    }
    return 0;
}
