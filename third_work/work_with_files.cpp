#include "work_with_files.h"
#include "products.h"

std::unique_ptr<Carray> input_data_from_file(void) {
	std::string path = { 0 };
	std::string rows = { 0 }, columns = { 0 }, data = { 0 };
	do {
		path = get_string_txt();
		std::ifstream file(path, std::ios_base::in);
		try {
			static_cast<void>(fs::is_regular_file(path));
		}
		catch (...) {
			std::cout << "Error, please try again" << std::endl;
			continue;
		}
		if (!(file.is_open())) {
			std::cout << "File is not existing" << std::endl;
			file.close();
		}
		if ((file.is_open()) || !file.fail()) {
			file.close();
			break;
		}
	} while (true);
	std::ifstream file(path, std::ios_base::in);
	file >> rows;
	if (!(is_string_only_digits(rows))) {
		std::cout << "File with incorrect data" << std::endl;
		exit(fileWithIncorrecData);
	}
	file >> columns;
	if (!(is_string_only_digits(columns))) {
		std::cout << "File with incorrect data" << std::endl;
		exit(fileWithIncorrecData);
	}
	Carray* carray = new Carray(std::stoi(rows), std::stoi(columns));
	for (int i = 0; i < carray->show_size_of_rows(); i++) {
		for (int j = 0; j < carray->show_size_of_columns(); j++) {
			file >> data;
			if (!(is_string_only_digits(data))) {
				std::cout << "File with incorrect data" << std::endl;
				exit(fileWithIncorrecData);
			}
			carray->set_elem_of_matrix(i , j, std::stod(data));
		}
	}
	get_sum_of_elements(carray);
	std::unique_ptr<Carray> array(carray);
	std::cout << "Size of rows and columns ->\t" << carray->show_size_of_rows() << "\t" << carray->show_size_of_columns() << std::endl;
	std::cout << "Numbers of matrix:" << std::endl;
	for (int i = 0; i <= carray->show_size_of_rows() - 1; i++) {
		for (int j = 0; j <= carray->show_size_of_columns() - 1; j++) {
			std::cout << array->get_element(i, j) << " ";
		}
		std::cout << std::endl;
	}
	return array;
}


std::string get_string_txt(void) {
	std::string path;
	std::cout << "Enter way to folder please:" << std::endl;
	std::cin >> path;
	while (getchar() != '\n');
	return path;
}

std::string convert_int_to_string(int n) {
	std::ostringstream someString;
	someString << n;
	return someString.str();
}

void save_in_file(Carray& array) {
	std::string rows = { 0 }, columns = { 0 }, data = { 0 };
	std::string path = { 0 };
	std::cout << "You want to save data in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	switch (input_digit()) {
	case true: {
		do {
			path = get_string_txt();
			std::ofstream file(path, std::ios_base::in);
			try {
				static_cast<void>(fs::is_regular_file(path));
			}
			catch (...) {
				std::cout << "Error, please try again" << std::endl;
				continue;
			}
			if ((file.is_open())) {
				std::cout << "You want to rewrite file?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "2 - no" << std::endl;
				if (input_digit() == 2) {
					file.close();
					continue;
				}
			}
			break;
		} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
		rows = convert_int_to_string(array.show_size_of_rows());
		file << rows << " ";
		columns = convert_int_to_string(array.show_size_of_columns());
		file << columns << " ";
		for (int i = 0; i < array.show_size_of_rows(); i++) {
			for (int j = 0; j < array.show_size_of_columns(); j++) {
				data = { 0 };
				data = convert_int_to_string(array.show_size_of_columns());
				file << data << " ";
			}
		}
		file.close();
		std::cout << "Result saved" << std::endl;
		break;
	}
	default:;
	}
}

void save_results_in_file(int* compares, int* changes, int sizeOfTest){
	std::string path = { 0 };
	std::cout << "You want save results in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	switch (input_digit()) {
	case true: {
		do {
			path = get_string_txt();
			std::ofstream file(path, std::ios_base::in);
			try {
				static_cast<void>(fs::is_regular_file(path));
			}
			catch (...) {
				std::cout << "Error, please try again" << std::endl;
				continue;
			}
			if ((file.is_open())) {
				std::cout << "You want to rewrite file?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "2 - no" << std::endl;
				if (input_digit() == 2) {
					file.close();
					continue;
				}
			}
			break;
		} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
			file << "results:" << std::endl;
			file << "type of sort\t|" << "changes" << "\t|" << "compares" << std::endl;
			for (int i = 0; i < sizeOfTest; i++) {
				file << out_put_information(i);
				file << "\t|\t" << changes[i] << "\t|\t" << compares[i] << std::endl;
		}
			std::cout << "Result saved" << std::endl;
	}
	}
}

void save_entered_data_in_file(Carray& array) {
	std::string path = { 0 };
	std::string rows = { 0 }, columns = { 0 }, data = { 0 };
	std::cout << "You want save entered data in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	switch (input_digit()) {
	case true: {
		do {
			path = get_string_txt();
			std::ifstream file(path, std::ios_base::in);
			try {
				static_cast<void>(fs::is_regular_file(path));
			}
			catch (...) {
				std::cout << "Error, please try again" << std::endl;
				continue;
			}
			if (file.is_open()) {
				std::cout << "You want to rewrite file?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "2 - no" << std::endl;
				if (input_digit() == 2) {
					file.close();
					continue;
				}
			}
			break;
		} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
		rows = convert_int_to_string(array.show_size_of_rows());
		file << rows << " ";
		columns = convert_int_to_string(array.show_size_of_columns());
		file << columns << " ";
		for (int i = 0; i < array.show_size_of_rows(); i++) {
			for (int j = 0; j < array.show_size_of_columns(); j++) {
				data = { 0 };
				file << array.get_element(i, j) << " ";
			}
		}
		file.close();
		std::cout << "Result saved" << std::endl;
	}
	default:;
	}
}