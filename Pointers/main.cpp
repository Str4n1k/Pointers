#include<iostream>
using namespace std;

//#define POINTER_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a;
	std::cout << a << endl; //����� ���������� 'a' �� �����.
	std::cout << &a << endl; //������ ������ ���������� '�'	����� ��� ������.
	std::cout << pa << endl; //����� ������ ��������� 'a' ����������� � ��������� 'pa'
	std::cout << *pa << endl; //������������� ��������� 'pa', � ����� �� ����� �������� �� ������.  
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