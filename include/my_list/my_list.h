#pragma once

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
	public:
		LinkedList() : _head(nullptr), _size(0) {}

		size_t get_size() const {
			return _size;
		}

		Node<T>* operator[](size_t index) {
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

		void pop_head() {
			Node<T>* p = _head;
			_head = p->_next;
			delete p;
			--_size;
		}

		void push_tail(const T& value) {
			Node<T>* p = new Node<T>(value);
			Node<T>* h = _head;
			while (h != nullptr && h->_next != nullptr) {
				h = h->_next;
			}
			h->_next = p;
			++_size;
		}

		void pop_tail() {
			Node<T>* h = _head;
			while (h != nullptr && h->_next != nullptr && h->_next->_next != nullptr)
			{
				h = h->_next;
			}
			Node<T>* p = h;
			h = h->_next;
			delete h;
			p->_next = nullptr;
			--_size;
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