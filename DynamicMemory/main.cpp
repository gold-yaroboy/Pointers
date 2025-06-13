#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DATATYPE double
typedef int DataType;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* push_back(T arr[], int& n, const T value);
template<typename T> T* push_front(T arr[], int& n, const T value);

template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);

template<typename T> T* insert(T arr[], int& n, const T value, const T index);
int* replacement(int arr[], int& n, int value, int index);
int* erase(int arr[], int& n, int index);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int indx);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int indx);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);
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
	DATATYPE* arr = new DATATYPE[n];

	FillRand(arr, n);
	Print(arr, n);

	DATATYPE value;
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
	Print(arr = insert(arr, n, value, index), n);

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

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int indx;
	int** arr;
	cout << "Enter rows: "; cin >> rows;
	cout << "Enter cols: "; cin >> cols;

	arr = Allocate<int>(rows, cols);
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
#endif
}

template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}

template<typename T>void Clear(T** arr)
{
	delete[]arr;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>T** insert_row(T** arr, int& rows, const int cols, int indx)
{
	T** buffer = new T* [rows + 1];
	buffer[indx] = new T[cols] {};
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

template<typename T>T** erase_row(T** arr, int& rows, const int cols, int indx)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++) i < indx ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}


template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
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

void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < n; i++)
	{
		arr[i] = double (rand() % (maxRand - minRand) + minRand) / 100;
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

template<typename T> void Print(T arr[], const int n)
{
	//cout << arr << endl;
	//cout << *arr << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << "\t";//subscript operator
	cout << endl;
}

template<typename T> void Print(T** arr, const int rows, const int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl;
}

template<typename T> T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
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

template<typename T> T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const T value, const T index)
{
	T* buffer = new T[++n]{};
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