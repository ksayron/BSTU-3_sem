#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int capacity, amount;
	cout << "вместительность рюкзака: ";
	cin >> capacity;
	cout << "количество предметов: ";
	cin >> amount;


	string* name = new string[amount];
	int* cost = new int[amount];
	int* ves = new int[amount];

	for (int i = 0; i < amount; i++)
	{
		cout << "имя " << i + 1 << " предмета: ";
		cin >> name[i];
		cin.clear();
		cout << "стоимость " << i + 1 << " предмета: ";
		cin >> cost[i];
		cout << "вес " << i + 1 << " предмета: ";
		cin >> ves[i];

	}

	int** matrix = new int* [amount + 1]; 
	for (int i = 0; i < amount + 1; i++)
	{
		matrix[i] = new int[capacity + 1];
	}

	for (int i = 0; i < amount + 1; i++)
	{
		for (int j = 0; j < capacity + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 1; i < amount + 1; i++)
	{
		for (int j = 1; j < capacity + 1; j++)
		{
			if (j < ves[i - 1])
			{
				matrix[i][j] = matrix[i - 1][j]; 
			}
			else
			{
				matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - ves[i - 1]] + cost[i - 1]);
			}
		}
	}

	cout << "\nитоговая матрица: ";
	for (int i = 0; i < amount + 1; i++)
	{
		for (int j = 0; j < capacity + 1; j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout << "\n";
	}

	cout << "\nмаксимальная ценность рюкзака: " << matrix[amount][capacity] << "\n"
		<< "\nПредметы в рюкзаке: \n";
	int i = amount, j = capacity;
	while (i > 0 && j > 0)
	{
		if (matrix[i][j] != matrix[i - 1][j])
		{
			cout << name[i - 1] << "\n";
			j -= ves[i - 1];
		}
		i--;
	}
	cout << endl;
	for (int i = 0; i < amount + 1; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] name;
	delete[] cost;
	delete[] ves;
}