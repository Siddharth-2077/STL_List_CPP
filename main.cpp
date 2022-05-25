

// DRIVER CODE:


#include "List.h"
#include <iostream>
using namespace std;


// PRINT_ARRAY function prototype:
template<typename Type>
void PrintArray(Type[], int);


int main() {

	List<int> li;
	int* arr = nullptr;

	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.Log("This is an integer list");
	auto pop_i = li.pop_front();
	li.Log("Popped the front node");
	cout << " front value was: " << pop_i << endl;
	li.push_front(10);
	li.Log();
	pop_i = li.pop_back();
	li.Log("Popped the rear node");
	cout << " rear value was: " << pop_i << endl;	

	// The to_array() function: [Converts the list to an iteratable array]
	arr = li.to_array();
	PrintArray(arr, li.size());

	// The to_list() function: [Converts an array to a list]
	int arr_1[] = { 100 , 200, 300, 400, 500 };
	List<int>* int_list = to_list(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
	int_list->Log();


	cout << "\n\n\n";
	/*
	List<char> lc;
	lc.push_back('c');
	lc.push_back('h');
	lc.push_back('a');
	lc.push_back('r');
	lc.Log("This is a character list");
	auto pop_c = lc.pop_front();
	lc.Log("Popped the front node");
	cout << " front value was: " << pop_c << endl;
	pop_c = lc.pop_back();
	lc.Log("Popped the rear node");
	cout << " rear value was: " << pop_c << endl;

	cout << "\n\n\n";

	List<float> lf;
	lf.push_back(1);
	lf.push_back(2.2f);
	lf.push_back(10.5f);
	lf.Log("This is a float list");
	auto pop_f = lf.pop_front();
	lf.Log("Popped the front node");
	cout << " front value was: " << pop_f << endl;
	pop_f = lf.pop_back();
	lf.Log("Popped the rear node");
	cout << " rear value was: " << pop_f << endl;

	cout << "\n\n\n";

	List<double> ld;
	ld.push_back(1.09728);
	ld.push_back(3.93478);
	ld.push_back(100.29832);
	ld.Log("This is a double list");
	auto pop_d = ld.pop_front();
	ld.Log("Popped the front node");
	cout << " front value was: " << pop_d << endl;
	pop_d = ld.pop_back();
	ld.Log("Popped the rear node");
	cout << " rear value was: " << pop_d << endl;
	*/
	
	return 0;
}



// PRINT_ARRAY function definition:
template<typename Type>
void PrintArray(Type arr[], int size) {
	std::cout << "\n Array [" << size << "]:  { ";
	for (int i{ 0 }; i < size - 1; i++) {
		std::cout << arr[i] << " , ";
	}
	std::cout << arr[size - 1] << " }" << endl;
}