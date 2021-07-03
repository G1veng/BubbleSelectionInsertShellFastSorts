#include "input_output.h"
#include "factory.h"
#include "test.h"

int main(void) {
	std::cout << "Welcome. Laborator work number 3, option 6, by student of 403 group: Shishko Daniil Yerevich" << std::endl;
	std::cout << "Aim of program: sort rows by decreasing sum of values of digits in rows" << std::endl;
	Container typesOfInputs;
	do {
		std::cout << "1 - to console input" << std::endl;
		std::cout << "2 - to random input" << std::endl;
		std::cout << "3 - to file input" << std::endl;
		std::cout << "4 - to test" << std::endl;
		type_of_inputs userChoice = static_cast<type_of_inputs>(input_digit());
		if (userChoice < type_of_inputs::testOfProgram && userChoice > type_of_inputs::mainFunction) {
			std::unique_ptr<Carray> array = typesOfInputs.get_input_type(userChoice)->get_input();
			std::unique_ptr<ISort> sorts[COUNT_OF_SORTS] = {
			std::make_unique<BubbleSort>(BubbleSort()),
			std::make_unique<SellectionSort>(SellectionSort()),
			std::make_unique<InsertSort>(InsertSort()),
			std::make_unique<ShellSort>(ShellSort()),
			std::make_unique<FastSort>(FastSort())
			};
			int changes[COUNT_OF_SORTS] = { 0 };
			int compares[COUNT_OF_SORTS] = { 0 };
			for (int i = 0; i < COUNT_OF_SORTS; i++) {
				auto sortedArray = sorts[i]->copyForSort(*array);
				out_put_information_text(i);
				output_matrix(*sortedArray);
				changes[i] = sorts[i]->get_changes();
				compares[i] = sorts[i]->get_compares();
			}
			out_put_results(changes, compares, COUNT_OF_SORTS);
			save_results_in_file(compares, changes, COUNT_OF_SORTS);
		}
		if (userChoice == type_of_inputs::testOfProgram) {
			test();
		}
		if(userChoice > type_of_inputs::testOfProgram || userChoice < type_of_inputs::mainFunction) {
			std::cout << "Wrong enter" << std::endl;
		}
		std::cout << "Enter 1 to repeat program" << std::endl;
		std::cout << "Enter 0 to end program" << std::endl;
	} while (input_digit());
	return 0;
}