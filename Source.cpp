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
			cout << "������� ������� � ������������ ������� ��������\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "������� ������� � ������������ ������� ��������\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial *p1 = new Polynomial(n1, c1),
				*p2 =  new Polynomial(n2, c2);

			Polynomial* c = dynamic_cast<Polynomial*>(p1->Add(p2));

			PrintInfo();
			cin >> choice;

			if (choice == 1)
				c->PrintCoefficients();
			else
			{
				int x;
				cout << "������� �������� ���������: \n >";
				cin >> x;

				c->Print(x);
			}

		}
		break;

		case 2:
		{
			cout << "������� ������� � ������������ ������� ��������\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "������� ������� � ������������ ������� ��������\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial* p1 = new Polynomial(n1, c1),
				* p2 = new Polynomial(n2, c2);

			Polynomial* c = dynamic_cast<Polynomial*>(p1->Subtract(p2));

			PrintInfo();
			cin >> choice;

			if (choice == 1)
				c->PrintCoefficients();
			else
			{
				int x;
				cout << "������� �������� ���������: \n >";
				cin >> x;

				c->Print(x);
			}

		}
		break;

		case 3:
		{
			cout << "������� ������� � ������������ ������� ��������\n";

			int n1, n2;
			int* c1, * c2;

			cin >> n1;
			c1 = new int[n1];
			for (int i = 0; i < n1 + 1; i++)
				cin >> c1[i];

			cout << "������� ������� � ������������ ������� ��������\n";
			cin >> n2;
			c2 = new int[n2];
			for (int i = 0; i < n2 + 1; i++)
				cin >> c2[i];

			Polynomial* p1 = new Polynomial(n1, c1),
				* p2 = new Polynomial(n2, c2);

			Polynomial* c = dynamic_cast<Polynomial*>(p1->Multiply(p2));

			PrintInfo();

			cin >> choice;

			if (choice == 1)
				c->PrintCoefficients();
			else
			{
				int x;
				cout << "������� �������� ���������: \n >";
				cin >> x;

				c->Print(x);
			}

		}
		break;

		case 4:
		{
			cout << "������� ������� � ������������ ��������\n";

			int n;
			int* c;

			cin >> n;
			c = new int[n];
			for (int i = 0; i < n + 1; i++)
				cin >> c[i];

			Polynomial p1(n, c);

			int x, i;
			cout << "������� �������� ���������: \n >";
			cin >> x;

			cout << "������� ����� �����: \n >";
			cin >> i;
			if (i < p1.getDegree() + 1 && i >= 0)
				cout << p1.FindTerm(i, x) << endl;
			else
				cout << "������ ����� �� ����������!\n";			
		}
		break;

		case 5: 
			system("cls");
			break;

		default:
			return 0;
		}
	
	}

	return 0;
}

void Info() 
{
	cout << "1. ������� ��������\n" <<
		"2. ������� ��������\n" <<
		"3. ����������� ��������\n" << 
		"4. ���������� �������� ���������� ��� ��������� ���������\n" <<
		"5. �������� ����� \n>";
}

void PrintInfo() 
{
	cout << "�������� �����:\n" <<
		"1. ������������ ��������\n" <<
		"2. ���������� �������� �������� � ���������� �\n >";
}
