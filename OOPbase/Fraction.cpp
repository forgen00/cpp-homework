#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
	Triangle(int a, int b, int c) {
		if (a > b + c || b > a + c || c > a + b) {
			std::cerr << "Triangle doesn't exist!";
			exit(1);
		}
		this->a = a;
		this->b = b;
		this->c = c;
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

//Перебирает все строки, состоящие из латинских символов
/*
class BruteForcer {
private:
	int len;
	std::vector<std::string> passwords;

public:
	BruteForcer(int n, std::string s="") {
		
	}

	auto getPasswords() {
		return passwords;
	}
};
*/

/*
Цифры числа надо хранить в обратном порядке
1. Написать конструкторы от лонга и стринга
2. Реализовать метод print
3. Реализовать метод add(сложение столбиком)
*/

class BigInteger {
private:
	std::vector<int> digits;
	bool isNegative;

	BigInteger(std::vector<int>& s) {
		this->digits = s;
	}

public:
	BigInteger(long long n) {
		n < 0 ? isNegative = true : isNegative = false;
		while (n != 0) {
			digits.push_back(n % 10);
			n /= 10;
		}
	}
	
	BigInteger(std::string s) {
		if (s[0] == '-') {
			isNegative = true;
		}
		for (int i = s.size() - 1; i >= 0; --i) {
			digits.push_back(s[i] - '0');
		}
	}
	
	BigInteger add(BigInteger other) {
		std::vector<int> result;
		int size = std::max(digits.size(), other.digits.size());
		int carry = 0;
		for (int i = 0; i < size; ++i) {
			int cur = carry;

			if (i < digits.size()) {
				cur += digits[i];
			}
			if (i < other.digits.size()) {
				cur += other.digits[i];
			}
			result.push_back(cur % 10);
			carry = (cur >= 10);
		}

		if (carry == 1) {
			result.push_back(1);
		}

		return BigInteger(result);
	}
	
	void print() {
		if (isNegative) {
			std::cout << '-';
		}
		for (int i = digits.size() - 1; i >= 0; --i) {
			std::cout << digits[i];
		}
	}

	int getDigitsSize() {
		return digits.size();
	}

	std::vector<int> getDigits() {
		return digits;
	}
};


int main() {
	BigInteger s(99);
	BigInteger b("100");
	BigInteger sum = s.add(b);
	sum.print();

	return 0;
}