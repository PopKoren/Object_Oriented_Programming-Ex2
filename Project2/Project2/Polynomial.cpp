#include <iostream>
#include "Polynomial.h"

using namespace std;

int Polynomial::_max_degree = 0;

Polynomial::Polynomial() {

	_degree = 0;
	_polynom = NULL;

}

Polynomial::Polynomial(int n) : _degree(n) {

	_polynom = new double[_degree + 1]{ 0 };

}

Polynomial::Polynomial(const double a[], int n) : _degree(n) {

	_polynom = new double[n + 1];
	int i;
	for (i = 0; i <= n; i++) {
		_polynom[i] = a[i];
		if (a[i] && i > _max_degree)
			_max_degree = i;
	}
}

Polynomial::Polynomial(const Polynomial& a) {
	_degree = a._degree;
	if (!a._polynom)
		_polynom = NULL;
	else {
		_polynom = new double[_degree + 1]{ 0 };
		for (int i = 0; i <= _degree; i++) {
			_polynom[i] = a._polynom[i];
		}
	}
}

int Polynomial::getMaxDegree() {
	return _max_degree;
}

void Polynomial::print() const {

	cout << "Polynomial = ";
	if (!_polynom && !_degree) {
		cout << "0" << endl;
		return;
	}
	int i, max = 0;
	for (i = 0; i <= _degree; i++) {
		if (_polynom[i] && i > max)
			max = i;
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!_polynom[i])
				cout << "0";
			else
				cout << _polynom[i];
		}
		else {
			cout << "+";
			if (!_polynom[i])
				cout << "(0)";
			else
				cout << "(" << _polynom[i] << ")";
			cout << "*X^" << i;
		}
	}
	cout << endl;
}

Polynomial & Polynomial::setCoeff(int a, double b) {
	_polynom[a] = b;
	return *this;
}

int Polynomial::getDegree(bool what) const {
	if (!what)
		return _degree;
	else
		return getDegree();
}

int Polynomial::getDegree() const {
	int i, cnt = 0;
	for (i = 0; i <= _degree; i++)
		if (_polynom[i])
			cnt = i;
	return cnt;
}

double Polynomial::getCoeff(int index) const {
	if (index > _max_degree) {
		return 0;
	}
	if (index < 0 || index > _degree) {
		return -1234.12;
	}
	return _polynom[index];
}

Polynomial::~Polynomial() {
	if (_polynom != NULL) {
		delete[] _polynom;
		_polynom = NULL;
	}
}

ostream& operator<<(ostream& print, const Polynomial& p) {
	print << "Polynomial = ";
	if (!p._polynom && !p._degree) {
		print << "0" << endl;
		return print;
	}
	int i, max = 0;
	for (i = 0; i <= p._degree; i++) {
		if (p._polynom[i] && i > max)
			max = i;
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!p._polynom[i])
				print << "0";
			else
				print << p._polynom[i];
		}
		else {
			print << "+";
			if (!p._polynom[i])
				print << "(0)";
			else
				print << "(" << p._polynom[i] << ")";
			print << "*X^" << i;
		}
	}
	print << endl;
	return print;
}

Polynomial& Polynomial::operator+(const Polynomial& other) const {
	int i, max;
	other._degree >= _degree ? max = other._degree : max = _degree;
	Polynomial* poly = new Polynomial(max);
	for (i = 0; i <= _degree && i <= other._degree && other._polynom && _polynom; i++)
		poly->_polynom[i] = _polynom[i] + other._polynom[i];
	while (i <= _degree && _polynom) {
		poly->_polynom[i] = _polynom[i];
		i++;
	}
	while (i <= other._degree && other._polynom) {
		poly->_polynom[i] = other._polynom[i];
		i++;
	}
	return *poly;
}

Polynomial& Polynomial::operator-(const Polynomial& other) const {

	int i, max;
	other._degree >= _degree ? max = other._degree : max = _degree;
	Polynomial* poly = new Polynomial(max);
	for (i = 0; i <= _degree && i <= other._degree; i++)
		poly->_polynom[i] = _polynom[i] - other._polynom[i];
	while (i <= _degree) {
		poly->_polynom[i] = _polynom[i];
		i++;
	}
	while (i <= other._degree) {
		poly->_polynom[i] = -other._polynom[i];
		i++;
	}
	return *poly;
}

Polynomial& Polynomial::operator*(const Polynomial& other) const {

	Polynomial* poly = new Polynomial(_degree + other._degree);
	int i, j;
	for (i = 0; i <= _degree; i++) {
		for (j = 0; j <= other._degree; j++) {
			poly->_polynom[i + j] += _polynom[i] * other._polynom[j];
			if (poly->_polynom[i + j] && i + j > _max_degree)
				_max_degree = i + j;
		}
	}
	return *poly;

}

Polynomial& Polynomial::operator*(const double c) const {
	Polynomial* poly = new Polynomial();
	*poly = *this;
	int i;
	for (i = 0; i <= _degree; i++)
		poly->_polynom[i] *= c;
	return *poly;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {


	if (_polynom) {
		delete[] _polynom;
	}
	_polynom = new double[other._degree + 1];
	_degree = other._degree;
	int i;
	for (i = 0; i <= other._degree; i++) {
		_polynom[i] = other._polynom[i];
	}
	return *this;
}

Polynomial& operator*(const double c, const Polynomial& p) {
	return p * c;

}

double& Polynomial::operator[](int index) const{
	return _polynom[index];
}

