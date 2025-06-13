#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int index);
int* replacement(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int index);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int indx);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int indx);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int indx);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int indx);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	arr = pop_back(arr, n);
	cout << "Pop_back" << endl;
	Print(arr, n);

	arr = pop_front(arr, n);
	cout << "Pop_front" << endl;
	Print(arr, n);

	//insert - добавл€ет значение раздвига€ под него массив
	int index;
	cout << "¬ведите добавл€емое значение и индекс: "; cin >> value >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	//replacement - замен€ет значение по индексу
	cout << "¬ведите замен€емое значение и индекс: "; cin >> value >> index;
	arr = replacement(arr, n, value, index);
	Print(arr, n);

	//erase - удал€ет значение/элемент массива по индексу
	cout << "¬ведите индекс удал€емого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif

	int rows;
	int cols;
	int indx;
	int** arr;
	cout << "Enter rows: "; cin >> rows;
	cout << "Enter cols: "; cin >> cols;

	arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	
	Print(arr, rows, cols);

	cout << "push_row_front: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Enter insert_row index: "; cin >> indx;
	arr = insert_row(arr, rows, cols, indx);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	cout << "pop_row_back: " << endl;
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	cout << "pop_row_front: " << endl;
	Print(arr, rows, cols);

	cout << "enter erase_row index: " << endl; cin >> indx;
	arr = erase_row(arr, rows, cols, indx);
	Print(arr, rows, cols);

	cout << "push_col_back: " << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "push_col_front: " << endl;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][0] = rand() % 10;
	Print(arr, rows, cols);

	cout << "Enter insert_col index: "; cin >> indx;
	insert_col(arr, rows, cols, indx);
	for (int i = 0; i < rows; i++)arr[i][indx] = rand() % 10000;
	Print(arr, rows, cols);

	cout << "pop_col_back: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "pop_col_front: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "enter erase_col index: " << endl; cin >> indx;
	erase_col(arr, rows, cols, indx);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	Clear(arr);
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
void Clear(int** arr)
{
	delete[]arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int indx)
{
	int** buffer = new int* [rows + 1];
	buffer[indx] = new int[cols] {};
	for (int i = 0; i < rows; i++)i < indx ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i];
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int indx)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) i < indx ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
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
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int ii = 0; ii < cols; ii++)buffer[ii + 1] = arr[i][ii];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, int indx)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int ii = 0; ii < cols; ii++)ii < indx ? buffer[ii] = arr[i][ii] : buffer[ii + 1] = arr[i][ii];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int ii = 0; ii < cols - 1; ii++)buffer[ii] = arr[i][ii];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int ii = 0; ii < cols - 1; ii++)buffer[ii] = arr[i][ii + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int indx)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int ii = 0; ii < cols - 1; ii++)i < indx ? buffer[ii] = arr[i][ii] : buffer[ii] = arr[i][ii + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void Print(int arr[], const int n)
{
	//cout << arr << endl;
	//cout << *arr << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << "\t";//subscript operator
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
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
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	buffer[index] = value;
	delete[] arr;
	return buffer;
}
int* replacement(int arr[], int& n, int value, int index)
{
	arr[index] = value;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}