#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <ctime>

using namespace std;

#define MAX_DIST 100

typedef vector<vector<int>> Matrix;
typedef vector<vector<double>> MatrixP;
typedef vector<int> Path;

struct Way
{
    Path way;
    size_t dist;
};


string to_string( Way way)
{
    string text = "Путь: ";

    for (auto i : way.way)
    {
        text += std::to_string(i) + " -> ";
    }
    

    text += "\nДлина пути : " + std::to_string(way.dist) + "\n";

    return text;
}


void fillAll(vector<bool>& path, size_t N)
{
    for (size_t i = 0; i < N; i++)
    {
        path.push_back(true);
    }
}

void fillPropabs(
    Matrix& graph,
    MatrixP& pheramons,
    vector<double>& propabs,
    vector<bool> notv,
    double alpha,
    double beta,
    size_t current)
{
    double sum = 0.0;
    propabs.resize(graph.size());
    for (size_t i = 0; i < notv.size(); i++)
    {
        if (notv[i] && i != current)
        {
            sum += pow(2.0 / (double)graph[current][i], alpha) * pow((double)pheramons[current][i], beta);
        }
    }

    for (size_t i = 0; i < propabs.size(); i++)
    {
        if (notv[i])
        {
            propabs[i] = 100.0 * pow(2.0 / (double)graph[current][i], beta) * pow((double)pheramons[current][i], alpha) / sum;
        }
        else
        {
            propabs[i] = 0;
        }
    }
}

size_t makeChoise(vector<double> propabs)
{
    srand(time(NULL));
    size_t answer = 0;
    size_t random = rand() % 100 + 1;
    double sum = 0.0;

    for (size_t i = 0; i < propabs.size(); i++)
    {
        if (propabs[i] == 0) continue;

        sum += propabs[i];
        if (sum >= random)
        {
            answer = i;
            break;
        }
    }

    return answer;
}
void fillPheramons(MatrixP& pheromones,vector<Way> ways)
{
    for (auto& el : pheromones)
    {
        for (auto& i : el) {
            if(i>0.01)i -= 0.01;
        }
    }
    for (auto& way : ways)
    {
        for (int i=0;i<way.way.size()-1;i++)
        {
            double change = double(4.0 / way.dist);
            pheromones[way.way[i]][way.way[i + 1]]+=change;
        }
    }
}

void main()
{
    setlocale(LC_ALL, "Ru");
    int nIters = 100;
    double alpha;
    double beta;
    double pher;
    int N;
    cout << "Введите кол-во городов: ";
    cin >> N;
    cout << "Введите кол-во  итераций: ";
    cin >> nIters;
    cout << "Введите альфа: ";
    cin >> alpha;
    cout << "Введите бета: ";
    cin >> beta;
    cout << "Введите начальное значение феромонов(<1.0): ";
    cin >> pher;


    Matrix cities;
    cities.resize(N);
    srand(time(NULL));

    for (auto& i : cities)
    {
        i.resize(N);
    }

    for (size_t i = 0; i < N; i++)
    {
        cities[i][i] = 0;

        for (size_t j = i + 1; j < N; j++)
        {
            cities[i][j] = cities[j][i] = rand() % MAX_DIST + 1;
        }
    }

    for (auto i : cities)
    {
        for (auto el : i)
        {
            cout << el << "\t";
        }
        cout << endl;
    }

    MatrixP pheromons;
    pheromons.resize(N);
    for (auto& i : pheromons)
    {
        i.resize(N);
    }
    for (size_t i = 0; i < N; i++)
    {
        pheromons[i][i] = 0;

        for (size_t j = i + 1; j < N; j++)
        {
            pheromons[i][j] = pheromons[j][i] = pher;
        }
    }
    
    Way way;
    way.dist = 0;
    Way best;
    vector<Way> ways;
    best.dist = INT_MAX;

    vector<bool> notv;
    vector<double> propabs;

    size_t current =0 ;
    size_t to;
    size_t n = 0;

    fillAll(notv, cities.size());

    way.way.push_back(current);

    while (n < nIters)
    {
        for (int i = 1; i < N;i++) {
           

            while(find(notv.begin(), notv.end(), true) != notv.end())
            {
                notv[current] = false;
                propabs.clear();
                fillPropabs(cities, pheromons, propabs, notv, alpha, beta, current);
                to = makeChoise(propabs);
                way.dist += cities[current][to];
                current = to;
                way.way.push_back(current);
                
            }
            if (way.dist < best.dist)
            {
                best = way;
            }
            ways.push_back(way);
            way.way.clear();
            way.dist = 0;
            current = 0;

            way.way.push_back(current);
            notv.clear();
            fillAll(notv, cities.size());
            
        }
        fillPheramons(pheromons,ways);
        ways.clear();
        n++;
    }

    cout << to_string(best);
}



