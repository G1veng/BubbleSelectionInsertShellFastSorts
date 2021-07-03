#pragma once

#include "class.h"
#include <memory>
#include "input_output.h"
#include "work_with_files.h"
#include <time.h>
#include <cstdlib>

const int COUNT_OF_SORTS = 5;
const int RAND_MINIMUM_FOR_NUMBERS = -500;
const int RAND_MAXIMUM_FOR_NUMBERS = 1000;
const int RAND_FOR_SIZE_OF_ARRAY = 5;
const int NUMBERS_AFTER_DOT = 3;
const int NUMBERS_AFTER_DOT_IN_RANDOM_GENERATION = 1000;

enum class type_of_inputs {
	mainFunction,
	manualInput,
	randomInput,
	fileInput,
	testOfProgram
};

int get_sum_of_number(double number);
void get_sum_of_elements(Carray* array);

class Product {
public:
	virtual ~Product() = default;
	virtual std::unique_ptr<Carray> get_input() = 0;
};

class MatrixFromConsoleInput final : public Product {
public:
	virtual ~MatrixFromConsoleInput() = default;
	MatrixFromConsoleInput() = default;
	std::unique_ptr<Carray> get_input() override;
};

class MatrixFromFileInput final : public Product {
public:
	virtual ~MatrixFromFileInput() = default;
	MatrixFromFileInput() = default;
	std::unique_ptr<Carray> get_input() override;
};

class MatrixFromRandomInput final : public Product {
public:
	virtual ~MatrixFromRandomInput() = default;
	MatrixFromRandomInput() = default;
	std::unique_ptr<Carray> get_input() override;
};

class Container final {
public:
	Container() = default;
	~Container() = default;
	std::shared_ptr<Product> get_input_type(type_of_inputs input);
private:
	std::shared_ptr<Product> manual;
	std::shared_ptr<Product> random;
	std::shared_ptr<Product> file;
};