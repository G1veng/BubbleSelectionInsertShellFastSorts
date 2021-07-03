#pragma once

#include "class.h"
#include "input_output.h"

class ISort {
public:
	virtual ~ISort() = default;
	virtual int get_compares() const = 0;
	virtual int get_changes() const = 0;
	virtual std::unique_ptr<Carray> copyForSort(const Carray& array) = 0;
protected:
	virtual void sort(Carray* array) = 0;
};

class BubbleSort final : public ISort {
private:
	int changes;
	int compares;
public:
	BubbleSort();
	virtual ~BubbleSort() = default;
	virtual int get_compares() const override;
	virtual int get_changes() const override;
	std::unique_ptr<Carray> copyForSort(const Carray& array) override;
protected:
	virtual void sort(Carray* array) override;
};

class SellectionSort final : public ISort {
private:
	int changes;
	int compares;
public:
	SellectionSort();
	virtual ~SellectionSort() = default;
	virtual int get_compares() const override;
	virtual int get_changes() const override;
	std::unique_ptr<Carray> copyForSort(const Carray& array) override;
protected:
	virtual void sort(Carray* array) override;
};

class InsertSort final : public ISort {
private:
	int changes;
	int compares;
public:
	InsertSort();
	virtual ~InsertSort() = default;
	virtual int get_compares() const override;
	virtual int get_changes() const override;
	std::unique_ptr<Carray> copyForSort(const Carray& array) override;
protected:
	virtual void sort(Carray* array) override;
};

class ShellSort final : public ISort {
private:
	int changes;
	int compares;
public:
	ShellSort();
	virtual ~ShellSort() = default;
	virtual int get_compares() const override;
	virtual int get_changes() const override;
	std::unique_ptr<Carray> copyForSort(const Carray& array) override;
protected:
	virtual void sort(Carray* array) override;
};

class FastSort final : public ISort {
private:
	int left;
	int right;
	int changes;
	int compares;
	int row;
	int nesting;
public:
	FastSort();
	virtual ~FastSort() = default;
	virtual int get_compares() const override;
	virtual int get_changes() const override;
	void set_right_and_left(int outsideLeft, int outsideRight);
	std::unique_ptr<Carray> copyForSort(const Carray& array) override;
protected:
	virtual void sort(Carray* array) override;
};