#include "gtest/gtest.h"

#include "my_list/my_list.h"

#include <iostream>

using namespace my_list;

using std::cout;

TEST(FirstTest, Creating) {
	LinkedList<int> list;
	list.push_tail(4);
	list.push_tail(5);
	list.push_tail(6);
	ASSERT_TRUE(list.get_size() == 3);
	std::cout << list << '\n';
}

TEST(SecondTest, Copy) {
	LinkedList<int> list;
	list.push_head(1);
	list.push_head(2);
	list.push_head(3);
	list.push_tail(4);
	list.push_tail(5);
	list.push_tail(6);
	LinkedList<int> copy_list(list);
	ASSERT_TRUE(copy_list.get_size() == 6);
	cout << copy_list << '\n';
}

TEST(ThirdTest, assign) {
	LinkedList<int> list1;
	list1.push_head(1);
	list1.push_head(2);
	list1.push_head(3);
	LinkedList<int> list2;
	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_tail(6);
	list2 = list1;
	ASSERT_TRUE(list2.get_size() == 3);
	cout << list2<< '\n';
}

TEST(FourthTest, push_tail_list) {
	LinkedList<int> list1;
	list1.push_head(1);
	list1.push_head(2);
	list1.push_head(3);
	LinkedList<int> list2;
	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_tail(6);
	list1.push_tail(list2);
	ASSERT_TRUE(list1.get_size() == 6);
	cout << list1 << '\n';
}

TEST(FifthTest, push_head_list) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	LinkedList<int> list2;
	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_tail(6);
	list2.push_head(list1);
	ASSERT_TRUE(list2.get_size() == 6);
	cout << list2 << '\n';
}

TEST(SixthTest, delete_node) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	list1.push_tail(4);
	list1.push_tail(1);
	list1.push_tail(1);

	cout << list1 << '\n';
	ASSERT_TRUE(list1.get_size() == 7);
	
	list1.delete_node(1);

	cout << list1 << '\n';
	ASSERT_TRUE(list1.get_size() == 3);
}
