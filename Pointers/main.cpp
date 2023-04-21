#include<iostream>
using namespace std;

//#define POINTER_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a;
	std::cout << a << endl; //вывод переменной 'a' на экран.
	std::cout << &a << endl; //взятие адреса переменной 'а'	прямо при выводе.
	std::cout << pa << endl; //вывод адреса перемнной 'a' хранящегося в указателе 'pa'
	std::cout << *pa << endl; //Разыменование указателя 'pa', и вывод на экран значения по адресу.  
#endif // POINTER_BASICS
	
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
	
	cout << "HomeWork" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;


}