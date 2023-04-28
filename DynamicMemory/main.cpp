#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	//1) Создайём буферный массив нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2) Копируем все значения из исходного массива в буферный
	for (int i = 0;i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	//4) Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	buffer = nullptr; //NULL-Pointer или указатель на 0
	//5) И только после этого в массив 'arr' можно добавить значение
	arr[n] = value;
	//6) После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	//7) Mission comlete
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}