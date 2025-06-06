#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	
	int a = 2;
	int& ra = a; //Компилятор сам, не явно берет адрес переменно 'а', и записывает его в ссылку 'ra'.
	ra += 3;
	cout << &a << endl;
	cout << &ra << endl;
}