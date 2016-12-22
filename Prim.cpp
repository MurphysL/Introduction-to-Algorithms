#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

typedef struct Graph{
    int arcs[MAX][MAX];
    int vexnum , arcnum;
}Graph;

void InitGraph(Graph **graph){
    *graph = new Graph;
    cout << "输入图的节点数及边数:" <<endl;
    cin >> (*graph)->vexnum >> (*graph)->arcnum;
    for(int i = 0 ;i < (*graph)->vexnum;i++)
        for(int j =0 ;j < (*graph)->vexnum ;j ++)
            (*graph)->arcs[i][j] = MAX;

    cout << "输入边节点及权重:" <<endl;
    for(int i = 0 ; i< (*graph)->arcnum ;i ++){
        int m , n;
        cin >>m >> n;
        cin >> (*graph)->arcs[m][n];
        (*graph)->arcs[n][m] = (*graph)->arcs[m][n];
    }
}

/**
 * 寻找与生成树相邻最近的点
 */
int FindMinNode(Graph *graph ,int *dist){
    int min = MAX , minPos = 0;
    for(int i = 0 ;i < graph->vexnum ;i ++){
        if(dist[i] != -1 && dist[i] < min){
            min = dist[i];
            minPos = i;
        }
    }
    if(min != MAX)
        return minPos;
    else
        return -1;
}

int Prim(Graph *graph ){
    int dist[graph->vexnum];
    int mst[graph->vexnum];

    //初始化生成树
    for(int i = 0 ;i < graph->vexnum ;i ++){
         dist[i] = MAX;
         mst[i] = MAX;
    }
    dist[0] = -1;//从0节点遍历
    mst[0] = 0;
    for(int i = 1 ;i < graph->vexnum ;i ++){
         dist[i] = graph->arcs[0][i];
         if(dist[i] != MAX)
            mst[i] = 0;
    }
    int Parent = 0;

    while(true){
        int min = FindMinNode(graph , dist);
        if(min == -1)
            break;
        dist[min] = -1;
        for(int i = 0 ;i < graph->vexnum ;i ++)
            if(dist[i] != -1 && graph->arcs[min][i] != MAX)
                mst[i] = min;

        cout << mst[min] << "-" <<min << " "<<graph->arcs[mst[min]][min]<<endl;
        Parent = min;
        for(int i = 0 ;i < graph->vexnum ;i ++)
            if(graph->arcs[Parent][i] != -1 && graph->arcs[Parent][i] != MAX && graph->arcs[Parent][i] < dist[i]){
                dist[i] = graph->arcs[Parent][i];
            }
    }

    int pathLen = 0;
    for(int i = 1 ;i < graph->vexnum ;i ++){
        pathLen += graph->arcs[i][mst[i]];
    }
    return pathLen;
}

void PrintGraph(Graph *graph){
    for(int i = 0;i < graph->vexnum ;i ++){
        for(int j = 0 ;j < graph->vexnum ;j ++){
            printf("%3d ", graph->arcs[i][j]);
        }
        cout <<"" <<endl;
    }
}

int main(){
    Graph *graph;
    InitGraph(&graph);
    cout <<"--------------------------"<<endl;
    PrintGraph(graph);
    cout <<"--------------------------"<<endl;
    cout << "最短长度:" << Prim(graph);

    return 0;
}
