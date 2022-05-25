

// List.cpp - Class definition file:


#include "List.h"


// CONSTRUCTOR:
template<typename Type>
List<Type>::List() : count{ 0 } {
	head = new node<Type>();
	front_ptr = head;
	rear_ptr = head;
}


// PUSH_BACK function:
template<typename Type>
void List<Type>::push_back(Type data) {
	if (is_head_null(head)) {
		node<Type>* new_node = new node<Type>(data);
		head = new_node;
		front_ptr = new_node;
		rear_ptr = new_node;
		++count;
		return;
	}
	node<Type>* temp = head;
	while (temp->next != nullptr) { temp = temp->next; }
	node<Type>* new_node = new node<Type>(data, temp, nullptr);
	temp->next = new_node;
	rear_ptr = new_node;
	++count;
}


// POP_BACK function:
template<typename Type>
Type List<Type>::pop_back() {
	if (is_head_null(head)) {
		Type ret_val{};
		front_ptr = head;
		rear_ptr = head;
		return ret_val;
	} else {
		node<Type>* curr = head;
		node<Type>* prev = new node<Type>();		
		while (curr->next != nullptr) {
			prev = curr;
			curr = curr->next;
		}	
		rear_ptr = prev;
		curr->prev = nullptr;
		prev->next = nullptr;
		Type ret_val = curr->data;
		delete curr;
		--count;
		return ret_val;
	}
}


// POP_FRONT function:
template<typename Type>
Type List<Type>::pop_front() {
	if (is_head_null(head)) {
		front_ptr = head;
		rear_ptr = head;
		Type ret_val{};
		return ret_val;
	} else {
		node<Type>* front_node = head;
		node<Type>* next_node = front_node->next;
		Type data_val = front_node->data;
		head = next_node;
		front_ptr = head;
		next_node->prev = nullptr;
		delete front_node;
		--count;
		return data_val;
	}
}


// PUSH_FRONT function:
template<typename Type>
void List<Type>::push_front(Type data) {
	if (is_head_null(head)) {
		push_back(data);
		return;
	}
	node<Type>* temp = head;
	node<Type>* new_node = new node<Type>(data, nullptr, temp);
	temp->prev = new_node;
	head = new_node;
	front_ptr = head;
	++count;
}


// EMPTY function:
template<typename Type>
bool List<Type>::empty() {
	if (count == 0)
		return true;
	return false;
}



// FRONT function:
template<typename Type>
Type List<Type>::front() {
	if (front_ptr != nullptr)
		return front_ptr->data;
	Type ret_val{};
	return ret_val;
}



// REAR function:
template<typename Type>
Type List<Type>::rear() {
	if (rear_ptr != nullptr)
		return rear_ptr->data;
	Type ret_val{};
	return ret_val;
}


// TO_ARRAY function:
template<typename Type>
Type* List<Type>::to_array() {
	if (is_head_null(head)) {
		Type* arr = new Type[1]{};
		return arr;
	}
	int size{ this->count };
	Type* arr = new Type[size]{};
	node<Type>* temp = head;
	int i{ 0 };
	while (temp != nullptr && i < size) {
		arr[i] = temp->data;
		temp = temp->next;
		++i;
	}
	return arr;
}




// LOG function (with custom string):
template<typename Type>
void List<Type>::Log(std::string arg) {
	if (is_head_null(head)) {
		std::cout << "\n List is empty" << std::endl;
		return;
	}
	std::cout << "\n List [" << this->count << "]: ";
	node<Type>* temp = this->head;
	while (temp->next != nullptr) {
		std::cout << temp->data << "  ";
		temp = temp->next;
	}
	std::cout << temp->data << std::endl;
	std::cout << " " << arg << std::endl;
}


// LOG function:
template<typename Type>
void List<Type>::Log() {
	if (is_head_null(head)) {
		std::cout << "\n List is empty" << std::endl;
		return;
	}
	std::cout << "\n List [" << this->count << "]: ";
	node<Type>* temp = this->head;
	while (temp->next != nullptr) {
		std::cout << temp->data << "  ";
		temp = temp->next;
	}
	std::cout << temp->data << std::endl;
}



// private: IS_HEAD_NULL function
template<typename Type>
bool List<Type>::is_head_null(node<Type>* head) {		
	if (count == 0 && head->next == nullptr && head->prev == nullptr)
		return true;
	return false;
}



// LINKER_RESOLVE: ============ This function never gets called //
void LinkerResolve() {
	// Integer link-resolves:
	List<int> int_list;
	int_list.push_back(1);
	int_list.pop_front();
	int_list.Log();
	int_list.Log("test");
	int_list.push_front(1);
	int_list.pop_back();
	int_list.size();
	int_list.empty();
	int_list.front();
	int_list.rear();
	int_list.to_array();
	int arr_i[1]{};
	List<int>* li = to_list(arr_i, 1);

	// Character link-resolves:
	List<char> char_list;
	char_list.push_back('c');
	char_list.pop_front();
	char_list.Log();
	char_list.Log("test");
	char_list.push_front('c');
	char_list.pop_back();
	char_list.size();
	char_list.empty();
	char_list.front();
	char_list.rear();
	char_list.to_array();
	char arr_c[1]{ 'c' };
	List<char>* lc = to_list(arr_c, 1);

	// Float link-resolves:
	List<float> float_list;
	float_list.push_back(1.0f);
	float_list.pop_front();
	float_list.Log();
	float_list.Log("test");
	float_list.push_front(1.0);
	float_list.pop_back();
	float_list.size();
	float_list.empty();
	float_list.front();
	float_list.rear();
	float_list.to_array();
	float arr_f[1]{ 0 };
	List<float>* lf = to_list(arr_f, 1);

	// Double link-resolves:
	List<double> double_list;
	double_list.push_back(1.0);
	double_list.pop_front();
	double_list.Log();
	double_list.Log("test");
	double_list.push_front(1.0);
	double_list.pop_back();
	double_list.size();
	double_list.empty();
	double_list.front();
	double_list.rear();
	double_list.to_array();
	double arr_d[1]{ 0.0 };
	List<double>* ld = to_list(arr_d, 1);
}