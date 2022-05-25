

// List.h -  Header File


#pragma once

#include <string>
#include <iostream>


// Node class for a Doubly Linked-List node
template<typename Type>
class node {
public:
	Type data;
	node* next;
	node* prev;

	node() {
		// Use this for initializing Head node only		
		next = nullptr;
		prev = nullptr;
		Type dummy_data{};
		this->data = dummy_data;
	}
	node(Type data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
	node(Type data, node* prev_node, node* next_node) {
		this->data = data;
		prev = prev_node;
		next = next_node;
	}
};


// Class that handles the creation/editing of the Doubly Linked-List
template<typename Type>
class List {
public:

	List();										// Constructor

	void push_back(Type data);					// Push an element to the back of the list
	void push_front(Type data);					// Push an element to the front of the list
	Type pop_back();							// Pop an element from the back of the list
	Type pop_front();							// Pop an element from the front of the list

	int size() { return count; }				// Get the size of the list
	bool empty();								// Check if list is empty or not

	Type front();								// Get the value of the first node
	Type rear();								// Get the value of the last node

	Type* to_array();							// Convert the current list to an iteratable array
	friend List<Type>* to_list(Type arr[], size_t size);		// Convert an array into a list

	void Log();									// Display the list
	void Log(std::string arg);					// Display the list along with custom string argument
			
private:
	node<Type>* head;							// Head node of the list
	node<Type>* front_ptr;						// Points to the front-end of the list
	node<Type>* rear_ptr;						// Points to the rear-end of the list
	int count;									// Size of the list

	bool is_head_null(node<Type>* head);		// Checks if head node is null or not
	
};



// TO_LIST function(friend):
template<typename Type>
List<Type>* to_list(Type arr[], size_t size) {
	List<Type>* list = new List<Type>;
	if (size == 0) {
		return list;
	}
	for (size_t i{ 0 }; i < size; i++) {
		list->push_back(arr[i]);
	}
	return list;
}


