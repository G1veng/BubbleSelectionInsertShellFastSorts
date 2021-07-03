#pragma once

#include <stdlib.h>

const int OUT_OF_RANGE = 0;

class Carray {
public:
	Carray(int sizeOfRows, int sizeOfColumns);
	~Carray();
	Carray(const Carray& array);
	double* operator[](int index);
	int show_size_of_rows() const;
	int show_size_of_columns() const;
	int row;
	double get_element(int i, int j) const;
	void set_elem_of_matrix(int i, int j, double number);

private:
	int sizeOfClassRows;
	int sizeOfClassColumns;
	double** matrix;
	double** matrixOfSum;
};