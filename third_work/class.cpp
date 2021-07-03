#include "class.h"

	Carray::Carray(int sizeOfRows, int sizeOfColumns) {
		sizeOfClassRows = sizeOfRows;
		sizeOfClassColumns = sizeOfColumns;
		matrix = new double*[sizeOfClassRows];
		for (int i = 0; i < sizeOfClassRows; i++) {
			matrix[i] = new double[sizeOfClassColumns];
		}
		matrixOfSum = new double* [sizeOfClassRows];
		for (int i = 0; i < sizeOfClassRows; i++) {
			matrixOfSum[i] = new double[sizeOfClassColumns];
		}
		row = 0;
	}

Carray::Carray(const Carray& array) {
	sizeOfClassRows = array.show_size_of_rows();
	sizeOfClassColumns = array.show_size_of_columns();
	matrix = new double* [sizeOfClassRows];
	for (int i = 0; i < sizeOfClassRows; i++) {
		matrix[i] = new double[sizeOfClassColumns];
	}
	matrixOfSum = new double* [sizeOfClassRows];
	for (int i = 0; i < sizeOfClassRows; i++) {
		matrixOfSum[i] = new double[sizeOfClassColumns];
	}
	for (int i = 0; i < sizeOfClassRows; i++) {
		for (int j = 0; j < sizeOfClassColumns; j++) {
			matrix[i][j] = array.get_element(i,j);
		}
	}
	for (int i = 0; i < sizeOfClassRows; i++) {
		for (int j = 0; j < sizeOfClassColumns; j++) {
			matrixOfSum[i][j] = array.matrixOfSum[i][j];
		}
	}
	row = 0;
}

	Carray ::~Carray() {
		for (int i = 0; i < sizeOfClassRows; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		for (int i = 0; i < sizeOfClassRows; ++i) {
			delete[] matrixOfSum[i];
		}
		delete[] matrixOfSum;
	}

	double* Carray :: operator[](int index) {
		if (index >= sizeOfClassRows)
			throw (OUT_OF_RANGE);
		return matrixOfSum[index];
	}

	double Carray::get_element(int i, int j) const{
		if (i >= sizeOfClassRows || j > sizeOfClassColumns)
			throw (OUT_OF_RANGE);
		return matrix[i][j];
	}

	void Carray::set_elem_of_matrix(int i, int j, double number) {
		if (i >= sizeOfClassRows || j > sizeOfClassColumns)
			throw (OUT_OF_RANGE);
		matrix[i][j] = number;
	}

	int Carray :: show_size_of_rows(void) const {
		return sizeOfClassRows;
	}

	int Carray::show_size_of_columns(void) const {
		return sizeOfClassColumns;
	}