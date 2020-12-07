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

Polynomial operator+(Polynomial a, Polynomial b)
{
	int new_degree = a.MaxDegree(b),
		lesser_degree;

	if (a.degree != new_degree)
		lesser_degree = a.degree;
	else
		lesser_degree = b.degree;

	Polynomial c(new_degree);

	for (int i = 0; i <= lesser_degree; i++)
		c.coefficients[i] = a.coefficients[i] + b.coefficients[i];

	if (a.degree != a.MaxDegree(b))
		for (int i = lesser_degree + 1; i < new_degree + 1; i++)
			c.coefficients[i] = b.coefficients[i];
	else
		for (int i = lesser_degree + 1; i < new_degree + 1; i++)
			c.coefficients[i] = a.coefficients[i];

	return c;
}

Polynomial operator-(Polynomial a, Polynomial b)
{
	for (int i = 0; i < b.degree + 1; i++)
		b.coefficients[i] *= -1;

	Polynomial c = a + b;

	for (int i = 0; i < b.degree + 1; i++)
		b.coefficients[i] *= -1;

	return c;
}

Polynomial operator*(Polynomial a, Polynomial b)
{
	int maxdegree = a.MaxDegree(b);
	int new_degree = a.degree + b.degree;
	Polynomial c(new_degree);

	if (maxdegree == b.degree)
		c = a.Multiply(b);
	else
		c = b.Multiply(a);

	return c;
}

Polynomial Polynomial::Multiply(Polynomial b)
{
	int maxdegree = MaxDegree(b);
	int new_degree = degree + b.degree;
	Polynomial c(new_degree);

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
		{
			value += coefficients[i] * b.coefficients[j];
		}

		c.coefficients[iterator] = value;
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
