#include "input_output.h"

int input_digit(void) {
	int digit = 0;
	do {
		while ((std::cin >> digit) && (std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return digit;
		}
		std::cout << "Error, please enter number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (true);
}

double get_double(void) {
	double digit = 0;
	do {
		while ((std::cin >> digit) && (std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return digit;
		}
		std::cout << "Error, please enter number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (true);
}

bool end_the_program(void) {
	std::cout << "Enter a number to repeat program, letter to end" << std::endl;
	std::string buffer = { 0 };
	int i = 0;
	std::cin >> buffer;
	do {
		if ((buffer[i] > CHAR_NINE || buffer[i] < CHAR_ZERO) && buffer[i] != CHAR_MINUS) {
			while (getchar() != '\n');
			return false;
		}
		++i;
	} while (buffer[i] != '\0');
	while (getchar() != '\n');
	return true;
}

void output_matrix(Carray& array) {
	std::cout <<  std::endl;
	for (int i = 0; i < array.show_size_of_rows(); ++i) {
		for (int j = 0; j < array.show_size_of_columns(); j++) {
			std::cout << array.get_element(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool is_string_only_digits(std::string someString) {
	size_t sizeOfString = someString.size();
	for (unsigned int i = 0; i < sizeOfString; ++i) {
		if ((someString[i] > CHAR_NINE || someString[i] < CHAR_ZERO) && someString[i] != CHAR_MINUS && someString[i] != CHAR_DOT) {
			std::cout << someString[i] << std::endl;
			return false;
		}
	}
	return true;
}

void out_put_information_text(int i) {
	switch (i) {
	case 0:
		std::cout << "BubbleSort:";
		break;
	case 1:
		std::cout << "SellectionSort:";
		break;
	case 2:
		std::cout << "InsertSort:";
		break;
	case 3:
		std::cout << "ShellSort:";
		break;
	case 4:
		std::cout << "FastSort:";
		break;
	}
}

std::string out_put_information(int i){
		switch (i) {
		case 0:
			return "BubbleSort:";
			break;
		case 1:
			return "SellectionSort:";
			break;
		case 2:
			return "InsertSort:";
			break;
		case 3:
			return "ShellSort:";
			break;
		case 4:
			return "FastSort:";
			break;
		}
		return "NoneSort";
	}

	void out_put_results(int* changes, int* compares, int sizeOfTests) {
		std::cout << "results:" << std::endl;
		std::cout << "type of sort\t|" << "changes" << "\t|" << "compares" << std::endl;
		for (int i = 0; i < sizeOfTests; i++) {
			out_put_information_text(i);
			std::cout << "\t|\t" << changes[i] << "\t|\t" << compares[i] << std::endl;
		}
	}