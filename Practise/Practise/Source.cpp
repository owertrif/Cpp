#include <iostream>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>
#include "Token.h"
using namespace std;

//Двумерный динамический масив
/*
	Двумерный динамический масив

		void Fillarr(int **arr,int cols,int rows)
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			arr[i][j] = rand() % 50;

	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << arr[i][j]<<'\t';
		cout << endl;

	}
	cout << endl;
}

int main()
{
	int cols, rows;
	cin >> cols;
	cin >> rows;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	Fillarr(arr, cols, rows);
	
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
*/
//Указатели на функцию
/*
	

		void add(int, int);
void subtract(int, int);
void multiply(int, int);

void main()
{
	int a = 10;
	int b = 5;
	void (*operations[3])(int, int) = { add, subtract, multiply };

	// получаем длину массива
	int length = sizeof(operations) / sizeof(operations[0]);

	for (int i = 0; i < length; i++)
	{
		operations[i](a, b);    // вызов функции по указателю
	}
	
}

void add(int x, int y)
{
	std::cout << "x + y = " << x + y << std::endl;
}
void subtract(int x, int y)
{
	int result = x - y;
	std::cout << "x - y = " << x - y << std::endl;
}
void multiply(int x, int y)
{
	std::cout << "x * y = " << x * y << std::endl;
}
*/
//Указатели на функцию как параметр в функцию
/*
	int add(int, int);
int subtract(int, int);
int operation(int(*)(int, int), int, int);

void main()
{
	int a = 10;
	int b = 5;
	int result;

	result = operation(add, a, b);
	cout << "result:" << result << endl;
	
	result = operation(subtract, a, b);
	cout << "result:" << result << endl;
}

int add(int x, int y)
{
	return x + y;
}
int subtract(int x, int y)
{
	return x - y;
}
int operation(int(*op)(int, int),int x, int y)
{
	return op(x, y);
}
*/
//Указатель как возвращаемое значение
/*
	void Goodmorning();
void Goodevening();
void(*message(int))();

void main()
{
	void(*action)();
	action = message(15);
	action();
}

void(*message(int hour))()
{
	if (hour < 12)
		return Goodmorning;
	else
		return Goodevening;
}

void Goodmorning()
{
	cout << "Good morning !" << endl;
}

void Goodevening()
{
	cout << "Good evening !" << endl;
}
*/
//Перебор вектора в цикле фор 
/*
	for (int i : arr) {
		...
	}
	Каждый круг цикла в число i подставляется елемент масива начиная с первого и заканчивая последним.
*/




Token_stream ts;

double checkFact(int);
long long factorial(int);
double primary();
double expression();
double term();



int main()
{
	cout << "> ";
	try {
		double val = 0;
		while (cin) {
			Token t = ts.get();
			while (t.kind == ';')t = ts.get();
			if (t.kind == 'q')return 0;
			ts.putback(t);
			cout << "= " << expression() << endl;
		}
		return 0;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch (...) {
		cout << "exception\n";
		return 2;
	}
}



double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '!':
		{
			left = factorial(left);
			t = ts.get();
			break;
		}
		case '*':
		{
			left *= primary();
			t = ts.get();
			break;
		}
		case '/':
		{
		double d = primary();
		if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
		break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':    
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return checkFact(d);
	}
	case '8':            
		return checkFact(t.value);  
	default:
		error("primary expected");
	}
}

double checkFact(int val) {
	Token t = ts.get();
	if (t.kind == '!') {
		return factorial(val);
	}
	else {
		ts.putback(t);
		return val;
	}
}

long long factorial(int val) {
	if (val <= 1)return 1;
	else return val * factorial(val - 1);
}