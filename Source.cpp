#include <iostream>
#include <windows.h>
#include "Polynomial.h"

using namespace std;

void Info();
void PrintInfo();

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	while (1) {
		cout << endl;
		Info();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Введите степень и коэффициенты первого полинома\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "Введите степень и коэффициенты второго полинома\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial p1(n1, c1), p2(n2, c2);

			PrintInfo();

			cin >> choice;

			if (choice == 1)
				(p1 + p2).PrintCoefficients();
			else
			{
				int x;
				cout << "Введите значение аргумента: \n >";
				cin >> x;

				(p1 + p2).Print(x);
			}

		}
		break;

		case 2:
		{
			cout << "Введите степень и коэффициенты первого полинома\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "Введите степень и коэффициенты второго полинома\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial p1(n1, c1), p2(n2, c2);

			PrintInfo();

			cin >> choice;

			if (choice == 1)
				(p1 - p2).PrintCoefficients();
			else
			{
				int x;
				cout << "Введите значение аргумента: \n >";
				cin >> x;

				(p1 - p2).Print(x);
			}

		}
		break;

		case 3:
		{
			cout << "Введите степень и коэффициенты первого полинома\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "Введите степень и коэффициенты второго полинома\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial p1(n1, c1), p2(n2, c2);

			PrintInfo();

			cin >> choice;

			if (choice == 1)
				(p1 * p2).PrintCoefficients();
			else
			{
				int x;
				cout << "Введите значение аргумента: \n >";
				cin >> x;

				(p1 * p2).Print(x);
			}

		}
		break;

		case 4:
		{
			cout << "Введите степень и коэффициенты полинома\n";

			int n;
			int* c;

			cin >> n;
			c = new int[n];
			for (int i = 0; i < n + 1; i++)
				cin >> c[i];

			Polynomial p1(n, c);

			int x, i;
			cout << "Введите значение аргумента: \n >";
			cin >> x;

			cout << "Введите номер члена: \n >";
			cin >> i;
			if (i < p1.getDegree() + 1 && i >= 0)
				cout << p1.FindTerm(i, x) << endl;
			else
				cout << "Такого члена не существует!\n";			
		}
		break;

		case 5: 
			system("cls");
			break;

		default:
			return 0;
		}
	
	}
	

	//int* c1 = new int[4]{ 1,2,3,4 };

	//Polynomial p1(2,c), p2(3,c);

	//p1.Print(1);
	//p1.PrintCoefficients();
	//cout << endl;

	//p2.Print(1);
	//p2.PrintCoefficients();
	//cout << endl;

	//cout << p2.FindTerm(3, 1) << endl;
	//cout << endl;

	//(p1 + p2).Print(1);
	//(p1 + p2).PrintCoefficients();
	//(p1 - p2).Print(1);
	//(p2 - p1).Print(1);
	//cout << endl;

	//Polynomial p3 = p1 * p2;
	//p3.PrintCoefficients();
	//p3.Print(1);

	return 0;
}

void Info() 
{
	cout << "1. Сложить полиномы\n" <<
		"2. Вычесть полиномы\n" <<
		"3. Перемножить полиномы\n" << 
		"4. Вычисление значения многочлена для заданного аргумента\n" <<
		"5. Очистить экран \n>";
}

void PrintInfo() 
{
	cout << "Выберите вывод:\n" <<
		"1. Коэффициенты полинома\n" <<
		"2. Конкретные значения полинома с аргументом х\n >";
}
