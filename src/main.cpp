#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
	string str;
	vector<int> vec({});

	/**/
	for (auto& i : vec)
		++i;

	for (auto i : vec)
		std::cout << i << " ";
	/**/


	/**
	for (int i = 0; i < 3; ++i)
		vec.pop_back();
	std::cout << vec.size() << " " << vec.capacity();
	/**/

	/**/
	int size;
	std::cout << "Please enter your amount of inputs: ";
	std::cin >> size;

	for (int i = 0; i < size; ++i) {
		std::cout << "Please enter a number: ";
		int input;
		std::cin >> input;
		vec.push_back(input);
	}

	for (auto i : vec)
		std::cout << i << " ";
	/**/

	return EXIT_SUCCESS;
}

struct Node {
	int _val;
	Node* _next, *_prev;
};
void func(const void* ptr, const void* (*nextVal)(const void*), bool (*cond)(const void*), void(*print)(const void*)) {
	for (const void* i = ptr; i != nullptr; i = nextVal(i)) {
		if (cond(i)) {
			print(i);
			return;
		}
	}
}

const void* nextNode(const void* ptr) {
	if(ptr != nullptr)
		return ((Node*)ptr)->_next;
	return nullptr;
}