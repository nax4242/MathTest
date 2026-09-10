#pragma once

struct Task {
private:
	double _first_number;
	double _second_number;
	char _operation;
	double _result;

public:
	Task();
	Task(double bot_of_diaposone, double top_of_diaposone, char operation = '+');
};