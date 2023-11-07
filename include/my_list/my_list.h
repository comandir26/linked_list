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

		const Node<T>* operator[](size_t index) const{
			if (index < 0 || index >= _size) {
				throw std::out_of_range("LinkedList::operator[], index is out of range");
			}
			Node<T>* p = _head;
			while (index != 0) {
				p = p->_next;
				--index;
			}
			return p;
		}

		Node<T>* operator[](size_t index){
			if (index < 0 || index >= _size) {
				throw std::out_of_range("LinkedList::operator[], index is out of range");
			}
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

		Node<T>* pop_head() {
			if (_size == 0) {
				return nullptr;
			}
			Node<T>* p = _head;
			_head = p->_next;
			--_size;
			return p;
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

		Node<T>* pop_tail() {
			if (_size == 0) {
				return nullptr;
			}
			Node<T>* h = _head;
			while (h != nullptr && h->_next != nullptr && h->_next->_next != nullptr)//с помощью сайза пойти на предпоследний элемент
			{
				h = h->_next;
			}
			Node<T>* p = h;
			if (_size != 1) {
				p = p->_next;
			}
			h->_next = nullptr;
			--_size;
			return p;
		}

		void delete_node(const T del_value) {
			Node<T>* h = _head;
			Node<T>* last_node = nullptr;
			while (h != nullptr) {
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
			os << list[i]->_value << '\n';
		}
		if (list.get_size() == 0) {
			os << '\n';
			os << "--------";
			os << '\n';
		}
		os << '\n';
		return os;
	}

	template<typename T>
	void print_lists(LinkedList<T>& l1, LinkedList<T>& l2, LinkedList<T>& l3) {
		std::cout << l1;
		std::cout << l2;
		std::cout << l3;
		std::cout << "One disk moved\n";
	}
	
	template<typename T>
	void move(LinkedList<T>& from, LinkedList<T>& dst) {
		Node<T>* from_top = from.pop_head();
		if (from_top != nullptr) {
			dst.push_head(from_top->_value);
		}
	}
	
	template<typename T>
	void hanoi_tower(LinkedList<T>& from, LinkedList<T>& temp, LinkedList<T>& dst, size_t tower_height) {
		if (tower_height > 0) {
			hanoi_tower(from, dst, temp, tower_height - 1);
			move(from, dst);
			print_lists(from, dst, temp);
			hanoi_tower(temp, from, dst, tower_height - 1);
		}
	}
}