// heap.cpp

#include "heap.h"

void heap::push(int value) {
	v.push_back(value);
	int currentindex = get_index(value);
	int parentindex = (currentindex-1)/2;
	int tmpparentval;
	
	while (v[parentindex] < v[currentindex]) {
		tmpparentval = v[parentindex];
		v[parentindex] = v[currentindex];
		v[currentindex] = tmpparentval;
		currentindex = parentindex;
		parentindex = (currentindex-1)/2;
	}
}
int heap::get_index(int value) {
	int index;
	for (int i=0; i<v.size(); i++) {
		if (v[i] == value)
			index = i;
	}
	return index;
}

void heap::pop() {
	if (this->empty())
		return;
	int deletedindex = v.size()-1;
	v[0] = v[deletedindex];
	v.pop_back();

	// if vector is now one element/empty
	if (deletedindex <= 1)
		return;
	
	int currentindex = 0;
	int childindex = 1;
	int tmp;
	
	if (!deletedindex == 1) {   // if vector is more than 2 elements
		if (v[1] > v[2])
			childindex = 2;
	}

	while (childindex < deletedindex && v[childindex] > v[currentindex]) {
		tmp = v[currentindex];
		v[currentindex] = v[childindex];
		v[childindex] = tmp;
		currentindex = childindex;
		childindex = 2*currentindex +1;
		if (childindex < deletedindex+1) {
			if (v[childindex] > v[childindex+1])
				childindex++;
		}
	}
}

int heap::top() {
	if (v.size() != 0)
		return v[0];
	else
		return 0;
}

bool heap::empty() {
	if (v.size() == 0)
		return true;
	return false;
}

void heap::print() {
	for (int i=0; i<v.size(); i++)
		cout << i << "=" << v[i] << ", ";
	cout << endl;
}	
