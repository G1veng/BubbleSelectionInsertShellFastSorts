/*#include "creators.h"

CreatorOfManualInput::CreatorOfManualInput() {}
CreatorOfFileInput::CreatorOfFileInput() {}
CreatorOfRandomInput::CreatorOfRandomInput() {}
Inputs::Inputs() {}

std::shared_ptr<Product> CreatorOfManualInput::factory_method() {
	Product* product = new MatrixFromConsoleInput();
	return std::shared_ptr<Product>(product);
}

std::shared_ptr< Product> CreatorOfFileInput::factory_method() {
	Product* product = new MatrixFromFileInput();
	return std::shared_ptr<Product>(product);
}

std::shared_ptr<Product> CreatorOfRandomInput::factory_method() {
	Product* product = new MatrixFromRandomInput();
	return std::shared_ptr<Product>(product);
}

std::shared_ptr<Carray> Creator::get_matrix() {
	std::shared_ptr<Product> product = this->factory_method();
	std::shared_ptr<Carray> array = product->get_input();
	return array;
}

std::shared_ptr <Creator> Inputs::get_input_type(type_of_inputs input) {
	switch (input) {
	case type_of_inputs::manualInput: {
		if (manual == nullptr)
			manual = std::make_shared<CreatorOfManualInput>(CreatorOfManualInput());
		return manual;
	}
	case type_of_inputs::randomInput: {
		if (random == nullptr)
			random = std::make_shared<CreatorOfRandomInput>(CreatorOfRandomInput());
		return random;
	}
	case type_of_inputs::fileInput: {
		if (file == nullptr)
			file = std::make_shared<CreatorOfFileInput>(CreatorOfFileInput());
		return file;
	}
	default:
		std::cout << "Error in creator_of_main_inputs" << std::endl;
		exit(0);
	}
}*/