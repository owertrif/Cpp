#include <iostream>
#include <time.h>
#include <string>
#include <cmath>

using namespace std;

int DigitCount(int);
void DigitArr(int, int, int*);
void DigitArr(int, int*);
int Average(int*, int);
float Average(int*, float);
int Average(int*, int, int);
float GAverage(int*, int);
long int Factorial(int);
int Summ(int*, int);


 void main()
{
	int num;
	int corr;
	
	cout << "Enter the number:" << endl;
	cin >> num;
	cout << "Enter the corrective:" << endl;
	cin >> corr;
	
	int* digitArr = new int[DigitCount(num)];
	cout << "First task:" << endl;
	cout << DigitCount(num) << endl;
	cout << "Second task:" << endl;
	DigitArr(num, digitArr);
	cout << "Third task:" << endl;
	cout << Average(digitArr, num) << endl;
	cout << "Third task(float):" << endl;
	cout << Average(digitArr, float(num)) << endl;
	cout << "Third task(N+m):" << endl;
	DigitArr(num,corr, digitArr);
	cout << Average(digitArr,num,corr) << endl;
	cout << "Forth task:" << endl;
	DigitArr(num, digitArr);
	cout << endl << GAverage(digitArr, num) << endl;
	cout << "Fifth task:" << endl;
	cout << Factorial(num) << endl;
	cout << "Sixth task:" << endl;
	cout <<"Summ:\t" << Summ(digitArr, num) << endl;
	
	delete[] digitArr;
}

 int DigitCount(int num)
 {
	 int count = 1;
	 do
	 {
		 num /= 10;
		 count++;

	 } while (num / 10 != 0);

	 return count;
 }
 
 void DigitArr(int n, int* digitArr)
 {
	
		 int i = DigitCount(n) - 1;


		 while (i >= 0)
		 {
			 int f = (n / pow(10, i + 1));
			 digitArr[i] = n / pow(10, i) - f * 10;
			 i--;
		 }

		 for (i = DigitCount(n) - 1; i >= 0; i--)
		 {
			 cout << digitArr[i] << '\t';
		 }
	 
 }

 void DigitArr(int n,int m, int* digitArr)
 {
	 int temp = m + n;
	 int i = DigitCount(temp) - 1;


	 while (i >= 0)
	 {
		 int f = (temp / pow(10, i + 1));
		 digitArr[i] = temp / pow(10, i) - f * 10;
		 i--;
	 }

 }

 int Average(int* arr,int n)
 {
	 int summ = 0;
	 int i = DigitCount(n)-1;
	 while (i >= 0)
	 {
		 summ += arr[i];
		 i--;
	 }
	 return summ/DigitCount(n);
 }
 float Average(int* arr, float n)
 {
	 float summ = 0;
	 int i = DigitCount(n) - 1;
	 while (i >= 0)
	 {
		 summ += arr[i];
		 i--;
	 }
	 return summ / DigitCount(n);
 }

 int Average(int* arr, int n,int m)
 {
	 float summ = 0;
	 int i = DigitCount(n) - 1;
	 while (i >= 0)
	 {
		 summ += arr[i];
		 i--;
	 }
	 return summ / DigitCount(n);
 }

 float GAverage(int* arr, int n)
 {
	 int product = arr[0];
	 int i = DigitCount(n) - 1;
	 for (;i >= 1;i--) product *= arr[i];
	 float p = 1 / float(DigitCount(n));
	 return pow(product,p);
 }
 
 long int Factorial(int num)
 {
	long int fnum = 1;
	 do
	 {
		 fnum *= num;
		 num--;
	 } while (num > 1);
	 return fnum;
 }

 int Summ(int* arr, int n)
 {
	 int summ = 0;
	 int choice;
	 int i = DigitCount(n) - 1;
	 while (1)
	 {
		 cout <<"1)Summ of even digits\n 2)Summ of odd digits\n";
		 cin >> choice;
		 if (choice == 1)
			 while (i >= 0)
			 {
				 if (arr[i] % 2 == 0) summ += arr[i];
				 i--;
			 }
		 else if (choice == 2)
		 {
			 while (i >= 0)
			 {
				 if (arr[i] % 2 != 0) summ += arr[i];
				 i--;
			 }
		 }
		 return summ;
	 }
 }

 