#include <iostream>
using namespace std;

class Matrix {
private:
    int** ptr;
    int rows;
    int cols;

public:
    // Default Constructor
    Matrix() {
        rows = cols = 2;
        ptr = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            ptr[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                ptr[i][j] = 0;
            }
        }
    }

    // Overloaded Constructor
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        ptr = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            ptr[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                ptr[i][j] = 0;
            }
        }
    }

    // Destructor to free memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    // Matrix addition
    Matrix Add(Matrix m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix addition is not possible. Matrices have different sizes." << endl;
            return *this;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.ptr[i][j] = ptr[i][j] + m.ptr[i][j];
            }
        }
        return result;
    }

    // Matrix subtraction
    Matrix Subtract(Matrix m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix subtraction is not possible. Matrices have different sizes." << endl;
            return *this;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
            }
        }
        return result;
    }

    // Input matrix elements
    void Input() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> ptr[i][j];
            }
        }
    }

    // Display matrix elements
    void PrintMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns for matrix 1: ";
    cin >> r >> c;

    Matrix matrix1(r, c);
    matrix1.Input();

    cout << "Enter number of rows and columns for matrix 2: ";
    cin >> r >> c;

    Matrix matrix2(r, c);
    matrix2.Input();

    cout << "Matrix 1:" << endl;
    matrix1.PrintMatrix();
    cout << endl;

    cout << "Matrix 2:" << endl;
    matrix2.PrintMatrix();
    cout << endl;

    Matrix resultAdd = matrix1.Add(matrix2);
    cout << "Matrix Addition:" << endl;
    resultAdd.PrintMatrix();
    cout << endl;

    Matrix resultSub = matrix1.Subtract(matrix2);
    cout << "Matrix Subtraction:" << endl;
    resultSub.PrintMatrix();
    cout << endl;

    return 0;
}
