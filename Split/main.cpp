#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "go size array: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	delete[]arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{//�� 0 �� 100 ����
		*(arr + i) = rand() % 100; //����� ���������� ���������� � �������� �������������
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";	   //����� �������� �������������� (���������� ������)
	}
}