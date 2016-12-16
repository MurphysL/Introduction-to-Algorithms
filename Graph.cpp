#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

/**
 * 邻接矩阵
 */
typedef struct AMGraph{
    char vexs[MAX];
    int arcs[MAX][MAX];
    int vexnum , arcnum;
}AMGraph;

/**
 * 邻接表
 */
typedef struct EdgeNode{
    int weight;
    int adjvex;
    EdgeNode *next;
}EdgeNode;

typedef struct VNode{
    char data;
    EdgeNode *firstNode;
}VNode , AdjList[MAX];

typedef struct Graph{
    AdjList adjlist;
    int vexNum;
    int arcNum;
}Graph;

typedef struct Queue{
    VNode node[MAX];
    int Capacity;
    int front , rear;
}Queue;

void CreateUDGraph(AMGraph *graph){
    cout << "输入顶点数及边数:"<< endl;
    cin >> graph->vexnum;
    cin >> graph->arcnum;

    cout << "输入顶点名称" <<endl;
    for(int i = 0 ;i <graph->vexnum ;i ++){
        cin >> graph->vexs[i];
    }

    cout << "输入边信息" <<endl;
    for(int i = 0 ;i < graph->vexnum;i ++){
        for(int j = 0;j < graph->vexnum ;j ++){
            graph->arcs[i][j] = MAX;
        }
    }

    for(int i  = 0 ;i < graph->arcnum ;i ++){
        int v1 , v2 ,weight;
        cin >> v1 >> v2 >>weight;
        graph->arcs[v1-1][v2-1] = weight;
        graph->arcs[v2-1][v1-1] = weight;
    }
}

void printUDGraph(AMGraph *graph){
    for(int i = 0 ;i < graph->vexnum;i ++){
        for(int j = 0 ;j < graph->vexnum ;j ++){
            cout << graph->arcs[i][j] << "    ";
        }
        cout << "" <<endl;
    }
}

void CreateGraph(Graph **graph){
    *graph = new Graph;
    cout << "输入顶点数及边数:" <<endl;
    cin >> (*graph)->vexNum >> (*graph)->arcNum;

    cout <<"输入顶点名称" <<endl;
    for(int i = 0 ;i < (*graph)->vexNum;i ++){
        cin >> (*graph)->adjlist[i].data;
        (*graph)->adjlist[i].firstNode = NULL;
    }

    cout <<"输入边的顶点及权重:" <<endl;
    for(int a = 0 ;a < (*graph)->arcNum ; a ++){
        int i , j , weight;
        cin >> i >> j >>weight;
        EdgeNode *node = new EdgeNode;
        node->adjvex = j - 1;
        node->weight = weight;
        node->next = (*graph)->adjlist[i - 1].firstNode;
        (*graph)->adjlist[i - 1].firstNode = node;

        node = new EdgeNode;
        node->adjvex = i - 1;
        node->weight = weight;
        node->next = (*graph)->adjlist[j - 1].firstNode;
        (*graph)->adjlist[j - 1].firstNode = node;
    }
}

bool Visited[MAX];
/**
 * 邻接矩阵深度优先遍历
 */
void DFS(AMGraph * graph , int i){
    Visited[i] = true;
    cout << "已遍历" << graph->vexs[i] <<endl;
    for(int j = 0 ; j < graph->vexnum;j ++){
        if(graph->arcs[i][j] != MAX && !Visited[j]){
            DFS(graph , j);
        }
    }
}
void DFSTraverse(AMGraph *graph){
    cout << "DFS遍历:" <<endl;
    for(int i = 0 ;i < graph->vexnum ; i ++){
        Visited[i] = false;
    }

    for(int i = 0 ;i < graph->vexnum ; i++){
        if(!Visited[i]){
            DFS(graph , i);
        }
    }
}
/**
 * 邻接表深度优先遍历
 */
void DFS2(Graph *graph , int i){
    Visited[i] = true;
    EdgeNode *node = graph->adjlist[i].firstNode;
    cout << "已遍历" <<graph->adjlist[i].data << endl;
    while(node != NULL){
        if(!Visited[node->adjvex])
            DFS2(graph , node->adjvex);
        node = node->next;
    }
}
void DFSTraverse2(Graph *graph){
    cout << "DFS遍历:" <<endl;
    for(int i = 0 ;i < graph->vexNum ;i ++){
        Visited[i] = false;
    }

    for(int i = 0 ;i < graph->vexNum ;i ++){
        if(!Visited[i]){
            DFS2(graph , i);
        }
    }
}

/**
 * 队满
 */
bool isQueueFull(Queue *queue){
    return (queue->rear + 1) % queue->Capacity == queue->front;
}

/**
 * 队空
 */
bool isQueueEmpty(Queue *queue){
    return queue->rear == queue->front;
}

/**
 * 入队
 */
bool EnQueue(Queue *queue , VNode vnode){
    if(!isQueueFull(queue)){
        queue->node[++ queue->rear] = vnode;
        return true;
    }
    return false;
}

/**
 * 出队
 */
VNode DeQueue(Queue *queue){
    if(!isQueueEmpty(queue)){
        VNode node = queue->node[queue->rear];
        queue->rear --;
        return node;
    }
}

/**
 * 广度优先遍历
 */
void BFS(Graph *graph , int i ,Queue *queue){
    VNode node = graph->adjlist[i];
    cout <<"已遍历:" << node.data << endl;
    Visited[i] = true;
    if(!EnQueue(queue , node)){
        VNode vnode = DeQueue(queue);
        EdgeNode *enode = vnode.firstNode;
        while(enode){
            if(!Visited[enode->adjvex]){
                EnQueue(queue , graph->adjlist[enode->adjvex]);
            }
            enode = enode->next;
        }
    }
}
void BFSTraverse(Graph *graph){
    Queue *queue = new Queue;
    queue->Capacity = graph->vexNum;
    queue->front = 0;
    queue->rear = 0;
    //queue->node[0] = NULL;

    for(int i = 0 ; i < graph->vexNum ;i ++){
        Visited[i] = false;
    }

    for(int i = 0 ;i < graph->vexNum ;i ++){
        if(!Visited[i]){
            BFS(graph , i , queue);
        }
    }
}

int main(){
    //AMGraph *graph = new AMGraph;
    //CreateUDGraph(graph);
    //printUDGraph(graph);

    //DFSTraverse(graph);

    Graph *graph;
    CreateGraph(&graph);
    DFSTraverse2(graph);

    cout << "BFS遍历:" <<endl;
    BFSTraverse(graph);
    return 0;
}
