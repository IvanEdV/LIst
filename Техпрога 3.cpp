#include <iostream>
using namespace std;
struct Node {
	int num;
	Node* Next = NULL;
	Node* Prew = NULL;
};

struct List {
	Node* First = NULL;
	Node* Last = NULL;
	int count = 0;
};

void up(List& list, int newnum) {
	Node* newnode = new Node;
	newnode->num = newnum;
	newnode->Next = list.First;
	if (list.First != NULL) {
		list.First->Prew = newnode;
	}
	if (list.Last == NULL) {
		list.Last = newnode;
	}
	list.First = newnode;
	list.count += 1;
}

void back(List& list, int newnum) {
	Node* newnode = new Node;
	newnode->num = newnum;
	newnode->Prew = list.Last;
	if (list.Last != NULL) {
		list.Last->Next = newnode;
	}
	if (list.First == NULL) {
		list.First = newnode;
	}
	list.Last = newnode;
	list.count += 1;
}

void print(List& list) {
	Node* temp = list.First;
	while (temp != NULL) {
		cout << temp->num << " ";
		temp = temp->Next;
	}
}

Node* getnode(List& list, int index) {
	if (index >= list.count)
		return NULL;
	Node* temp;
	temp = list.First;
	for (int i = 0; i < index; i++) {
		temp = temp->Next;
	}
	return temp;
}

void renum(List& list, int index, int newnum) {
	Node* temp;
	temp = getnode(list, index);
	temp->num = newnum;

}

void insert(List& list, int index, int newnum) {
	Node* temp, * temp2;
	Node* newnode = new Node;

	newnode->num = newnum;
	temp = getnode(list, index);
	//предыдущий элемент
	temp2 = temp->Prew;
	temp->Prew = newnode;
	newnode->Next = temp;
	//указатель на следующий предыдущего должен указывать не на темп, а на newnode
	temp2->Next = newnode;
	newnode->Prew = temp2;

	list.count += 1;
}

void delite(List list,int index) {
	Node* temp;
	temp = getnode(list, index);
	if (temp->Next == NULL) {
		list.Last = temp->Prew;
		temp->Prew->Next = NULL;
		return;
	}
	else
		temp->Prew->Next = temp->Next;
	if (temp->Prew == NULL) {
		list.First = temp->Next;
		temp->Next->Prew = NULL;
		return;
	}
	else
		temp->Next->Prew = temp->Prew;
	delete temp;
	list.count -= 1;
}

int main()
{
	system("chcp 1251 > text");
	List list;
	int userchoice = 10;
	int index;
	int num;
	while (userchoice != 0) {
		cout << "МЕНЮ:" << endl;
		cout << "1. Добавление на позицию." << endl;
		cout << "2. Добавление в начало." << endl;
		cout << "3. Добавление в конец." << endl;
		cout << "4. Удаление по индексу." << endl;
		cout << "5. Изменение по индексу." << endl;
		cout << "6. Просмотр." << endl;
		cin >> userchoice;
		if (userchoice == 1) {
			cout << "Позиция: ";
			cin >> index;
			cout << "Значение: ";
			cin >> num;
			insert(list, index, num);
		}
		else if (userchoice == 2) {
			int temp;
			cout << "Значение: ";
			cin >> temp;
			up(list, temp);
		}
		else if (userchoice == 3) {
			int temp;
			cout << "Значение: ";
			cin >> temp;
			back(list, temp);
		}
		else if (userchoice == 4) {
			cout << "Позиция: ";
			cin >> index;
			delite(list, index);
		}
		else if (userchoice == 5) {
			int newnum, index;
			cout << "Введите индекс\n";
			cin >> index;
			cout << "Введите новое число\n";
			cin >> newnum;
			renum(list, index, newnum);
		}
		else if (userchoice == 6) {
			print(list);
			cout << endl;
		}

	}
}