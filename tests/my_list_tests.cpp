#include "gtest/gtest.h"

#include "my_list/my_list.h"

#include <iostream>
#include <string>

using namespace my_list;

using std::cout, std::string;

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

TEST(SeventhTest, pop_head) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	list1.push_tail(4);
	list1.push_tail(5);
	list1.push_tail(6);
	cout << list1 << '\n';
	auto node = list1.pop_head();
	cout << list1 << '\n';
	ASSERT_TRUE(node->_value == 1);
}

TEST(EighthTest, pop_tail) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	list1.push_tail(4);
	list1.push_tail(5);
	list1.push_tail(6);
	cout << list1 << '\n';
	auto node = list1.pop_tail();
	cout << list1 << '\n';
	ASSERT_TRUE(node->_value == 6);
}

TEST(NinethTest, hanoi_tower) {
	LinkedList<string> l1;
	LinkedList<string> l2;
	LinkedList<string> l3;
	l1.push_tail("   o   ");
	l1.push_tail("  ooo  ");
	l1.push_tail(" ooooo ");
	print_lists(l1, l2, l3);
	hanoi_tower(l1, l2, l3, l1.get_size());//перекидываю с первого на третий
	print_lists(l1, l2, l3);
}

TEST(TenthTest, get_element) {
	LinkedList<int> list1;
	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);
	ASSERT_THROW(list1[3], std::out_of_range);
}

TEST(EleventhTest, pop_tail_two_elem_in_list) {
	LinkedList<int> list;
	list.push_tail(4);
	list.push_tail(5);
	auto element1 = list.pop_tail();
	auto element2 = list.pop_tail();
	ASSERT_TRUE(list.get_size() == 0);
	ASSERT_TRUE(element1->_value == 5);
	ASSERT_TRUE(element2->_value == 4);
}

TEST(TwelfthTest, pop_head_one_elem_in_list) {
	LinkedList<int> list;
	list.push_tail(4);
	auto element = list.pop_head();
	ASSERT_TRUE(list.get_size() == 0);
	ASSERT_TRUE(element->_value == 4);
}

