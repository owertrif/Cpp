#include <iostream>
#include <time.h>
#include <Windows.h>


void FillandShow(int** arr, int rows, int cols)
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = -50 + rand() % 100;
		}
	}
	
	for (int i = 0; i < rows; i++)
	{
		std::cout << '|';
		for (int j = 0; j < cols; j++)
		{
			std::cout<<arr[i][j]<<'\t';
		}
		std::cout<<'|' << std::endl;
	}
	
}

void FillandShow_String(char* stroka,int size)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	
	srand(time(NULL));
	
	while (1)
	{
		std::cout << "Яким способом заповнити строку: \n1)Цифрами \n2)Літерами (Латиниця і Кацапською) \n3)Літерами і цифрами\n";
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1)
		{

			for (int i = 0; i < size; i++)
			{
				int rnd = (rand() % 10) + 48;
				stroka[i] = char(rnd);
			}
			break;
		}

		else if (choice == 2)
		{
			for (int i = 0; i < size; i++)
			{
				int temp = (rand() % 2) + 1;
				if (temp == 1)
				{
					int temp2 = (rand() % 2) + 1;
					if (temp2 == 1)
					{
						
						
							int rnd = (rand() % 26) + 65;
							stroka[i] = char(rnd);
						
					}
					else if (temp2 == 2)
					{
						
						
							int rnd = (rand() % 26) + 97;
							stroka[i] = char(rnd);
						
					}
				}
				else if (temp == 2)
				{
				
					
						int rnd = (rand() % 65) + 191;
						stroka[i] = char(rnd);
					
				}
			}
			break;
		}

		else if (choice == 3)
		{

			for (int i = 0; i < size; i++)
			{
				int temp = (rand() % 3) + 1;
				if (temp == 1)
				{
					int temp2 = (rand() % 2) + 1;
					if (temp2 == 1)
					{
						
							int rnd = (rand() % 26) + 65;
							stroka[i] = char(rnd);
						
					}
					else if (temp2 == 2)
					{
						
							int rnd = (rand() % 26) + 97;
							stroka[i] = char(rnd);
						
					}
				}
				else if (temp == 2)
				{
					
						int rnd = (rand() % 65) + 191;
						stroka[i] = char(rnd);
					
				}
				else if (temp == 3)
				{

					
						int rnd = (rand() % 10) + 48;
						stroka[i] = char(rnd);
					
				}
			}
			break;
		}
		
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << stroka[i];
	}
	std::cout << std::endl;
}

void CheckStr(char* str,int size, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cntr = 0;

	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (str2[i] == str[j])
			{
				cntr++;
				break;
			}
		}
	}
	if (cntr == str2.length()) std::cout << "Stroka має всі символи з Stroka2" << std::endl;
	else std::cout << "Stroka має не всі символи з Stroka2" << std::endl;

}
void CheckStr(std::string str, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cntr = 0;

	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j <str.length(); j++)
		{
			if (str2[i] == str[j])
			{
				cntr++;
				break;
			}
		}
	}
	if (cntr == str2.length()) std::cout << "Stroka має всі символи з Stroka2" << std::endl;
	else std::cout << "Stroka має не всі символи з Stroka2" << std::endl;

}

void CorrandShow(char* str, int size, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (str2[i] == str[j])
			{
				str[j] = '#';
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}
void CorrandShow(std::string str, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < str2.length(); i++)
	{
		for (int j = 0; j < str.length(); j++)
		{
			if (str2[i] == str[j])
			{
				str[j] = '#';
			}
		}
	}

	std::cout <<str<< std::endl;
}

void FindWord(std::string str, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int counter = 0;
	std::string temp = str;
	int pos ;
	while (1)
	{
		pos = temp.find(str2);
		if (pos != -1)
		{
			counter++;
			for (int i = pos; i < str2.length()+pos; i++)
			{
				temp[i] = '*';
			}
		}
		else if (pos == -1 && counter != 0)
		{
			std::cout << "Stroka2 повторюєтся цілком в Stroka " << counter << " разів\n";
			break;
		}
		else
		{
			std::cout << "Stroka не повторюєтся в Stroka2\n";
			break;
		}
	}
}
void FindWord(char* str,int size, std::string str2)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		char temp = str[i];
		if (str[i] == str2[0])
		{
			for (int j = 0;j<str2.length();j++)
			{
				if (j == str2.length() - 1)
				{
					counter++;
				}
				else if (str[i + j] != str2[j])
				{
					break;
				}
				
			}
		}
	}

	if (counter != 0) std::cout<< "Stroka2 повторюєтся цілком в Stroka " << counter << " разів\n";
	else std::cout << "Stroka не повторюєтся в Stroka2\n";
	
}

int ArrMax1(int** arr, int rows, int cols)
{
	int maxv = arr[0][cols-1];
	int temp,border = 0;

	for(int i = cols - 1; i >= 0; i--)
	{
		for (int j = rows - 1; j >= border; j--)
		{
			temp = arr[j][i];
			maxv = temp > maxv ? temp : maxv;
		}
		border++;
	}

	return maxv;
}
int ArrMax2(int** arr, int rows, int cols)
{
	int maxv = arr[0][0];
	int temp,midr = (rows -1)/2,midc = (cols-1)/2, border = 0;

	//if (rows % 2 != 0) midr++;
	//if (cols % 2 != 0) midc++;
	
	for (int i = 0; i < rows; i++)
	{
		if (i <= midr)
		{
			for (int j = 0; j <= border; j++)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
			if(i<midc)border++;
		}
		else if (i > midr)
		{
			for (int j = border-1 ; j >= 0; j--)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
			border--;
		}
	}

	return maxv;
}
int ArrMax3(int** arr, int rows, int cols)
{
	int maxv = arr[0][cols - 1];
	int temp, midr = (rows - 1) / 2, midc = (cols - 1) / 2, finish = cols - 1, start = 0;

	if (rows % 2 != 0) midr++;
	if (cols % 2 != 0) midc++;

	for (int i = 0; i < rows; i++)
	{
		if (i <= midr && rows % 2 == 0)
		{
			for (int j = start; j <= finish; j++)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
			if (start < finish-1)
			{
				start++;
				finish--;
			}
		}
		else if (i <= midr && rows % 2 != 0)
		{
			for (int j = start; j <= finish; j++)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
			if (start < finish)
			{
				start++;
				finish--;
			}
		}
		if (i > midr && rows % 2 == 0)
		{
			for (int j = start; j <= finish; j++)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
			if (start < finish)
			{
				start--;
				finish++;
			}
		}
		else if (i > midr && rows % 2 != 0)
		{
			if (start <= finish)
			{
				start--;
				finish++;
			}
			for (int j = start; j <= finish; j++)
			{
				temp = arr[i][j];
				maxv = temp > maxv ? temp : maxv;
			}
		}
	}

	return maxv;
}

void main()
{
	int choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1)
	{
		std::cout << " 1)Випадкова строка\n 2)Строка заповнена тобою\n Введіть вибір:\t";
		std::cin >> choice;
		if (choice == 1)
		{
			int size;
			std::cout << "Введіть розмір строки:\t";
			std::cin >> size;

			char* Stroka = new char[size];


			FillandShow_String(Stroka, size);

			std::string Stroka2;
			std::cout << "Введіть свою строку:\t" << std::endl;
			std::cin >> Stroka2;
			int len = Stroka2.length();
			std::cout << "Довжина Stroka2:\t" << len << std::endl;

			CheckStr(Stroka, size, Stroka2);
			FindWord(Stroka,size,Stroka2);
			CorrandShow(Stroka, size, Stroka2);

			delete[] Stroka;
			break;
		}
		else if (choice == 2)
		{
			std::string Stroka;
			std::cout << "Введіть свою строку:\t" << std::endl;
			std::cin >> Stroka;
			int len = Stroka.length();
			std::cout << "Довжина Stroka:\t" << len << std::endl;

			std::string Stroka2;
			std::cout << "Введіть свою строку:\t" << std::endl;
			std::cin >> Stroka2;
			len = Stroka2.length();
			std::cout << "Довжина Stroka2:\t" << len << std::endl;

			CheckStr(Stroka, Stroka2);
			FindWord(Stroka, Stroka2);
			CorrandShow(Stroka, Stroka2);

			break;
		}
	}
	int  rows, cols;

	std::cout << "Введіть кількість рядків:\t" ;
	std::cin >> rows;
	std::cout << "Введіть кількість стовпців:\t" ;
	std::cin >> cols;
	std::cout << std::endl;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillandShow(arr, rows, cols);
	std::cout << "Максимальне число з діапазону 4: " << ArrMax1(arr, rows, cols) << std::endl;
	std::cout << "Максимальне число з діапазону 7: " << ArrMax2(arr, rows, cols) << std::endl;
	std::cout << "Максимальне число з діапазону 5: " << ArrMax3(arr, rows, cols) << std::endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}