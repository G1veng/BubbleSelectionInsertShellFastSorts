#include "test.h"

void test(void) {
	std::string buffer = { 0 };
	int countOfErrors = 0, sizeOfRows = 0, sizeOfColumns = 0;
	std::ifstream file("test.txt", std::ios_base::in);
	for (int i = 0; i < SIZE_OF_TEST; ++i) {
		file >> buffer;
		sizeOfRows = std::stoi(buffer);
		if (sizeOfRows <= 0) {
			file >> buffer;
			continue;
		}
		file >> buffer;
		sizeOfColumns = std::stoi(buffer);
		if (sizeOfColumns <= 0) {
			continue;
		}
		Carray* item = new Carray(sizeOfRows, sizeOfColumns);
		Carray* correctItem = new Carray(sizeOfRows, sizeOfColumns);
		for (int j = 0; j < sizeOfRows; ++j) {
			for (int k = 0; k < sizeOfColumns; k++) {
				file >> buffer;
				item->set_elem_of_matrix(j, k, stod(buffer));
				get_sum_of_elements(item);
			}
		}
		for (int j = 0; j < sizeOfRows; ++j) {
			for (int k = 0; k < sizeOfColumns; k++) {
				file >> buffer;
				correctItem->set_elem_of_matrix(j, k, stod(buffer));
				get_sum_of_elements(correctItem);
			}
		}
		std::unique_ptr<Carray> newItem(item);
		std::unique_ptr<Carray> newCorrectItem(correctItem);
		std::unique_ptr<ISort> sorts[COUNT_OF_SORTS] = {
			std::make_unique<BubbleSort>(),
			std::make_unique<SellectionSort>(),
			std::make_unique<InsertSort>(),
			std::make_unique<ShellSort>(),
			std::make_unique<FastSort>()
		};
		for (int j = 0; j < COUNT_OF_SORTS; j++) {
			auto sortedArray = sorts[j]->copyForSort(*item);
			for (int k = 0; k < sizeOfRows; ++k) {
				for (int m = 0; m < sizeOfColumns; m++) {
					if (sortedArray->get_element(k, m) != correctItem->get_element(k, m)) {
						std::cout << "Error in " << i + 1 << " test in ";
						out_put_information_text(j);
						std::cout << sortedArray->get_element(k, m) << std::endl;
						countOfErrors++;
					}
				}
			}
		}
	}
	if (countOfErrors == 0)
		std::cout << "All tests are succeded" << std::endl;
}