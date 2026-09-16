#pragma once
#include "Task.h"

class MathTest {
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
};