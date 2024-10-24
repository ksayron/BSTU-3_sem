// DFS_BFS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <stack>
#include <list>

bool AddEdge(bool graph[10][10], int a, int b) {
    graph[a-1][b-1] = true;
    graph[b-1][a-1] = true;
    return graph;
}


int main()
{
    setlocale(LC_ALL, "RUS");
    //Матрица смежности
    bool graph[10][10];
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            graph[i][j] = false;
        }
    }
    int verts = 10, edges = 10;
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 5);
    AddEdge(graph, 7, 2);
    AddEdge(graph, 8, 2);
    AddEdge(graph, 5, 6);
    AddEdge(graph, 4, 6);
    AddEdge(graph, 4, 9);
    AddEdge(graph, 7, 8);
    AddEdge(graph, 8, 3);
    AddEdge(graph, 6, 9);
    AddEdge(graph, 10, 9);
    

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (graph[i][j]) std::cout << 1 << "\t";
            else std::cout << 0 << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    //BFS
    std::cout << "AdjMatrix BFS: ";
    int cur;
    bool visited[100];
    std::queue<int> q;
    q.push(0);
    visited[0] = false;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        std::cout  << cur + 1<<' ';
        
        for (int i = 0; i < 10; i++) {
            if (graph[cur][i]) {
                if (visited[i]) {
                    q.push(i);
                    visited[i] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
    //DFS
    std::cout << "AdjMatrix DFS: ";
    bool visited2[100];
    std::stack<int> s;
    s.push(0);
    visited2[0] = false;

    while (!s.empty()) {
        cur = s.top();
        s.pop();
        std::cout  << cur + 1<<' ';

        for (int i = 0; i < 10; i++) {
            if (graph[cur][i]) {
                if (visited2[i]) {
                    s.push(i);
                    visited2[i] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
    //Список ребер
    int edgeList[11][2] = {
    {1,2},
    {1,5},
    {2,7},
    {4,6},
    {2,8},
    {7,8},
    {3,8},
    {5,6},
    {4,9},
    {6,9},
    {10,9}
    };
    std::cout << "EdgeList BFS: ";
    bool visitedEL[100];
    std::queue<int> q2;
    q2.push(0);
    visitedEL[0] = false;

    while (!q2.empty()) {
        cur = q2.front();
        q2.pop();
        std::cout  << cur + 1<<' ';
        
        for (int i = 0; i < 11; i++) {
            if (edgeList[i][0]==cur+1) {
                if (visitedEL[edgeList[i][1] - 1]) {
                    q2.push(edgeList[i][1] - 1);
                    visitedEL[edgeList[i][1] - 1] = false;
                }
            }
            if (edgeList[i][1] == cur + 1 ) {
                if (visitedEL[edgeList[i][0] - 1]) {
                    q2.push(edgeList[i][0] - 1);
                    visitedEL[edgeList[i][0] - 1] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
    std::cout << "EdgeList DFS: ";
    bool visitedEL2[100];
    std::stack<int> s2;
    s2.push(0);
    visitedEL2[0] = false;

    while (!s2.empty()) {
        cur = s2.top();
        s2.pop();
        std::cout  << cur + 1<<' ';

        for (int i = 0; i < 11; i++) {
            if (edgeList[i][0] == cur + 1) {
                if (visitedEL2[edgeList[i][1] - 1]) {
                    s2.push(edgeList[i][1] - 1);
                    visitedEL2[edgeList[i][1] - 1] = false;
                }
            }
            if (edgeList[i][1] == cur + 1) {
                if (visitedEL2[edgeList[i][0] - 1]) {
                    s2.push(edgeList[i][0] - 1);
                    visitedEL2[edgeList[i][0] - 1] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;

    int AdjList[11][3] = {
    {0,0,0},
    {2,5,0},
    {1,7,8},
    {8,0,0},
    {9,6,0},
    {1,6,0},
    {4,5,9},
    {2,8,0},
    {2,3,7},
    {4,6,10},
    {9,0,0}
    };
    std::cout << "AdjList BFS: ";
    bool visitedAL[100];
    std::queue<int> q3;
    q3.push(1);
    visitedAL[0] = false;
    visitedAL[1] = false;

    while (!q3.empty()) {
        cur = q3.front();
        q3.pop();
        std::cout << cur  << ' ';

        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < 3;i++) {
                if (visitedAL[AdjList[cur][i]]) {
                    q3.push(AdjList[cur][i]);
                    visitedAL[AdjList[cur][i]] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
    std::cout << "AdjList DFS: ";
    bool visitedAL2[100];
    std::stack<int> s3;
    s3.push(1);
    visitedAL2[0] = false;
    visitedAL2[1] = false;

    while (!s3.empty()) {
        cur = s3.top();
        s3.pop();
        std::cout << cur  << ' ';

        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < 3; i++) {
                if (visitedAL2[AdjList[cur][i]]) {
                    s3.push(AdjList[cur][i]);
                    visitedAL2[AdjList[cur][i]] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
}

