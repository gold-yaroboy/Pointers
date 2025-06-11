#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);


//#define dynamic_memory_1
#define dynamic_memory_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef dynamic_memory_1
	int n;
	cout << "go size array: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "go push_back value: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "go push_front value: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
#endif

#ifdef dynamic_memory_2

	int rows;
	int cols;
	cout << "Введите кол - во строк : "; cin >> rows;
	cout << "Введите кол - во элементов строки : "; cin >> cols;
	
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);	
	Print(arr, rows, cols);
	
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

#endif
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; //Через арифметику указателей и оператор разыменования
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
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
		cout << arr[i] << "\t";	   //через оператор индексирования (квадратные скобки)
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, const int value)
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols]{};
	rows++;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;		
	}
	cols++;
}

int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}