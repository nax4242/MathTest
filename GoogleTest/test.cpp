#include "pch.h"
#include "Task.h"

TEST(TaskTests, DefaultConstructorTest) {
	Task t;

	EXPECT_TRUE(t.get_num_1() >= 1 && t.get_num_2() <= 100 && t.get_num_2() >= 1 && t.get_num_2() <= 100);
	EXPECT_TRUE(t.get_operation() == '+' || t.get_operation() == '-' || t.get_operation() == '*' || t.get_operation() == '/');
}

TEST(TaskTests, InitConstructorTestWithPlus) {
	Task t(100, 200, '+');

	EXPECT_TRUE(t.get_num_1() >= 100 && t.get_num_2() <= 200 && t.get_num_2() >= 100 && t.get_num_2() <= 200);
	EXPECT_TRUE(t.get_operation() == '+');
	EXPECT_TRUE(t.get_result() == t.get_num_1() + t.get_num_2());
}

TEST(TaskTests, InitConstructorTestWithMinus) {
	Task t(100, 200, '-');

	EXPECT_TRUE(t.get_num_1() >= 100 && t.get_num_2() <= 200 && t.get_num_2() >= 100 && t.get_num_2() <= 200);
	EXPECT_TRUE(t.get_operation() == '-');
	EXPECT_TRUE(t.get_result() == t.get_num_1() - t.get_num_2());
}

TEST(TaskTests, InitConstructorTestWithMultiple) {
	Task t(100, 200, '*');

	EXPECT_TRUE(t.get_num_1() >= 100 && t.get_num_2() <= 200 && t.get_num_2() >= 100 && t.get_num_2() <= 200);
	EXPECT_TRUE(t.get_operation() == '*');
	EXPECT_TRUE(t.get_result() == t.get_num_1() * t.get_num_2());
}

TEST(TaskTests, InitConstructorTestWithDivision) {
	Task t(100, 200, '/');

	EXPECT_TRUE(t.get_num_1() >= 100 && t.get_num_2() <= 200 && t.get_num_2() >= 100 && t.get_num_2() <= 200);
	EXPECT_TRUE(t.get_operation() == '/');
	EXPECT_TRUE(t.get_result() == static_cast<double>(t.get_num_1()) / t.get_num_2());
}

TEST(TaskTests, InitConstructorTestThrowInvalidOperation) {
	EXPECT_THROW(Task(100, 200, '2'), std::invalid_argument);
}

TEST(TaskTests, InitConstructorTestThrowInvalidRange) {
	EXPECT_THROW(Task(200, 100, '+'), std::invalid_argument);
}

TEST(TaskTests, InitConstructorTestThrowZeroOnlyRangeWIthDivision1) {
	EXPECT_THROW(Task(0, 0, '/'), std::invalid_argument);
}

TEST(TaskTests, InitConstructorTestThrowZeroOnlyRangeWIthDivision2) {
	EXPECT_THROW(Task(0, 0, '?'), std::invalid_argument);
}

TEST(TaskTests, ResultMatchesOperationWithDefaultConstructor) {

	for (int i = 0; i < 500; i++) {
		Task t;
		int n1 = t.get_num_1();
		int n2 = t.get_num_2();

		switch (t.get_operation()) {
		case '+':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 + n2);
			break;
		case '-':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 - n2);
			break;
		case '*':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 * n2);
			break;
		case '/':
			ASSERT_NE(n2, 0);
			EXPECT_DOUBLE_EQ(t.get_result(), static_cast<double>(n1) / n2);
			break;
		}
	}

}

TEST(TaskTests, ResultMatchesOperationWithInitConstructor) {

	for (int i = 0; i < 500; i++) {
		Task t(-100, 100);
		int n1 = t.get_num_1();
		int n2 = t.get_num_2();

		switch (t.get_operation()) {
		case '+':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 + n2);
			break;
		case '-':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 - n2);
			break;
		case '*':
			EXPECT_DOUBLE_EQ(t.get_result(), n1 * n2);
			break;
		case '/':
			ASSERT_NE(n2, 0);
			EXPECT_DOUBLE_EQ(t.get_result(), static_cast<double>(n1) / n2);
			break;
		}
	}

}

TEST(TaskTests, DefaultArgumentIsRandom) {
	Task t(1, 50);
	char op = t.get_operation();
	EXPECT_TRUE(op == '+' || op == '-' || op == '*' || op == '/');
}
