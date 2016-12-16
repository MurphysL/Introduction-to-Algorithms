#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

typedef struct Graph{
    int arcs[MAX][MAX];
    int vexs[MAX];
    int arcnum ,vexnum;
}Graph;

void CreateGraph(Graph **graph){
    *graph = new Graph;
    cout << "输入图的结点个数及边数:" <<endl;
    cin >> (*graph)->vexnum >> (*graph)->arcnum;
    cout <<"输入边的顶点及权重:" <<endl;
    for(int i = 0 ;i < (*graph)->vexnum ;i ++){
        for(int j= 0;j < (*graph)->vexnum ;j ++){
            (*graph)->arcs[i][j] = MAX;
        }
    }

    for(int i = 0 ;i <(*graph)->arcnum ;i ++){
        int v1 , v2 ;
        cin >> v1 >> v2;
        cin >> (*graph)->arcs[v1][v2];
    }
}

void PrintGraph(Graph *graph){
    for(int i = 0 ;i < graph->vexnum ;i ++){
        for(int j = 0 ; j < graph->vexnum ;j ++){
            cout << graph->arcs[i][j] << "   ";
        }
        cout << " "<<endl;
    }
}

int dist[MAX];
int path[MAX];
bool Visited[MAX];
int FindMinDist(Graph *graph){
    int minValue = MAX;
    for(int i = 0 ;i < graph->vexnum ;i ++){
        if(dist[i] < minValue && !Visited[i]){
            minValue = i;
        }
    }
    return minValue;
}
void Dijkstra(Graph *graph){
    for(int i = 0 ;i < graph->vexnum ;i ++){
        dist[i] = MAX;
        path[i] = -1;
        Visited[i] = false;
    }

    dist[0] = 0;
    for(int i = 0 ;i < graph->vexnum ;i ++){
        if(graph->arcs[0][i] != MAX){
            dist[i] = graph->arcs[0][i];
            path[i] = 0;
        }
    }
    Visited[0] = true;

    while(true){
        int v = FindMinDist(graph);
        if(v == MAX)
            break;
        Visited[v] = true;
        for(int i = 0 ;i < graph->vexnum ;i ++){
            if(graph->arcs[v][i] != MAX && dist[i] > dist[v] +graph->arcs[v][i]){
                dist[i] = dist[v] +graph->arcs[v][i];
                path[i] = v;
            }
        }
    }
}

int main(){
    Graph *graph;
    CreateGraph(&graph);
    PrintGraph(graph);

    Dijkstra(graph);
    for(int i = 0 ;i < graph->vexnum ;i ++)
        cout << dist[i] << " " << path[i] <<endl;
    return 0;
}
