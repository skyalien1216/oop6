#pragma once

class Calculations
{
protected :

	virtual Calculations* Multiplication(Calculations* b) = 0;

public:

	virtual Calculations* Add(Calculations* b) = 0;
	virtual Calculations* Subtract(Calculations* b) = 0;
	virtual Calculations* Multiply(Calculations* b) = 0;
};

class Polynomial : public Calculations
{
	int degree;
	int* coefficients;

	Calculations* Multiplication(Calculations* b) override;

public:

	Polynomial(int degree, int* c);
	Polynomial(int degree);

	int MaxDegree(Polynomial b);
	int FindTerm(int i, int x);

	int getDegree();

	Calculations* Add(Calculations* b) override;
	Calculations* Subtract(Calculations* b) override;
	Calculations* Multiply(Calculations* b) override;

	void Print(int x);
	void PrintCoefficients();

};