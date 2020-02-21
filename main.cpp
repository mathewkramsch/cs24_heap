// main.cpp

#include "heap.h"

int main() {
	heap h;
	h.push(35);
	h.push(45);
	h.print();
	h.pop();
	h.pop();
	h.push(5);
	h.print();
	h.pop();
	h.push(45);
	h.push(35);
	h.push(2);
	h.push(90);
	h.print();
	return 0;
}
