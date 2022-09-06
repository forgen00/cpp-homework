#include <iostream>
#include <vector>
#include <map>

/*
private
public
protected 
*/

class Fraction {
private:
	int numerator;		//Числитель
	int denomenator;	//Знаменатель

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

	Fraction add(Fraction other) {
		int num = numerator * other.denomenator + other.numerator * denomenator;
		int den = denomenator * other.denomenator;

		Fraction res(num, den);
		res.reduce();
		return res;
	}

	Fraction subtraction(Fraction other) {
		int num = numerator * other.denomenator - other.numerator * denomenator;
		int den = denomenator * other.denomenator;

		Fraction res(num, den);
		res.reduce();
		return res;
	}

	//Добавить методы для умножения дробей, деления, возведения в степень.

	Fraction multiply(Fraction other) {
		int num = numerator * other.numerator;
		int den = denomenator * other.denomenator;
		
		Fraction res(num, den);
		res.reduce();
		return res;
	}

	Fraction division(Fraction other) {
		int num = numerator * other.denomenator;
		int den = denomenator * other.numerator;
		
		Fraction res(num, den);
		res.reduce();
		return res;
	}

	 void extent(int n) {
		 numerator = pow(numerator, n);
		 denomenator = pow(denomenator, n);
	}

	void print() {
		std::cout << numerator << '/' << denomenator << '\n';
	}
};

class Triangle {
private:
	int a;
	int b;
	int c;

public:
	Triangle(int aa, int bb, int cc) {
		if (a > b + c || b > a + c || c > a + b) {
			std::cerr << "Triangle doesn't exist!";
			exit(1);
		}
		a = aa;
		b = bb;
		c = cc;
	}

	int square() {
		int p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	int perimetr() {
		return a + b + c;
	}
};

class Decoder {
private:
	std::string password;
	std::map<char, char> dict; //Правило для расшифрования

public:
	//Происходит шифрование и кладётся в password
	Decoder(std::string pass, std::map<char, char>& mp) {
		for (char& x : pass) {
			password += mp[x];
		}

		for (const auto& p : mp) {
			dict[p.second] = p.first;
		}
	}

	//Метод должен возвращать расшифрованный пароль
	std::string decrypt() {
		std::string res;
		for (char c : password) {
			res += dict[c];
		}
		return res;
	}
};

class Student {
private:
	std::string fullname, dateOfBirth, phoneNumber, city, country, groupNumber;

public:
	Student() {
		std::cout << "Please enter: full name, date of birth, phone number, city, country, group number\n";
		std::cin >> fullname >> dateOfBirth >> phoneNumber >> city >> country >> groupNumber;
	}

	std::string getFullName() {
		return fullname;
	}

	std::string getDateOfBirth() {
		return dateOfBirth;
	}
	
	std::string getPhoneNumber() {
		return phoneNumber;
	}
	
	std::string getCity() {
		return city;
	}
	
	std::string getCountry() {
		return country;
	}
	
	std::string getGroupNumber() {
		return groupNumber;
	}

	void print() {
		std::cout << fullname << '\n' << dateOfBirth << '\n' 
			<< phoneNumber << '\n' << city << '\n' << country << '\n'
			<< groupNumber << '\n';
	}

};

class Dot {
private:
	int x, y, z;

public:
	Dot() {
		std::cout << "Please enter x, y, z\n";
		std::cin >> x >> y >> z;
		std::cout << '\n';
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getZ() {
		return z;
	}

	void print() {
		std::cout << x << '\n' << y << '\n' << z << '\n';
	}

	int distance(Dot other) {
		return sqrt(pow(other.x - x, 2) + pow(other.y - x, 2) + pow(other.z - z, 2));
	}

	//Метод, который принимает другую точку и считает расстояние между ними
};

int main() {
	Dot a;
	Dot other;

	a.print();
	std::cout << '\n' <<  a.distance(other);

	return 0;
}