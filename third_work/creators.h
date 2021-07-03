#pragma once

#include "products.h"

/*class Creator {
public:
	virtual ~Creator() = default;
	virtual std::shared_ptr<Product> factory_method() = 0;
	std::shared_ptr<Carray> get_matrix();
};*/

/*class Inputs final {
public:
	Inputs();
	~Inputs() = default;
	std::shared_ptr<Creator> get_input_type(type_of_inputs);
private:
	std::shared_ptr<Creator> manual;
	std::shared_ptr<Creator> random;
	std::shared_ptr<Creator> file;
};*/


/*class CreatorOfManualInput final : public Creator {
public:
	CreatorOfManualInput();
	virtual ~CreatorOfManualInput() = default;
	virtual std::shared_ptr<Product> factory_method() override;
};

class CreatorOfRandomInput final : public Creator {
public:
	CreatorOfRandomInput();
	virtual ~CreatorOfRandomInput() = default;
	virtual std::shared_ptr<Product> factory_method() override;
};

class CreatorOfFileInput final : public Creator {
public:
	CreatorOfFileInput();
	virtual ~CreatorOfFileInput() = default;
	virtual std::shared_ptr<Product> factory_method() override;
};*/