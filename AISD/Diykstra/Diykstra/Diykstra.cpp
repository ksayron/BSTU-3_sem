#include <iostream>
#include <queue>

void AddEdge(int graph[10][10], int a, int b, int dist) {
    graph[a - 1][b - 1] = dist;
    graph[b - 1][a - 1] = dist;
}

int main()
{
    int dist_arr[9];
    for (int i = 0; i < 9; i++) {
        dist_arr[i] = 1000;
    }

    int start = 0;
    std::cin >> start;
    if (start < 1 or start>9) return 0;
    start -= 1;
    dist_arr[start] = 0;
    int graph[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            i == j ? graph[i][j] = 0 : graph[i][j] = 1000;
            
        }
    }
    AddEdge(graph, 1, 2, 7);
    AddEdge(graph, 1, 3, 10);
    AddEdge(graph, 2, 6, 9);
    AddEdge(graph, 2, 7, 27);
    AddEdge(graph, 3, 6, 8);
    AddEdge(graph, 3, 5, 31);
    AddEdge(graph, 6, 8, 11);
    AddEdge(graph, 5, 4, 32);
    AddEdge(graph, 7, 9, 15);
    AddEdge(graph, 8, 9, 15);
    AddEdge(graph, 4, 9, 21);
    AddEdge(graph, 4, 8, 17);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    int cur;
    bool visited[100];
    std::queue<int> q;
    q.push(start);
    visited[start] = false;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 9; i++) {
            if(graph[cur][i]<1000){
                if (graph[cur][i] + dist_arr[cur] < dist_arr[i]) dist_arr[i] = graph[cur][i] + dist_arr[cur];
                if (visited[i]) {
                    q.push(i);
                    visited[i] = false;
                }
            }
        }

    }
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << char('A' + i) << ": " << dist_arr[i] << "  ";
    }
}

