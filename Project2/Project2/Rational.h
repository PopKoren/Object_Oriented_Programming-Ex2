#pragma once
#include <iostream>
#include "Polynomial.h"

using namespace std;

class Rational {
private:
	Polynomial _nom;
	Polynomial _denom;
public:
	Rational();
	Rational(const Polynomial&, const Polynomial&);
	Polynomial& getNom();
	Polynomial& getDenom();
	Rational& operator=(const Rational&);
	Rational& operator+(const Rational&) const;
	Rational& operator*(const Rational&) const;
	Rational& operator*(const double) const;
	void print() const;
	friend ostream& operator<<(ostream&, const Rational&);
	friend Rational& operator*(const double, const Rational&);
};




