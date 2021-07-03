#include "Products.h"


int get_sum_of_number(double number) {
	int sum = 0, integer = 0, numbersAfterDot = 0;
	std::string sumOfNumbersInNumber = std::to_string(number);
	for (int i = 0; numbersAfterDot != NUMBERS_AFTER_DOT + 1; i++) {
		if (sumOfNumbersInNumber[i] == '-' || sumOfNumbersInNumber[i] == '.') {
			if (sumOfNumbersInNumber[i] == '.')
				numbersAfterDot++;
			continue;
		}
		if (numbersAfterDot != 0) {
			numbersAfterDot++;
		}
		integer = sumOfNumbersInNumber[i] - 48;
		sum += integer;
	}
	return sum;
}

void get_sum_of_elements(Carray* array) {
	for (int i = 0; i < array->show_size_of_rows(); i++) {
		for (int j = 0; j < array->show_size_of_columns(); j++) {
			(*array)[i][j] = get_sum_of_number(array->get_element(i, j));
		}
	}
}

std::unique_ptr<Carray> MatrixFromConsoleInput::get_input(void) {
	int sizeOfRow = 0, sizeOfColumns = 0;
	std::cout << "Please enter size of row and column" << std::endl;
	do {
		sizeOfRow = input_digit();
		sizeOfColumns = input_digit();
		if (sizeOfColumns > 0 && sizeOfRow > 0)
			break;
		else {
			std::cout << "Please enter positive number" << std::endl;
		}
	} while (true);
	Carray* carray = new Carray(sizeOfRow, sizeOfColumns);
	std::cout << "Please enter " << carray->show_size_of_rows()* carray->show_size_of_columns() << " numbers, up to 3 numbers after dot" << std::endl;
	for (int i = 0; i < carray->show_size_of_rows(); ++i) {
		for (int j = 0; j < carray->show_size_of_columns(); j++) {
			carray->set_elem_of_matrix(i, j, get_double());
		}
	}
	std::cout << "Size of rows and columns ->\t" << carray->show_size_of_rows() << "\t" << carray->show_size_of_columns() << std::endl;
	std::cout << "Numbers of matrix:";
	output_matrix(*carray);
	get_sum_of_elements(carray);
	save_entered_data_in_file(*carray);
	std::unique_ptr<Carray> array(carray);
	return array;
}

std::unique_ptr<Carray> MatrixFromFileInput::get_input(void) {
	std::cout << "Enter please folder with data" << std::endl;
	std::unique_ptr<Carray> array = input_data_from_file();
	return array;
}

std::unique_ptr<Carray> MatrixFromRandomInput::get_input(void) {
	srand(static_cast <unsigned> (time(NULL)));
	int sizeOfRow = 0, sizeOfColumns = 0;
	double elem = 0.0;
	sizeOfRow = 1 + rand() % (RAND_FOR_SIZE_OF_ARRAY);
	sizeOfColumns = 1 + rand() % (RAND_FOR_SIZE_OF_ARRAY);
	Carray* carray = new Carray(sizeOfRow, sizeOfColumns);
	std::cout << "Size of rows and columns ->\t" << carray->show_size_of_rows() << "\t" << carray->show_size_of_columns() << std::endl;
	std::cout << "Numbers of matrix:" << std::endl;
	for (int i = 0; i < carray->show_size_of_rows(); ++i) {
		for (int j = 0; j < carray->show_size_of_columns(); j++) {
			elem = RAND_MINIMUM_FOR_NUMBERS + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (RAND_MAXIMUM_FOR_NUMBERS - RAND_MINIMUM_FOR_NUMBERS)));
			elem = round(elem * NUMBERS_AFTER_DOT_IN_RANDOM_GENERATION) / NUMBERS_AFTER_DOT_IN_RANDOM_GENERATION;
			carray->set_elem_of_matrix(i, j, elem);
			std::cout << carray->get_element(i, j) << " ";
		}
		std::cout << std::endl;
	}
	get_sum_of_elements(carray);
	save_entered_data_in_file(*carray);
	std::unique_ptr<Carray> array(carray);
	return array;
}

std::shared_ptr<Product> Container::get_input_type(type_of_inputs input) {
	switch (input) {
	case type_of_inputs::manualInput: {
		if (Container::manual == nullptr)
			manual = std::make_shared<MatrixFromConsoleInput>(MatrixFromConsoleInput());
		return manual;
	}
	case type_of_inputs::randomInput: {
		if (Container::random == nullptr)
			random = std::make_shared<MatrixFromRandomInput>(MatrixFromRandomInput());
		return random;
	}
	case type_of_inputs::fileInput: {
		if (Container::file == nullptr)
			file = std::make_shared<MatrixFromFileInput>(MatrixFromFileInput());
		return file;
	}
	}
	return nullptr;
}