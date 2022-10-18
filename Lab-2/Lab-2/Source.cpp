#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void FillArr(int*, int);
int MinNum(int*, int);
int MaxNum(int*, int);
int ModeNum(int*, int);
void Histogram(int*, int);
void BubbleSort(int*, int);
void BubbleSort(int*, int, int, int);
int LinealSearch(int*, int, int);
int BinarySearch(int*, int, int,int );
void InsertSort(int*, int);
void AssortmentSort(int*, int);
void InsertSort(int*, int, int, int);
void AssortmentSort(int*, int, int, int);
void BubbleSortDes(int*, int);
void InsertSortDes(int*, int);
void AssortmentSortDes(int*, int);
void BubbleSortDes(int*, int, int, int);
void InsertSortDes(int*, int, int, int);
void AssortmentSortDes(int*, int, int, int);
void Sorting(int*, int);

void main()
{
	int size, key;
	cout << "Enter the array size:\t";
	cin >> size;
	cout << endl;
	int* arr = new int[size];

	FillArr(arr,size);
	cout <<"Minimum number of array: " << MinNum(arr, size) << endl;
	cout << "Maximum number of array: " << MaxNum(arr, size) << endl;
	cout << "Mode of array: " << ModeNum(arr, size) << endl;
	cout << "Histogram: " << endl;
	Histogram(arr, size);
	cout << "Enter the key: ";
	cin >> key;
	cout << '\n';
	cout << "Lineal search (index): " << LinealSearch(arr, size, key) << endl;

	Sorting(arr, size);
	cout << '\n';
	
	int choice;
	cout << "Sort by: 1)growth\n 2)descending\n";
	cin >> choice;
	
	cout << "\nBinary search (index): " << BinarySearch(arr, size, key, choice) << endl;



	delete[] arr;
}

int MinNum(int* arr, int size)
{
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp > arr[i])temp = arr[i];
	}
	return temp;
}

int MaxNum(int* arr, int size)
{
	int temp = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < arr[i])temp = arr[i];
	}
	return temp;
}

int ModeNum(int* arr, int size)
{
	int count = 0;
	int tempCount = 0;
	int countM = 0;
	int temp = 0;
		for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
				if (countM < count)
				{
					temp = arr[i];
					countM = count;
				}
				
			}
			
		}
		tempCount = countM;
		count = 0;
	}
		if (tempCount <= 1)
		{
			cout << "The numbers are not repeated" << endl;
			return 0;
		}
		else
		{
			return temp;
		}
		
}

void Histogram(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << '\t';
		for (int j = 1; j <= arr[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void FillArr(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << "\t";
	}
	cout << endl;

}

void BubbleSort(int* arr, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++) 
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void BubbleSort(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;

	int temp;
	for (int i = lower; i < upper; i++)
	{
		for (int j = lower; j < upper - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

int LinealSearch(int* arr, int size, int key)
{
	for (int i = 0; i < size; i++) if (arr[i] == key) return i;
		return -1;
}

int BinarySearch(int* arr, int size, int key,int choice)
{
	int min = 0, max = size;
	int middle;
	
	if (choice == 1)
	{
		InsertSort( arr, size);

		while (1)
		{
			middle = (max + min) / 2;

			if (key < arr[middle])
				max = middle - 1;
			else if (key > arr[middle])
				min = middle + 1;
			else
				return middle;

			if (min > max) return -1;
		}
	}
	else if (choice == 2)
	{
		InsertSortDes(arr, size);

		while (1)
		{

			middle = (max + min) / 2;

			if (key > arr[middle])
				max = middle - 1;
			else if (key < arr[middle])
				min = middle + 1;
			else
				return middle;

			if (min > max) return -1;
		}
	}
}

void InsertSort(int* arr, int size)
{
	int buff = 0;
	for (int i = 0; i < size; i++)
	{
		buff = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] > buff; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = buff;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void InsertSort(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;
	int buff = 0;
	for (int i = lower; i < upper; i++)
	{
		buff = arr[i];
		for (int j = i - 1; j >= lower && arr[j] > buff; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = buff;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void AssortmentSort(int* arr, int size)
{
	int min = 0;
	int buff = 0;

	for (int i = 0; i < size-1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; ++j)
		{
			min = (arr[j] < arr[min]) ? j : min;

		}
		std::swap(arr[i], arr[min]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void AssortmentSort(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;

	int min = 0;
	int buff = 0;

	for (int i = lower; i < upper; i++)
	{
		min = i;
		for (int j = i + 1; j < upper + 1; j++)
		{
			min = (arr[j] < arr[min]) ? j : min;
		}
		std::swap(arr[i], arr[min]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void InsertSortDes(int* arr, int size)
{
	int buff = 0;
	for (int i = 0; i < size; i++)
	{
		buff = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] < buff; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = buff;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void InsertSortDes(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;
	int buff = 0;
	for (int i = lower; i < upper; i++)
	{
		buff = arr[i];
		for (int j = i - 1; j >= lower && arr[j] < buff; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = buff;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void AssortmentSortDes(int* arr, int size)
{
	int max = 0;
	int buff = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		max = i;
		for (int j = i + 1; j < size; ++j)
		{
			max = (arr[j] > arr[max]) ? j : max;

		}
		std::swap(arr[i], arr[max]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void AssortmentSortDes(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;

	int max = 0;
	int buff = 0;

	for (int i = lower; i < upper; i++)
	{
		max = i;
		for (int j = i + 1; j < upper + 1; j++)
		{
			max = (arr[j] > arr[max]) ? j : max;
		}
		std::swap(arr[i], arr[max]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void BubbleSortDes(int* arr, int size)
{	
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void BubbleSortDes(int* arr, int size, int upper, int lower)
{
	if (upper > size) upper = size;
	if (lower < 0) lower = 0;

	int temp;
	for (int i = lower; i < upper; i++)
	{
		for (int j = lower; j < upper - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
}

void Sorting(int* arr,int size)
{
	int choise, upper, lower;
	cout << "Sort by: \n1) descending\n2)growth" << endl;
	cin >> choise;

	if (choise == 1)
	{
		cout << "Sort: \n1)all \n2)part of array\n";
		cin >> choise;
		if (choise == 1)
		{
			cout << "Sort by: \n1) Insert sorting \n2)Assortment sorting \n3)Bubble sorting" << endl;
			cin >> choise;

			if (choise == 1)
				{
					InsertSortDes(arr, size);
				}
			else if(choise == 2)
				{
					AssortmentSortDes(arr, size);
				}
			else if (choise == 3)
				{
					BubbleSortDes(arr, size);
				}
			else
			{
				cout << "Invaild value\n";
			}

		}

		else if (choise == 2)
		{
			cout << "Sort by: \n1) Insert sorting \n2)Assortment sorting \n3)Bubble sorting" << endl;
			cin >> choise;
			cout << "Enter upper bound\n";
			cin >> upper;
			cout << "Enter lower bound\n";
			cin >> lower;

			if (choise == 1)
			{
				InsertSortDes(arr, size, upper, lower);
			}
			else if (choise == 2)
			{
				AssortmentSortDes(arr, size, upper, lower);
			}
			else if (choise == 3)
			{
				BubbleSortDes(arr, size,upper,lower);
			}
			else
			{
				cout << "Invaild value\n";
			}
		}
		else
		{
			cout << "Invaild value\n";
		}
	}
	
	else if (choise == 2)
	{
		cout << "Sort: \n1)all \n2)part of array\n";
		cin >> choise;
		if (choise == 1)
		{
			cout << "Sort by: \n1) Insert sorting \n2)Assortment sorting \n3)Bubble sorting" << endl;
			cin >> choise;
			if (choise == 1)
			{
				InsertSort(arr, size);
			}
			else if (choise == 2)
			{
				AssortmentSort(arr, size);
			}
			else if (choise == 3)
			{
				BubbleSort(arr, size);
			}
			else
			{
				cout << "Invaild value\n";
			}
		}

		else if (choise == 2)
		{
			cout << "Sort by: \n1) Insert sorting \n2)Assortment sorting \n3)Bubble sorting" << endl;
			cin >> choise;
			cout << "Enter upper bound\n";
			cin >> upper;
			cout << "Enter lower bound\n";
			cin >> lower;

			if (choise == 1)
			{
				InsertSort(arr, size, upper, lower);
			}
			else if (choise == 2)
			{
				AssortmentSort(arr, size, upper, lower);
			}
			else if (choise == 3)
			{
				BubbleSort(arr, size, upper, lower);
			}
			else
			{
				cout << "Invaild value\n";
			}
		}
		else
		{
			cout << "Invaild value\n";
		}
	}
	else
	{
	cout << "Invaild value\n";
	}
}
