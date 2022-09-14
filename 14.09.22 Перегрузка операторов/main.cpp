#include <iostream>

class Fraction {
private:
	int numerator;
	int denomenator;

	void reduce() {
		for (int divisor = 2;
			divisor < std::min(numerator, denomenator);
			++divisor) {

			while (numerator % divisor == 0
				&& denomenator % divisor == 0) {
				numerator /= divisor;
				denomenator /= divisor;
			}
		}
	}

public:
	Fraction(int num, int den) {
		if (den == 0) {
			std::cerr << "Den must be not equal to zero!";
			exit(1);
		}
		numerator = num;
		denomenator = den;
	}

	void extent(int n) {
		numerator = pow(numerator, n);
		denomenator = pow(denomenator, n);
	}

	void print() {
		std::cout << numerator << '/' << denomenator << '\n';
	}

	friend Fraction operator+(Fraction f1, Fraction f2);
	friend Fraction operator-(Fraction f1, Fraction f2);
	friend Fraction operator*(Fraction f1, Fraction f2);
	friend Fraction operator/(Fraction f1, Fraction f2);
	friend bool operator==(Fraction t1, Fraction t2);
	friend bool operator!=(Fraction t1, Fraction t2);
	friend bool operator<(Fraction t1, Fraction t2);
	friend bool operator<=(Fraction t1, Fraction t2);
	friend bool operator>(Fraction t1, Fraction t2);
	friend bool operator>=(Fraction t1, Fraction t2);
};

Fraction operator+(Fraction f1, Fraction f2) {
	int num = f1.numerator * f2.denomenator + f2.numerator * f1.denomenator;
	int den = f1.denomenator * f2.denomenator;
	Fraction res(num, den);
	res.reduce();
	return res;
}

Fraction operator-(Fraction f1, Fraction f2) {
	int num = f1.numerator * f2.denomenator - f2.numerator * f1.denomenator;
	int den = f1.denomenator * f2.denomenator;
	Fraction res(num, den);
	res.reduce();
	return res;
}

Fraction operator*(Fraction f1, Fraction f2) {
	int num = f1.numerator * f2.numerator;
	int den = f1.denomenator * f2.denomenator;
	Fraction res(num, den);
	res.reduce();
	return res;
}

Fraction operator/(Fraction f1, Fraction f2) {
	int num = f1.numerator * f2.denomenator;
	int den = f1.denomenator * f2.numerator;
	Fraction res(num, den);
	res.reduce();
	return res;
}

bool operator==(Fraction t1, Fraction t2) {
	t1.reduce();
	t2.reduce();
	return t1.numerator == t2.numerator && t1.denomenator == t2.denomenator;
}

bool operator!=(Fraction t1, Fraction t2) {
	return !(t1 == t2);
}

bool operator<(Fraction t1, Fraction t2) {
	int num1 = t1.numerator * t2.denomenator;
	int num2 = t2.numerator * t1.denomenator;
	return num1 < num2;
}

bool operator<=(Fraction t1, Fraction t2) {
	return t1 == t2 || t1 < t2;
}

bool operator>(Fraction t1, Fraction t2) {
	return !(t1 <= t2);
}

bool operator>=(Fraction t1, Fraction t2) {
	return !(t1 < t2);
}

int main() {
	Fraction first(1, 2);
	Fraction second(2, 3);
	Fraction result = first + second;
	result.print();
	
	return 0;
}