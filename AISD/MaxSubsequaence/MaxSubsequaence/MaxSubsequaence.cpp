#include <iostream>
#include <cstdlib>
using namespace std;



//7
//5
//7,12
//5,12
//7,12,55
//5,12,55
//7,12,23
//5,12,23
//7,12,23,45
//5,12,23,45
//7,12,55,56
//5,12,55,56
//7,12,23,45,56
//5,12,23,45,56
//7,12,55,56,77
//5,12,55,56,77
//7,12,23,45,56,77
//5, 12, 23, 45, 56, 77
//7, 12, 55, 56, 70
//5, 12, 55, 56, 70
//7, 12, 23, 45, 56, 70
//5, 12, 23, 45, 56, 70
//7, 12, 55, 56, 77,89
//5, 12, 55, 56, 77,89
//7, 12, 23, 45, 56, 77,89
//5, 12, 23, 45, 56, 77,89
//7, 12, 55, 56, 70,89
//5, 12, 55, 56, 70,89
//7, 12, 23, 45, 56, 70,89
//5, 12, 23, 45, 56, 70,89
//7, 12, 55, 56, 77, 89,99
//5, 12, 55, 56, 77, 89,99
//7, 12, 23, 45, 56, 77, 89,99
//5, 12, 23, 45, 56, 77, 89,99
//7, 12, 55, 56, 70, 89,99
//5, 12, 55, 56, 70, 89
//7, 12, 23, 45, 56, 70, 89,99
//5, 12, 23, 45, 56, 70, 89,99
//
//7, 12, 23, 45, 56, 77, 89, 99
//5, 12, 23, 45, 56, 77, 89, 99
//7, 12, 23, 45, 56, 70, 89, 99
//5, 12, 23, 45, 56, 70, 89, 99





void main() {
	setlocale(LC_ALL, "RUS");
	int N;
	cout << "длина: "; cin >> N;
	int* arr = new int[N];
	int* lengthes = new int[N];
	int* path = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cout << "элемент " << i + 1 << ": "; cin >> arr[i];
		lengthes[i] = 1;
		path[i] = -1;
	}
	cout << endl;

	cout << "последовательность: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && lengthes[i] <= lengthes[j]) {
				lengthes[i] = lengthes[j] + 1;
				path[i] = j;
			}
		}
	}

	int max = 0;
	int max_versh = 0;
	for (int i = 0; i < N; i++)
	{
		if (lengthes[i] > max)
		{
			max_versh = i;
			max = lengthes[i];
		}
	}
	cout << "длина макс подпоследовательности: " << max << endl;


	cout << "длины подпоследовательностей от вершин: ";
	for (int i = 0; i < N; i++)
	{
		cout << lengthes[i] << " ";
	}
	cout << endl;

	cout << "путь от вершине к вершине: ";
	for (int i = 0; i < N; i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;


	int out[100];
	for (int i = max; i >= 0; i--)
	{
		out[i] = arr[max_versh];
		max_versh = path[max_versh];
	}

	cout << "Максимальная возрастающая подпоследовательность: ";
	for (int i = 1; i < max + 1; i++)
	{
		cout << out[i] << " ";
	}
	delete[] arr;
	delete[] lengthes;
	delete[] path;
}