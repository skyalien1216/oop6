#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial(int degree, int* c)
{
	this->degree = degree;
	coefficients = new int[degree + 1];

	for (int i = 0; i <= degree; i++)
	{
		coefficients[i] = c[i];
	}
}

Polynomial::Polynomial(int degree) 
{
	this->degree = degree;
	coefficients = new int[degree + 1];
}

int Polynomial::MaxDegree(Polynomial b)
{
	int new_degree;

	if (degree > b.degree)
		new_degree = degree;
	else
		new_degree = b.degree;

	return new_degree;

}

int Polynomial::FindTerm(int i, int x)
{
	int elem = coefficients[i];

	for (int k = i - 1; k >= 0; k--)
	{
		elem *= x;
		elem += coefficients[k];
	}

	return elem;
}

int Polynomial::getDegree()
{
	return degree;
}

Calculations* Polynomial::Add(Calculations* b)
{
	Polynomial* new_b = dynamic_cast<Polynomial*>(b);

	int new_degree = MaxDegree(*new_b),
		lesser_degree;

	if (degree != new_degree)
		lesser_degree = degree;
	else
		lesser_degree = new_b->degree;

	Polynomial* c = new Polynomial(new_degree);

	for (int i = 0; i <= lesser_degree; i++)
		c->coefficients[i] = coefficients[i] + new_b->coefficients[i];

	if (degree != MaxDegree(*new_b))
		for (int i = lesser_degree + 1; i < new_degree + 1; i++)
			c->coefficients[i] = new_b->coefficients[i];
	else
		for (int i = lesser_degree + 1; i < new_degree + 1; i++)
			c->coefficients[i] = coefficients[i];

	return c;
}

Calculations* Polynomial::Subtract(Calculations* b)
{
	Polynomial* new_b = dynamic_cast<Polynomial*>(b);

	for (int i = 0; i < new_b->degree + 1; i++)
		new_b->coefficients[i] *= -1;

	Calculations* c = this->Add(new_b);

	for (int i = 0; i < new_b->degree + 1; i++)
		new_b->coefficients[i] *= -1;

	return c;
}

Calculations* Polynomial::Multiply(Calculations* b)
{
	Polynomial* new_b = dynamic_cast<Polynomial*>(b);

	int maxdegree = MaxDegree(*new_b);
	int new_degree = degree + new_b->degree;
	Calculations* c;

	if (maxdegree == new_b->degree)
		c = this->Multiplication(b);
	else
		c = new_b->Multiplication(this);

	return c;
}

Calculations* Polynomial::Multiplication(Calculations* b)
{
	Polynomial* new_b = dynamic_cast<Polynomial*>(b);

	int maxdegree = MaxDegree(*new_b);
	int new_degree = degree + new_b->degree;
	Polynomial* c = new Polynomial(new_degree);

	int iterator = 0, i = 0, j = 0, end = 0;

	while (iterator <= new_degree)
	{
		if (iterator >= maxdegree)
		{
			i = iterator - maxdegree;
			j = maxdegree;
			end = maxdegree - (iterator - maxdegree);
		}
		else
		{
			i = 0;
			j = iterator;
			end = iterator + 1;
		}

		int value = 0;
		for (int k = 0; k < end; k++, i++, j--)
			value += coefficients[i] * new_b->coefficients[j];

		c->coefficients[iterator] = value;
		iterator++;
	}

	return c;
}

void Polynomial::Print(int x)
{
	for (int i = 0; i < degree + 1; i++)
		std::cout << FindTerm(i, x) << ' ';

	std::cout << std::endl;
}

void Polynomial::PrintCoefficients()
{
	for (int i = 0; i < degree + 1; i++)
		std::cout << coefficients[i] << ' ';

	std::cout << std::endl;
}
