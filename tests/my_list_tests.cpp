#include "gtest/gtest.h"

#include "my_list/my_list.h"

#include <iostream>

using namespace my_list;

TEST(SecondTest, Creating) {
	LinkedList<int> list;
	list.push_head(1);
	list.push_head(2);
	list.push_head(3);
	list.push_tail(4);
	list.push_tail(5);
	list.push_tail(6);
	ASSERT_TRUE(list.get_size() == 6);
	std::cout << list << '\n';
	list.pop_head();
	list.pop_tail();
	ASSERT_TRUE(list.get_size() == 4);
	std::cout << list << '\n';
}
