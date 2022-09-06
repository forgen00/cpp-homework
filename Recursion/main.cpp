#include <iostream>

/*
1) ������� ����� n. ����� �������� ����������� �������
long long findFibonnachi(int n), ������� ������� n-��� ����� ���������. �������: fib_0 = 0, fib_1 = 1,
fib_n = fib_{n - 1} + fib_{n - 2}

2) ������� ����� n, ������� ������ ��� ��������
void printReserved(int n)

3) ������� ���������� � �������

4) �������� ������������������ ����� �����, �������������� ����. ����� ����� ���� �����

5) �������� ������������������ ����� �����, �������������� ����. ����� �������� ���� �����
*/

long long findFibonnachi(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	
	return findFibonnachi(n - 1) + findFibonnachi(n - 2);
}

void printReserved(int n) {
	if (n > 0) {
		int a = n % 10;
		std::cout << a << std::endl;
		n /= 10;
		printReserved(n);
	}
}


long long binPower(int a, int n) {
	if (n == 0) {
		return 1;
	}

	if (n % 2 == 0) {
		long long res = binPower(a, n / 2);
		return res * res;
	}

	else if (n % 2 == 1) {
		return a * binPower(a, n - 1);
	}
}


int findsum() {
	int num;
	std::cin >> num;
	return num == 0 ? 0 : num + findsum();
}


int findmax(int firstNum = 0) {
	int n;
	std::cin >> n;
	if (firstNum = 0) {
		firstNum = n;
	}

	else {
		return n == 0 ? 0 : std::max(findmax(firstNum), n);
	}
}


int main() {
	
	return 0;
}