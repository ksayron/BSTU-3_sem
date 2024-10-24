#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct edge
{
    int x;
    int y;
    int dist;
    bool tree=false;
    edge() {}
};

bool compareEdge(edge a, edge b)
{
    return (a.dist < b.dist);
}

void AddEdge(int graph[8][8], int a, int b, int dist) {
    graph[a - 1][b - 1] = dist;
    graph[b - 1][a - 1] = dist;
}

void AddEdge(edge &e, int a, int b, int dist) {
    e.x = a;
    e.y = b;
    e.dist = dist;
}

int main()
{
    int graph[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            i == j ? graph[i][j] = 0 : graph[i][j] = INT32_MAX;

        }
    }
    std::cout << std::endl;

    AddEdge(graph, 1, 2, 2);
    AddEdge(graph, 1, 5, 2);
    AddEdge(graph, 1, 4, 8);
    AddEdge(graph, 2, 3, 3);
    AddEdge(graph, 2, 4,10);
    AddEdge(graph, 2, 5, 5);
    AddEdge(graph, 3, 5,12);
    AddEdge(graph, 3, 8, 7);
    AddEdge(graph, 4, 5,14);
    AddEdge(graph, 4, 6, 3);
    AddEdge(graph, 4, 7, 1);
    AddEdge(graph, 5, 6,11);
    AddEdge(graph, 5, 7, 4);
    AddEdge(graph, 5, 8, 8);
    AddEdge(graph, 6, 7, 6);
    AddEdge(graph, 7, 8, 9);
    #pragma region prim
    int min_v = INT32_MAX, min_i = 0, min_j = 0,sum=0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (graph[i][j] == INT32_MAX) std::cout << "inf" << "\t";
            else std::cout << graph[i][j] << "\t";
           // if (graph[i][j] < min_v && i!=j) { min_v = graph[i][j]; min_i = i; min_j = j; }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int size = 1;
    int versh[8];    
    int start;
    std::cin >> start;
    versh[0] = start-1;
    for (int k = 0; k < 8; k++) {
        graph[start-1][k] = INT32_MAX;
    }
    while(size<8) {
        
        for (int v = 0; v < size; v++) {
            for (int j = 0; j < 8; j++) {
                if (graph[j][versh[v]] < min_v && versh[v] != j) { min_v = graph[j][versh[v]]; min_i = j; min_j = versh[v]; }
            }

        }

        versh[size] = min_i;
        size++;
            
        std::cout << "edge: " << min_i + 1 << ' ' << min_j + 1 << " dist: " << min_v << ' ' << "\n";
        sum += min_v;
        min_v = INT32_MAX;

        for (int k = 0; k < 8; k++) {
            graph[min_i][k] = INT32_MAX;
            graph[min_j][k] = INT32_MAX;
        }
    }
    std::cout << sum;
    #pragma endregion
    #pragma region краскал
    edge e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16;
    AddEdge(e1 , 1, 2, 2);
    AddEdge(e2 , 1, 5, 2);
    AddEdge(e3 , 1, 4, 8);
    AddEdge(e4 , 2, 3, 3);
    AddEdge(e5 , 2, 4,10);
    AddEdge(e6 , 2, 5, 5);
    AddEdge(e7 , 3, 5,12);
    AddEdge(e8 , 3, 8, 7);
    AddEdge(e9 , 4, 5,14);
    AddEdge(e10, 4, 6, 3);
    AddEdge(e11, 4, 7, 1);
    AddEdge(e12, 5, 6,11);
    AddEdge(e13, 5, 7, 4);
    AddEdge(e14, 5, 8, 8);
    AddEdge(e15, 6, 7, 6);
    AddEdge(e16, 7, 8, 9);
    std::vector<edge> edgeList = {e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16 };
    sort(edgeList.begin(), edgeList.end(), compareEdge);
    int subgraph[8] = { 0,0,0,0,0,0,0,0 };
    std::cout << "\n\n";
    
    for (edge e : edgeList) {
        std::cout << e.x << " " << e.y << " " << e.dist << "\n";
    }
    std::cout << "\n\n";
    int subgraph_count = 1;
    int temp;
    for (int e=0; e < edgeList.size(); e++) {
        if (subgraph[edgeList[e].x - 1] == 0 || subgraph[edgeList[e].y - 1] == 0) {
            if (subgraph[edgeList[e].x - 1] == subgraph[edgeList[e].y - 1]) {
                subgraph[edgeList[e].x - 1] = subgraph_count;
                subgraph[edgeList[e].y - 1] = subgraph_count++;
                edgeList[e].tree = true;
            }
            else {
                subgraph[edgeList[e].x - 1] = std::max(subgraph[edgeList[e].x - 1], subgraph[edgeList[e].y - 1]);
                subgraph[edgeList[e].y - 1] = std::max(subgraph[edgeList[e].x - 1], subgraph[edgeList[e].y - 1]);
                edgeList[e].tree = true;
            }
        }
        else {
            if (subgraph[edgeList[e].x - 1]  != subgraph[edgeList[e].y - 1]) {
                temp = std::max(subgraph[edgeList[e].x - 1], subgraph[edgeList[e].y - 1]);
                for (int i = 0; i < 8;i++) {
                    if (subgraph[i] == temp) {
                        subgraph[i] = std::min(subgraph[edgeList[e].x - 1], subgraph[edgeList[e].y - 1]);
                    }
                }
                edgeList[e].tree = true;

            }
        }
    }
    sum = 0;
    std::cout << "\n\n";
    for (edge e : edgeList) {
        if(e.tree){
            std::cout <<"edge: "<< e.x << " " << e.y << " dist: " << e.dist << "\n";
            sum += e.dist;
        }
    }
    std::cout << "\n"<<sum;

    #pragma endregionПп
}
/*
if (size == 0) {
            for (int p = 0; p < 8; p++) {
                for (int j = 0; j < 8; j++) {
                    if (graph[p][j] < min_v && p != j) { min_v = graph[p][j]; min_i = p; min_j = j; }
                    versh[0] = min_i;
                    versh[1] = min_j;
                    size = 2;

                }
            }
        }
*/
