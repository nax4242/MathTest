#include "Task.h"

Task::Task() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist_for_numbers(_default_min, _default_max);
	std::uniform_int_distribution<int> dist_for_operation(1, 4);

	_num_1 = dist_for_numbers(gen);
	_num_2 = dist_for_numbers(gen);

	switch (dist_for_operation(gen)) {
	case 1:
		_operation = '+';
		_result = _num_1 + _num_2;
		break;
	case 2:
		_operation = '-';
		_result = _num_1 - _num_2;
		break;
	case 3:
		_operation = '*';
		_result = _num_1 * _num_2;
		break;
	case 4:
		_operation = '/';
		
		while (_num_2 == 0) {
			_num_2 = dist_for_numbers(gen);
		}

		_result = static_cast<double>(_num_1) / _num_2;
		break;
	}
}

Task::Task(int min, int max, char operation) {
	
	if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '?') {
		throw std::invalid_argument("Invalid operation. Must be one of '+', '-', '*', '/' or '?' for random operation.");
	}

	if (min > max) {
		throw std::invalid_argument("Invalid range. Minimum value cannot be greater than maximum value.");
	}

	if (min == 0 && max == 0 && (operation == '/' || operation == '?')) {
		throw std::invalid_argument("Invalid range. Range [min, max] must contain a non-zero value when division is possible.");
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist_for_numbers(min, max);

	_num_1 = dist_for_numbers(gen);
	_num_2 = dist_for_numbers(gen);

	if (operation == '?') {
		std::uniform_int_distribution<int> dist_for_operation(1, 4);

		switch (dist_for_operation(gen)) {
		case 1:
			_operation = '+';
			_result = _num_1 + _num_2;
			break;
		case 2:
			_operation = '-';
			_result = _num_1 - _num_2;
			break;
		case 3:
			_operation = '*';
			_result = _num_1 * _num_2;
			break;
		case 4:
			_operation = '/';

			while (_num_2 == 0) {
				_num_2 = dist_for_numbers(gen);
			}

			_result = static_cast<double>(_num_1) / _num_2;
			break;
		}

	}
	else {

		switch (operation) {
		case '+':
			_operation = '+';
			_result = _num_1 + _num_2;
			break;
		case '-':
			_operation = '-';
			_result = _num_1 - _num_2;
			break;
		case '*':
			_operation = '*';
			_result = _num_1 * _num_2;
			break;
		case '/':
			_operation = '/';

			while (_num_2 == 0) {
				_num_2 = dist_for_numbers(gen);
			}

			_result = static_cast<double>(_num_1) / _num_2;
			break;
		}

	}
}

Task& Task::operator=(const Task& other) {

	if (this == &other) return *this;

	_num_1 = other._num_1;
	_num_2 = other._num_2;
	_operation = other._operation;
	_result = other._result;

	return *this;
}