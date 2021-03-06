// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

class list {
private:
	node * head;
	int *arr;
	int tSize;
public:
	list(int s) {
		tSize = s;
		head = 0;
		arr = new int[tSize];
		for (int i = 0; i < tSize; i++) {
			arr[i] = NULL;
		}
	}
	void remove();
	void push_front(int v);
	void del(int v);
	void print();

	int hash(int v);
	int size();
	void createTable();
	int probe(int v);
	void printTable();
};
void list::printTable() {
	for (int i = 0; i < tSize; i++) {
		cout << i << "|  " << arr[i] << endl;
	}
}
void list::createTable() {
	node* cur = head;
	int index = 0;
	while (cur != NULL) {
		cout << cur->val << ' ';
		index = hash(cur->val);
		cout << "at Index: " << index << endl;
		if (arr[index] != NULL) {
			index = probe(cur->val);
			if (index == -2) {
				cout << "Deleting duplicate" << endl;
				del(cur->val);

			}
		}
		if(index >= 0){
			arr[index] = cur->val;
		}
		cur = cur->next;
	}
}
int list::probe(int v) {
	int position  = hash(v);
	int iter = 0;
	int loop = 0;
	cout << "Filled at: "<< position << " with value " << arr[position] << endl;
	if (arr[position] == v)
		return -2;
	while (arr[position] != NULL) {
		if (iter > tSize) {
			iter = -1;
			loop++;
		}
		iter++;
		position = hash(v + iter);
		if(loop > 1){
			return -1;
		}
	}
	cout << "Returning: " << position << endl;
	return position;
}
int list::hash(int v) {
	//tSize = size();
	return v % tSize;
}
int list::size() {
	int c = 0;
	node* cur = head;
	while (cur != NULL) {
		c++;
		cur = cur->next;
	}
	return c;
}
void list::print() {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->val << ' ';
		cur = cur->next;
	}
	cout << endl;
}
void list::push_front(int v) {
	node* tmp = new node;
	tmp->val = v;
	tmp->next = 0;
	if (head == NULL)
		head = tmp;
	else {
		tmp->next = head;
		head = tmp;
	}

}
void list::del(int v) {
	node* cur = head;
	node* trail = new node;
	if (cur->val == v) {
		head = cur->next;
		delete cur;
	}
	else {
		while (cur->val != v) {
			trail = cur;
			cur = cur->next;
		}
		trail->next = cur->next;
		delete cur;
	}
}
void list::remove() {

}

int main()
{
	list * p = new list(5);
	p->push_front(3);
	p->push_front(5);
	p->push_front(7);
	p->push_front(2);
	p->push_front(2);
	cout << "Before: " << endl;
	p->print();
	p->createTable();
	p->printTable();
	cout << "After: " << endl;
	p->print();



	system("pause");
    return 0;
}

