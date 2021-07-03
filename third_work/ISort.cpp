#include "ISort.h"
#include <iostream>

BubbleSort::BubbleSort() {
	changes = 0;
	compares = 0;
}

int BubbleSort::get_changes(void) const {
	return changes;
}

int BubbleSort::get_compares(void) const {
	return compares;
}

std::unique_ptr<Carray> BubbleSort::copyForSort(const Carray& array) {
	auto arrinner = new Carray(array);
	sort(arrinner);
	std::unique_ptr<Carray> ptrArrinner(arrinner);
	return ptrArrinner;
}

void BubbleSort::sort(Carray* array) {
	for (int row = 0; row < array->show_size_of_rows(); row++) {
		for (int i = 0; i < array->show_size_of_columns(); i++) {
			for (int j = 0; j < array->show_size_of_columns() - i - 1; j++) {
				if ((*array)[row][j] < (*array)[row][j + 1]) {
					double temp = (*array)[row][j];
					double tempForOriginalMatrix = array->get_element(row, j);
					(*array)[row][j] = (*array)[row][j+1];
					array->set_elem_of_matrix(row, j, array->get_element(row, j + 1));
					(*array)[row][j+1] = temp;
					array->set_elem_of_matrix(row, j + 1, tempForOriginalMatrix);
					changes++;
					compares++;
				}
				else {
					compares++;
				}
			}
			if (changes == 0)
				break;
		}
	}
}


SellectionSort::SellectionSort() {
	changes = 0;
	compares = 0;
}

int SellectionSort::get_changes(void) const {
	return changes;
}

int SellectionSort::get_compares(void) const {
	return compares;
}

std::unique_ptr<Carray> SellectionSort::copyForSort(const Carray& array) {
	auto arrinner = new Carray(array);
	sort(arrinner);
	std::unique_ptr<Carray> ptrArrinner(arrinner);
	return ptrArrinner;
}

void SellectionSort::sort(Carray* array) {
	for (int row = 0; row < array->show_size_of_rows(); row++) {
		double highest = 0, highestForOriginalMatrix = 0;
		int currentHighestNumber = 0;
		bool finded = false;
		for (int i = 0; i < array->show_size_of_columns() - 1; i++) {
			finded = false;
			currentHighestNumber = i;
			highest = (*array)[row][i];
			highestForOriginalMatrix = array->get_element(row, i);
			for (int j = i + 1; j < array->show_size_of_columns(); j++) {
				if ((*array)[row][j] > highest) {
					currentHighestNumber = j;
					highest = (*array)[row][j];
					highestForOriginalMatrix = array->get_element(row, j);
					finded = true;
					compares++;
				}
				else {
					compares++;
				}
			}
			if (finded) {
				(*array)[row][currentHighestNumber] = (*array)[row][i];
				array->set_elem_of_matrix(row, currentHighestNumber, array->get_element(row, i));
				(*array)[row][i] = highest;
				array->set_elem_of_matrix(row, i, highestForOriginalMatrix);
				changes++;
			}
		}
	}
}


InsertSort::InsertSort() {
	changes = 0;
	compares = 0;
}

int InsertSort::get_changes(void) const {
	return changes;
}

int InsertSort::get_compares(void) const {
	return compares;
}

std::unique_ptr<Carray> InsertSort::copyForSort(const Carray& array) {
	auto arrinner = new Carray(array);
	sort(arrinner);
	std::unique_ptr<Carray> ptrArrinner(arrinner);
	return ptrArrinner;
}

void InsertSort::sort(Carray* array) {
	for (int row = 0; row < array->show_size_of_rows(); row++) {
		double temp = 0, tempForOriginalMatrix = 0;
		for (int i = 1; i < array->show_size_of_columns(); i++) {
			temp = (*array)[row][i];
			tempForOriginalMatrix = array->get_element(row, i);
			for (int j = i - 1; j >= 0 && temp > (*array)[row][j]; j--) {
				(*array)[row][j+1] = (*array)[row][j];
				array->set_elem_of_matrix(row, j + 1, array->get_element(row, j));
				(*array)[row][j] = temp;
				array->set_elem_of_matrix(row, j, tempForOriginalMatrix);
				changes++;
			}
			compares++;
		}
	}
}


ShellSort::ShellSort() {
	changes = 0;
	compares = 0;
}

int ShellSort::get_changes(void) const {
	return changes;
}

int ShellSort::get_compares(void) const {
	return compares;
}

std::unique_ptr<Carray> ShellSort::copyForSort(const Carray& array) {
	auto arrinner = new Carray(array);
	sort(arrinner);
	std::unique_ptr<Carray> ptrArrinner(arrinner);
	return ptrArrinner;
}

void ShellSort::sort(Carray* array) {
	for (int row = 0; row < array->show_size_of_rows(); row++) {
		int d = array->show_size_of_columns() / 2;
		while (d > 0) {
			for (int i = 0; i <= array->show_size_of_columns() - 1 - d; i++) {
				int j = i;
				while (j >= 0 && (*array)[row][j] < (*array)[row][j+d]) {
					double temp = (*array)[row][j];
					double tempForOriginalMatrix = array->get_element(row, j);
					(*array)[row][j] = (*array)[row][j+d];
					array->set_elem_of_matrix(row, j, array->get_element(row, j + d));
					(*array)[row][j+d] = temp;
					array->set_elem_of_matrix(row, j + d, tempForOriginalMatrix);
					j--;
					compares++;
					changes++;
				}
				if (j >= 0 && (*array)[row][j] >= (*array)[row][j + d])
					compares++;
			}
			d = d / 2;
		}
	}
}


FastSort::FastSort() {
	changes = 0;
	compares = 0;
	left = 0;
	right = 0;
	row = 0;
	nesting = 0;
}

void FastSort::set_right_and_left(int outsideLeft, int outsideRight) {
	right = outsideRight;
	left = outsideLeft;
}

int FastSort::get_changes(void) const {
	return changes;
}

int FastSort::get_compares(void) const {
	return compares;
}

std::unique_ptr<Carray> FastSort::copyForSort(const Carray& array) {
	auto arrinner = new Carray(array);
	for (int i = 0; i < arrinner->show_size_of_rows(); i++) {
		set_right_and_left(0, arrinner->show_size_of_columns() - 1);
		arrinner->row = i;
		nesting = 0;
		sort(arrinner);
	}
	std::unique_ptr<Carray> ptrArrinner(arrinner);
	return ptrArrinner;
}

void FastSort::sort(Carray* array){
	nesting++;
	int i = 0, j = 0;
	double tmp = 0, pivot = 0, tempForOriginalMatrix = 0;
	i = left;
	j = right;
	pivot = (*array)[array->row][(left + (right - left) / 2)];
	do {
		while ((*array)[array->row][i] > pivot) {
			compares++;
			i++;
		}
		compares++;
		while ((*array)[array->row][j] < pivot) {
			compares++;
			j--;
		}
		compares++;
		if (i <= j) {
			if (i != j) {
				changes++;
				tmp = (*array)[array->row][i];
				tempForOriginalMatrix = array->get_element(array->row, i);
				(*array)[array->row][i] = (*array)[array->row][j];
				array->set_elem_of_matrix(array->row, i, array->get_element(array->row, j));
				(*array)[array->row][j] = tmp;
				array->set_elem_of_matrix(array->row, j, tempForOriginalMatrix);
			}
			i++;
			if (j > 0) {
				j--;
			}
		}
	} while (i <= j);
	if (i < right) {
		set_right_and_left(i, right);
		sort(array);
	}
	if (nesting == 1)
		set_right_and_left(0, array->show_size_of_columns() - 1);
	if (j > left) {
		set_right_and_left(left, j);
		sort(array);
	}
	nesting--;
}