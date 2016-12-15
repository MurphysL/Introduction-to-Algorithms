#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

/**
 * �ڽӾ���
 */
typedef struct AMGraph{
    char vexs[MAX];
    int arcs[MAX][MAX];
    int vexnum , arcnum;
}AMGraph;

/**
 * �ڽӱ�
 */
typedef struct EdgeNode{
    int weight;
    int adjvex;
    EdgeNode *next;
}EdgeNode;

typedef struct VNode{
    char data;
    EdgeNode *firstNode;
}AdjList[MAX];

typedef struct Graph{
    AdjList adjlist;
    int vexNum;
    int arcNum;
}Graph;

void CreateUDGraph(AMGraph *graph){
    cout << "���붥����������:"<< endl;
    cin >> graph->vexnum;
    cin >> graph->arcnum;

    cout << "���붥������" <<endl;
    for(int i = 0 ;i <graph->vexnum ;i ++){
        cin >> graph->vexs[i];
    }

    cout << "�������Ϣ" <<endl;
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
    cout << "���붥����������:" <<endl;
    cin >> (*graph)->vexNum >> (*graph)->arcNum;

    cout <<"���붥������" <<endl;
    for(int i = 0 ;i < (*graph)->vexNum;i ++){
        cin >> (*graph)->adjlist[i].data;
        (*graph)->adjlist[i].firstNode = NULL;
    }

    cout <<"����ߵĶ��㼰Ȩ��:" <<endl;
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
void DFS(AMGraph * graph , int i){
    Visited[i] = true;
    cout << "�ѱ���" << graph->vexs[i] <<endl;
    for(int j = 0 ; j < graph->vexnum;j ++){
        if(graph->arcs[i][j] != MAX && !Visited[j]){
            DFS(graph , j);
        }
    }
}
void DFSTraverse(AMGraph *graph){
    for(int i = 0 ;i < graph->vexnum ; i ++){
        Visited[i] = false;
    }

    for(int i = 0 ;i < graph->vexnum ; i++){
        if(!Visited[i]){
            DFS(graph , i);
        }
    }
}
void DFS2(Graph *graph , int i){
    Visited[i] = true;
    EdgeNode *node = graph->adjlist[i].firstNode;
    cout << "�ѱ���" <<graph->adjlist[i].data << endl;
    while(node != NULL){
        if(!Visited[node->adjvex])
            DFS2(graph , node->adjvex);
        node = node->next;
    }
}
void DFSTraverse2(Graph *graph){
    for(int i = 0 ;i < graph->vexNum ;i ++){
        Visited[i] = false;
    }

    for(int i = 0 ;i < graph->vexNum ;i ++){
        if(!Visited[i]){
            DFS2(graph , i);
        }
    }
}

int main(){
    //AMGraph *graph = new AMGraph;
    //CreateUDGraph(graph);
    //printUDGraph(graph);

    //cout << "DFS����:" <<endl;
    //DFSTraverse(graph);

    Graph *graph;
    CreateGraph(&graph);
    DFSTraverse2(graph);
    return 0;
}
