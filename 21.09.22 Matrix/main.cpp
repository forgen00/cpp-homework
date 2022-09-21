#include <iostream>

class Matrix {
private:
	double** a;
	int rows;		//кол-во строк
	int colums;		//кол-во столбцов

	bool is_correct(int i, int j);

public:
	Matrix(int r, int c);
	Matrix(const Matrix& m);
	~Matrix();
	Matrix& operator=(const Matrix& m);

	void set(int i, int j, double value);
	double get(int i, int j);

	friend bool operator==(const Matrix& left, const Matrix& right);
	friend bool operator!=(const Matrix& left, const Matrix& right);

	friend Matrix operator+(const Matrix& left, const Matrix& right);
	friend Matrix operator-(const Matrix& left, const Matrix& right);
	friend Matrix operator*(const Matrix& left, double number);
	friend Matrix operator*(const Matrix& left, const Matrix& right);

	void print();
};

bool Matrix::is_correct(int i, int j) {
	return i < rows && j < colums && i >= 0 && j >= 0;
}

Matrix::Matrix(int r, int c) {
	rows = r;
	colums = c;
	a = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		a[i] = new double[colums];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colums; ++j) {
			a[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& m) {
	rows = m.rows;
	colums = m.colums;
	a = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		a[i] = new double[colums];
		for (int j = 0; j < colums; ++j) {
			this->a[i][j] = m.a[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] a[i];
	}
	delete[] a;
}

Matrix& Matrix::operator=(const Matrix& m) {
	if (a == m.a) {
		return *this;
	}

	if (rows != m.rows || colums != m.colums) {
		throw std::out_of_range("Sizes isn't the same");
	}

	Matrix new_matrix(m.rows, m.colums);
	for (int i = 0; i < m.rows; ++i) {
		for (int j = 0; j < m.colums; ++j) {
			new_matrix.set(i, j, m.a[i][j]);
		}
	}

	for (int i = 0; i < rows; ++i) {
		delete[] a[i];
	}
	delete[] a;

	return new_matrix;
}

void Matrix::set(int i, int j, double value) {
	if (is_correct(i, j)) {
		a[i][j] = value;
	}
}

double Matrix::get(int i, int j) {
	if (is_correct(i, j)) {
		return a[i][j];
	}
	throw std::out_of_range("Incorrect index");
}

bool operator==(const Matrix& left, const Matrix& right) {
	if (left.rows == right.rows && left.colums == right.colums) {
		int rows = left.rows;
		int colums = left.colums;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < colums; ++j) {
				if (left.a[i][j] != right.a[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	throw std::out_of_range("Matrix sizes doesn't match");
}

bool operator!=(const Matrix& left, const Matrix& right) {
	return !(left == right);
}


Matrix operator+(const Matrix& left, const Matrix& right) {
	if (left.rows == right.rows && left.colums == right.colums) {
		Matrix new_matrix(left.rows, left.colums);
		int rows = left.rows;
		int colums = left.colums;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < colums; ++j) {
				new_matrix.a[i][j] = left.a[i][j] + right.a[i][j];
			}
		}
		return new_matrix;
	}
	throw std::out_of_range("Matrix sizes doesn't match");
}

Matrix operator-(const Matrix& left, const Matrix& right) {
	return left + (right * (-1.0));
	/*
	if (left.rows == right.rows && left.colums == right.colums) {
		Matrix new_matrix(left.rows, left.colums);
		int rows = left.rows;
		int colums = left.colums;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < colums; ++j) {
				new_matrix.a[i][j] = left.a[i][j] - right.a[i][j];
			}
		}
		return new_matrix;
	}
	*/
}

Matrix operator*(const Matrix& left, double number) {
	Matrix result = left;
	for (int i = 0; i < left.rows; ++i) {
		for (int j = 0; j < left.colums; ++j) {
			result.a[i][j] *= number;
		}
	}
	return result;
}

Matrix operator*(const Matrix& left, const Matrix& right) {
	if (left.colums != right.rows) {
		throw std::out_of_range("Wrong sizes of matrix");
	}
	int m = left.colums;
	Matrix result(left.rows, right.colums);
	for (int i = 0; i < result.rows; ++i) {
		for (int j = 0; j < result.colums; ++j) {
			double cur = 0.0;
			for (int k = 0; k < m; ++k) {
				cur += left.a[i][k] * right.a[k][j];
			}
			result.set(i, j, cur);
		}
	}
	return result;
}

void Matrix::print() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colums; ++j) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	Matrix someMatrix(3, 4);
	Matrix otherMatrix(4, 3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			someMatrix.set(i, j, i + j);
		}
	}
	someMatrix.print();
	std::cout << '\n';

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			otherMatrix.set(i, j, 5);
		}
	}
	otherMatrix.print();
	std::cout << '\n';

	Matrix sumMatrix = otherMatrix * someMatrix;
	sumMatrix.print();
	
	return 0;
}