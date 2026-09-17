#include "MathTest.h"

MathTest::MathTest(int count_of_tasks) {
	_tasks = new Task[count_of_tasks];
	_count_of_tasks = count_of_tasks;
	_user_answers = new double[count_of_tasks];
	_count_of_correct_answers = 0;
}

MathTest::MathTest(int count_of_tasks, int min, int max) {
	_tasks = new Task[count_of_tasks];

	for (int i = 0; i < count_of_tasks; i++) {
		_tasks[i] = Task(min, max);
	}

	_count_of_tasks = count_of_tasks;
	_user_answers = new double[count_of_tasks];
	_count_of_correct_answers = 0;
}

MathTest::MathTest(int count_of_tasks, int min, int max, char operation) {
	_tasks = new Task[count_of_tasks];

	for (int i = 0; i < count_of_tasks; i++) {
		_tasks[i] = Task(min, max, operation);
	}

	_count_of_tasks = count_of_tasks;
	_user_answers = new double[count_of_tasks];
	_count_of_correct_answers = 0;
}

MathTest::~MathTest() {
	delete[]_tasks;
	delete[]_user_answers;
}

void MathTest::run(){
	double user_answer, real_answer;

	std::cout << "===MATH TEST===" << std::endl << "(Input answers rounded to two decimal places)" << std::endl;

	for (int i = 0; i < _count_of_tasks; i++) {
		real_answer = _tasks[i].get_result();

		std::cout << _tasks[i].get_num_1() << " " << _tasks[i].get_operation() << " " << _tasks[i].get_num_2() << " = ";

		std::cin >> user_answer;

		_user_answers[i] = user_answer;

		if (is_correct(user_answer, real_answer)) _count_of_correct_answers++;
	}

	show_statistics();
}

void MathTest::show_statistics() const noexcept{
	double user_answer, real_answer;

	std::cout << "===Result===" << std::endl;

	for (int i = 0; i < _count_of_tasks; i++) {
		user_answer = _user_answers[i];
		real_answer = _tasks[i].get_result();

		std::cout << _tasks[i].get_num_1() << " " << _tasks[i].get_operation() << " " << _tasks[i].get_num_2() << " = " << user_answer;

		if (is_correct(user_answer, real_answer)) {
			std::cout << " (+)" << std::endl;
		}
		else {
			std::cout << " (-) Real answer was " << real_answer << std::endl;
		}
	}

	std::cout << "Result: " << _count_of_correct_answers << "/" << _count_of_tasks << std::endl;
	std::cout << "Mark: ";
	
	int percent_of_correct = calculate_percentage();

	if (percent_of_correct >= _A_grade_percentage) {
		std::cout << "A" << std::endl;
	}
	else if (percent_of_correct >= _B_grade_percentage) {
		std::cout << "B" << std::endl;
	}
	else if (percent_of_correct >= _C_grade_percentage) {
		std::cout << "C" << std::endl;
	}
	else if (percent_of_correct >= _D_grade_percentage) {
		std::cout << "D" << std::endl;
	}
	else {
		std::cout << "F" << std::endl;
	}
}

inline bool MathTest::is_correct(double user_answer, double real_answer) const noexcept {
	return std::abs(user_answer - real_answer) < 1e-6;
}

inline int MathTest::calculate_percentage() const noexcept {
	return static_cast<double>(_count_of_correct_answers) / _count_of_tasks * 100;
}
