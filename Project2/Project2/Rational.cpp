#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational() : _nom(), _denom(0) {
	_denom.setCoeff(0, 1);
}

void Rational::print() const {

	_nom.print();
	cout << "--------------------------" << endl;
	_denom.print();
}

Rational::Rational(const Polynomial& a, const Polynomial& b) {
	_nom = a; 
	_denom = b;
}

Polynomial& Rational::getNom()  {
	return _nom;
}

Polynomial& Rational::getDenom()  {
	return _denom;
}

ostream& operator<<(ostream& print, const Rational& r) {
	print << "numerator=" << r._nom;
	print << "--------------------------" << endl;
	print << "denominator=" << r._denom;
	return print;
}

Rational& Rational::operator=(const Rational& r) {
	_nom = r._nom;
	_denom = r._denom;
	return *this;
}
Rational& Rational::operator+(const Rational& r) const {
	Rational* rat = new Rational(_nom * r._denom + _denom * r._nom, _denom * r._denom);
	return *rat;
}
Rational& Rational::operator*(const Rational& r) const {
	Rational* rat = new Rational(_nom * r._nom, _denom * r._denom);
	return *rat;
}
Rational& Rational::operator*(const double c) const {
	Rational* rat = new Rational(_nom * c, _denom * c);
	return *rat;
}
Rational& operator*(const double c, const Rational& r) {
	return r * c;
}