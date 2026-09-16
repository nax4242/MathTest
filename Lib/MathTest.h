#pragma once
#include "Task.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

class MathTest {
	static constexpr int _A_grade_percentage = 90;
	static constexpr int _B_grade_percentage = 75;
	static constexpr int _C_grade_percentage = 50;
	static constexpr int _D_grade_percentage = 35;

	Task* _tasks;
	int _count_of_tasks;
	double* _user_answers;
	int _count_of_correct_answers;

public:
	MathTest(int count_of_tasks);
	MathTest(int count_of_tasks, int min, int max);
	MathTest(int count_of_tasks, int min, int max, char operation);

	~MathTest();

	void run();
	void show_statistics() const noexcept;

private:
	inline bool is_correct(double user_answer, double real_answer) const noexcept;
	inline int calculate_percentage() const noexcept;
};