#pragma once
#include <iostream>
using namespace std;

class Polynomial {

private:
	int _degree;
	double* _polynom;
	static int _max_degree;

public:
	Polynomial();
	Polynomial(int degree);
	Polynomial(const double c[], int a);
	Polynomial(const Polynomial& a);
	~Polynomial();
	static int getMaxDegree();
	void print() const;
	Polynomial& setCoeff(int a, double b);
	int getDegree(bool what) const;
	int getDegree() const;
	double getCoeff(int index) const;
	friend ostream& operator<<(ostream& out, const Polynomial& other);
	friend Polynomial& operator*(const double num, const Polynomial& other);
	Polynomial& operator*(const Polynomial& other) const;
	Polynomial& operator*(const double) const;
	Polynomial& operator+(const Polynomial& other) const;
	Polynomial& operator-(const Polynomial& other) const;
	Polynomial& operator=(const Polynomial& other);
	double& operator[](int index) const;
	
};
