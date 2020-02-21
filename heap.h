// heap.h

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
using namespace std;

class heap {
	public:
		void push(int value);
		void pop();
		int top();
		bool empty();
		void print();
	private:
		vector<int> v;

		int get_index(int value);
};

#endif
