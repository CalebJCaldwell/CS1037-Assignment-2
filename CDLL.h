#pragma once

template <class T>

class CDLL {
private:
	class Node {
	public:
		Node(T v, Node * n = nullptr, Node * l = nullptr):data(v),next(n),last(l){
			data = v;
			next = n;
			last = l;
		}
		T data;
		Node * next;
		Node * last;
	};

public:
	//sets the size of a blank CDLL to 0 and the head & tail pointers to null
	CDLL() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	//iterates through each node and erases its contents 
	~CDLL(){
		for (int i = 0; i < size; i++){
			Node * deleter = head;
			head = head->next; 
			delete deleter;
		}
	}
	//checks if linked list is empty
	bool isEmpty() {
		if (head == nullptr) return 1;
		else return 0;
	}
	//find size of CDLL in terms of elements
	unsigned getSize() {
		return size;
	}
	//creates a new node at the tail of the linked list and adjusts all pointers accordingly
	void addData(T data){
		if (isEmpty()) {
			Node *n = new Node(data);
			head = n;
			tail = n;
			n->next = tail;
			n->last = head;
			size++;
		}
		else {
			Node * m = new Node(data, tail, head);
			tail->next = m;
			m->last = tail;
			tail = m;
			head->last = tail;
			tail->next = head;
			size++;
		}
	}
	//moves head forward one position
	void incrementHead() {
		head = head->next;
	}
	//moves head back one position
	void decrementHead() {
		head = head->last;
	}
	//switches the values stored at src & dst
	void swap(unsigned src, unsigned dst) {

		Node * target1 = head;
		Node * target2 = head;

		T temp = this->operator[](src);

		for (int i = 0; i < src; i++) {
			target1 = target1->next;
		}
		for (int i = 0; i < dst; i++) {
			target2 = target2->next;
		}

		target1->data = this->operator[](dst);
		target2->data = temp;
	}
	//overrides the operator [] so ccdl indices can be accessed using it
	T operator[] (unsigned i) {
		Node * target = head;
		for (int j = 0; j < i; j++)
		{
			target = target->next;
		}
		return target->data;
	}

private:
	Node * head;
	Node * tail;
	unsigned size;

};