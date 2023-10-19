#pragma once
#include<algorithm>
namespace my_list {
	template<typename T>
	struct Node {
		T _value;
		Node<T>* _next;

		Node(const T& value) : _value(value), _next(nullptr) {}
	};

	template<typename T>
	class LinkedList {
	private:
		Node<T>* _head;

		size_t _size;

		const Node<T>* get_head() const{
			return _head;
		}

		Node<T>*& get_head(){
			return _head;
		}

	public:
		LinkedList() : _head(nullptr), _size(0) {}

		LinkedList(const LinkedList<T>& rhs): _head(nullptr), _size(0) {
			for (size_t i = 0; i < rhs.get_size(); i++)
			{
				this->push_tail(rhs[i]->_value);
			}
		}

		LinkedList& operator=(const LinkedList<T>& rhs) {
			LinkedList<T> copy(rhs);
			swap(copy);
			return *this;
		}

		void swap(LinkedList<T>& rhs) {
			std::swap(_size, rhs.get_size());
			std::swap(_head, rhs.get_head());
		}

		const size_t get_size() const {
			return _size;
		}

		size_t& get_size() {
			return _size;
		}

		Node<T>* operator[](size_t index) const{
			Node<T>* p = _head;
			while (index != 0) {
				p = p->_next;
				--index;
			}
			return p;
		}

		void push_head(const T& value) {
			Node<T>* p = new Node<T>(value);
			p->_next = _head;
			_head = p;
			++_size;
		}

		void push_head(const LinkedList<T>& rhs) {
			LinkedList<int> copy(rhs);
			copy.push_tail(*this);
			swap(copy);
		}

		void pop_head() {
			Node<T>* p = _head;
			_head = p->_next;
			delete p;
			--_size;
		}

		void push_tail(const T& value) {
			Node<T>* p = new Node<T>(value);
			if (_head == nullptr) {
				_head = p;
				++_size;
				return;
			}
			Node<T>* h = _head;
			while (h != nullptr && h->_next != nullptr) {
				h = h->_next;
			}
			h->_next = p;
			++_size;
		}

		void push_tail(const LinkedList<T>& rhs) {
			for (size_t i = 0; i < rhs.get_size(); i++)
			{
				this->push_tail(rhs[i]->_value);
			}
		}

		void pop_tail() {
			Node<T>* h = _head;
			while (h != nullptr && h->_next != nullptr && h->_next->_next != nullptr)//с помощью сайза пойти на предпоследний элемент
			{
				h = h->_next;
			}
			Node<T>* p = h;
			h = h->_next;
			delete h;
			p->_next = nullptr;
			--_size;
		}

		void delete_node(const T del_value) {
			Node<T>* h = _head;
			Node<T>* last_node = nullptr;
			while (h != nullptr) {
				//Node<T>* prev = h;
				if (h->_value == del_value) {
					Node<T>* p = h;
					h = h->_next;
					if (_head->_value == del_value) {
						_head = h;
						last_node = _head;
					}
					delete p;
					p = nullptr;
					--_size;
					if (last_node != nullptr && last_node != h) {
						last_node->_next = h;
					}
				}
				else {
					last_node = h;
					h = h->_next;
				}
			}
		}

		~LinkedList(){
			while (_head != nullptr) {
				Node<T>* p = _head;
				_head = p->_next;
				delete p;
			}
			_size = 0;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, LinkedList<T>& list) {
		for (size_t i = 0; i < list.get_size(); i++)
		{
			os << list[i]->_value << ' ';
		}
		return os;
	}
}