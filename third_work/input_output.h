#pragma once

#include "class.h"
#include <string>
#include <iostream>
#include <limits>
#include <ios>
#include "ISort.h"

enum class Save_in_file {
	save_int_file,
	output_in_console
};

const int CHAR_NINE = 57;
const int CHAR_ZERO = 48;
const int CHAR_MINUS = 45;
const int CHAR_DOT = 46;

bool end_the_program(void);
void output_matrix(Carray& array);
bool is_string_only_digits(std::string someString);
int input_digit(void);
std::string out_put_information(int i);
void out_put_results(int* changes, int* compares, int sizeOfTests);
void out_put_information_text(int i);
double get_double(void);