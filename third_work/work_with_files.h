#pragma once

#include "class.h"
#include "input_output.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

enum Errors_with_files {
	fileIsNotExisting,
	fileWithIncorrecData,
};

std::string convert_int_to_string(int n);
void save_in_file(Carray& array);
void save_entered_data_in_file(Carray& array);
std::string get_string_txt(void);
std::unique_ptr<Carray> input_data_from_file(void);
void save_results_in_file(int* compares, int* changes, int sizeOfTest);