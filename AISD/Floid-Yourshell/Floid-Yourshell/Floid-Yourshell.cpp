#include <iostream>
#include <queue>

void AddEdge(int graph[10][10], int a, int b, int dist) {
    graph[a - 1][b - 1] = dist;
}


int main()
{

    int graph[6][6] = {
        {0  ,28       ,21       ,59       ,12 ,27       },
        {7  ,0        ,24       ,INT32_MAX,21 ,9        },
        {9  ,32       ,0        ,13       ,11 ,INT32_MAX},
        {8  ,INT32_MAX,5        ,0        ,16 ,INT32_MAX},
        {14 ,13       ,15       ,10       ,0  ,22       },
        {15 ,18       ,INT32_MAX,INT32_MAX,6  ,0        }
    };
    int s_graph[6][6] = {
        {0,2,3,4,5,6 },
        {1,0,3,4,5,6 },
        {1,2,0,4,5,6 },
        {1,2,3,0,5,6 },
        {1,2,3,4,0,6 },
        {1,2,3,4,5,0 },
    };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(graph[i][j]== INT32_MAX) std::cout << "inf" << "\t";
            else std::cout << graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << s_graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    for (int m = 0; m < 6; m++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (graph[i][m] + graph[m][j] < graph[i][j] && (i != j && j != m && i != m)) {
                    graph[i][j] = graph[i][m] + graph[m][j];
                    s_graph[i][j] = m+1;
                }
            }
        }
    }

    std::cout << std::endl << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << s_graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

