/*#include "Factory.h"
#include "ISort.h"
#include <iostream>
#include <sstream>

std::shared_ptr<Creator> factory(type_of_inputs userChoice, Inputs input) {
		switch (userChoice) {
		case type_of_inputs::manualInput: {
			std::shared_ptr<Creator>(creator) = input.get_input_type(type_of_inputs::manualInput);
			return creator;
		}
		break;
		case type_of_inputs::randomInput: {
			std::shared_ptr<Creator>(creator) = input.get_input_type(type_of_inputs::randomInput);;
			return creator;
		}
		break;
		case type_of_inputs::fileInput: {
			std::shared_ptr<Creator>(creator) = input.get_input_type(type_of_inputs::fileInput);
			return creator;
		}
		break;
		default:
			std::cout << "Error in dactory" << std::endl;
			exit(0);
		}
}*/