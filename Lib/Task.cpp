#include "Task.h"
#include <random>

Task::Task() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist_for_numbers;
	std::uniform_int_distribution<int> dist_for_operation;

	_first_number = dist_for_numbers(gen);
	_second_number = dist_for_numbers(gen);

	if (std::abs(_second_number) < 1e-9) dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 3));
	else dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 4));

	switch (dist_for_operation(gen)) {
	case 1:
		_operation = '+';
		_result = _first_number + _second_number;
		break;
	case 2:
		_operation = '-';
		_result = _first_number - _second_number;
		break;
	case 3:
		_operation = '*';
		_result = _first_number * _second_number;
		break;
	case 4:
		_operation = '/';
		_result = _first_number / _second_number;
		break;
	}
}

Task::Task(double bot_of_diaposone, double top_of_diaposone, char operation = '?') {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist_for_numbers(bot_of_diaposone, top_of_diaposone);

	_first_number = dist_for_numbers(gen);
	_second_number = dist_for_numbers(gen);

	std::uniform_int_distribution<int> dist_for_operation;
	if (std::abs(_second_number) < 1e-9) dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 3));
	else dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 4));

	switch (operation) {
	case '+':
		_result = _first_number + _second_number;
		break;
	case '-':
		_result = _first_number - _second_number;
		break;
	case '*':
		_result = _first_number * _second_number;
		break;
	case '/':
		_result = _first_number / _second_number;
		break;
	default:
		std::uniform_int_distribution<int> dist_for_operation;
		if (std::abs(_second_number) < 1e-9) dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 3));
		else dist_for_operation.param(std::uniform_int_distribution<int>::param_type(1, 4));
	}
}