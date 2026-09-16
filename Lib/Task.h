#pragma once
#include <random>
#include <stdexcept>

struct Task {
private:
	const int _default_min = 1;
	const int _default_max = 100;

	int _num_1;
	int _num_2;
	char _operation;
	double _result;

public:
	Task();
	Task(int min, int max, char operation = '?');

	inline int get_num_1() const noexcept;
	inline int get_num_2() const noexcept;
	inline char get_operation() const noexcept;
	inline double get_result() const noexcept;

	Task& operator=(const Task& other);
};

inline int Task::get_num_1() const noexcept {
	return _num_1;
}

inline int Task::get_num_2() const noexcept {
	return _num_2;
}

inline char Task::get_operation() const noexcept {
	return _operation;
}

inline double Task::get_result() const noexcept {
	return _result;
}