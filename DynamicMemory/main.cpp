#include<iostream>
using namespace std;


int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int**& arr, int& rows, const int cols);
int** insert_row(int**& arr, int& rows, const int cols,int index);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int**& arr, int& rows, const int cols);
int** erase_row(int**& arr, int& rows, const int cols, int index);

void push_cols_back(int** arr, const int rows, int& cols);
void push_cols_front(int** arr, const int rows, int& cols);
void insert_cols(int** arr, const int rows, int& cols, int index);

void pop_cols_back(int** arr, const int rows, int& cols);
void pop_cols_front(int** arr, const int rows, int& cols);
void erase_cols(int** arr, const int rows, int& cols, int index);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите порядковый номер элемента для добавления: "; cin >> index;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols, index;
	std::cout << "Введите количество строк: "; std::cin >> rows;
	std::cout << "Введите количество столбцов: "; std::cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	std::cout << "Добавляет пустую строку в конец  массива: " << std::endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Добавляет пустую строку в начало  массива: " << std::endl;
	push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Введите индекс добавляемой строки: "; std::cin >> index;
	insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	std::cout << "Удаляет последнюю строку  массива: " << std::endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Удаляет нулевую строку  массива: " << std::endl;
	pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Введите индекс удаляемой строки: "; std::cin >> index;
	erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	std::cout << "Добавляет пустой столбец в конец массива: " << std::endl;
	push_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Добавляет пустой столбец в начало массива: " << std::endl;
	push_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Введите индекс добавляемого столбца: "; std::cin >> index;
	insert_cols(arr, rows, cols, index);
	Print(arr, rows, cols);

	std::cout << "Удаляет столбец с конца  массива: " << std::endl;
	pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Удаляет столбец с начала  массива: " << std::endl;
	pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	std::cout << "Введите индекс удаляемой столбца: "; std::cin >> index;
	erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);


	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;

}
int** push_row_front(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[0] = new int[cols] {};
	rows++;
	return arr;
}
int** insert_row(int**& arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int** pop_row_front(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** erase_row(int**& arr, int& rows, const int cols,int index)
{
	int** buffer = new int* [rows--];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

void push_cols_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_cols_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_cols(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_cols_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_cols_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_cols(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}