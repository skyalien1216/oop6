#pragma once

class Polynomial
{
	int degree;
	int* coefficients;

	Polynomial Multiply(Polynomial b);

public:

	Polynomial(int degree, int* c);
	Polynomial(int degree);

	int MaxDegree(Polynomial b);
	int FindTerm(int i, int x);

	int getDegree();

	friend Polynomial operator+(Polynomial a, Polynomial b);
	friend Polynomial operator-(Polynomial a, Polynomial b);
	friend Polynomial operator*(Polynomial a, Polynomial b);

	void Print(int x);
	void PrintCoefficients();

};