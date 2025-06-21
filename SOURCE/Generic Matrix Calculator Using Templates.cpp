#include <iostream>
#include <vector>

using namespace std;

// Template class for Matrix operations
template <typename T>
class Matrix {
private:
	vector<vector<T>> mat;
	int rows, cols;

public:
	// Constructor
	Matrix(int r, int c) : rows(r), cols(c) {
		mat.resize(rows, vector<T>(cols));
	}
	
	// Function to input matrix
	void inputMatrix() {
		cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> mat[i][j];
			}
		}
	}
	
	// Function to display matrix
	void displayMatrix() const {
		for (const auto& row : mat) {
			for (const auto& elem : row) {
				cout << elem << " ";
			}
			cout << endl;
		}
	}

	// Operator overloading
	Matrix operator+(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.mat[i][j] = mat[i][j] + other.mat[i][j];
			}
		}
		return result;
	}

	Matrix operator-(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.mat[i][j] = mat[i][j] - other.mat[i][j];
			}
		}
		return result;
	}

	Matrix operator*(const Matrix& other) const {
		if (cols != other.rows) {
			throw invalid_argument("Matrix dimensions do not match for multiplication.");
		}
		Matrix result(rows, other.cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < other.cols; j++) {
				result.mat[i][j] = 0;
				for (int k = 0; k < cols; k++) {
					result.mat[i][j] += mat[i][k] * other.mat[k][j];
				}
			}
		}
		return result;
	}
};

// Main Function
int main() {
	int rows, cols;

	cout << "Enter number of rows and columns for the matrix: ";
	cin >> rows >> cols;

	Matrix<int> mat1(rows, cols);
	Matrix<int> mat2(rows, cols);

	cout << "Enter first matrix:\n";
	mat1.inputMatrix();

	cout << "Enter second matrix:\n";
	mat2.inputMatrix();

	// Matrix Addition
	cout << "\nMatrix Addition:\n";
	Matrix<int> sum = mat1 + mat2;
	sum.displayMatrix();

	// Matrix Subtraction
	cout << "\nMatrix Subtraction:\n";
	Matrix<int> diff = mat1 - mat2;
	diff.displayMatrix();

	// Matrix Multiplication
	cout << "\nMatrix Multiplication:\n";
	try {
		Matrix<int> prod = mat1 * mat2;
		prod.displayMatrix();
	} catch (const invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}
