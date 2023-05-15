#pragma once
#include <iostream>

using namespace std;

struct Node {
	string data;
	struct Node* next;
};

class MainMenu {
private:
	struct Node* my_head;
	string prase;
	int count_item;

public:
	// ��� ������� ��������
	MainMenu(string phrase) {
		count_item = 0;
		addItem(phrase);
	}

	// ������� ������
	~MainMenu() {
		struct Node* old = NULL;
		struct Node* current = my_head;
		while (current != NULL) {
			old = current;
			current = current->next;
			delete old;
		}
	}

	// ��������� ������� � ������
	void addItem(string inp_data) {
		struct Node* new_item = new Node;
		new_item->data = inp_data;
		if (count_item == 0) { new_item->next = NULL; }
		else { new_item->next = my_head; }
		my_head = new_item;
		count_item++;
	}

	// ��������� ������� � �����
	void insertItem(int index, string inp_data) {
		if (index < count_item || count_item < 0) { return; }
		else if (index == 0) { addItem(inp_data); }
		else {
			struct Node* current = my_head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			struct Node* new_item = new Node();
			new_item->data = inp_data;
			new_item->next = current->next;
			current->next = new_item;
			count_item++;
		}
	}

	// �������� ������� insertItem � �������� ��, ������� ��������� ��� ���������
	void push_back(string inp_data) {
		insertItem(count_item, inp_data);
	}

	// ����� ���������
	void printItem() {
		struct Node* current = my_head;
		int i = 0;
		while (current != NULL) {
			if (i != 0 && i != count_item - 1) { cout << i << ". "; }
			cout << current->data;
			if (i != count_item - 1) { cout << "\n"; }
			i++;
			current = current->next;
		}
	}
};