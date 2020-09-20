// Singular linked list

#include<iostream>
using namespace std;

class IntList {
private:
	struct List {
		int data;
		struct List* next;
	};
	struct List* head;
	struct List* tail;
public:
	IntList() {
		List* head = nullptr;
		List* tail = nullptr;
	}

	~IntList() {
		List* nodePtr = head;
		List* nextNode;

		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}

	void prependNode(int value) {
		List* nodePtr = new List;
		nodePtr->data = value;

		if (!head) {
			head = nodePtr;
			tail = nodePtr;
			nodePtr->next = nullptr;
		}

		else {
			nodePtr->next = head;
			head = nodePtr;
		}
	}

	void displayList() {
		List* nodePtr = head;

		while (nodePtr) {
			cout << nodePtr->data << " ";
			nodePtr = nodePtr->next;
		}

		cout << endl;
	}

	void searchList(int value){
		List* nodePtr = head;

		while(nodePtr) {
			if(nodePtr->data == value) {
				cout << value << " found!\n";
				return;
			}
			nodePtr = nodePtr->next;
		}
		
		cout << value << " not found!\n";
		
	}

	void deleteItem(int value){
		List* nodePtr = head;
		List* prevNode = head;

		if(nodePtr->data == value){
			head = head->next;
			delete nodePtr;
			return;
		}

		while(nodePtr){

			if(nodePtr->data == value){
				prevNode->next = nodePtr->next;
				delete nodePtr;
				cout << value << " deleted.\n";
				return;
			}
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
			cout << value << " not found.\n";
		
		displayList();
	}

	void sortInsert(){
		List* nodePtr = head;
		List* nodeCheck = head->next;
		int swap;

		while(nodePtr){
			while(nodeCheck){
				if(nodeCheck->data < nodePtr->data){
					swap = nodeCheck->data;
					nodeCheck->data = nodePtr->data;
					nodePtr->data = swap;
					
					}
				
				nodeCheck = nodeCheck->next;
				

			}

			nodePtr = nodePtr->next;
			if (nodePtr) {
				nodeCheck = nodePtr->next;
			}
		}
		cout << "Sorted List: ";
		displayList();
		cout << endl;
	}

	void deleteMulti(){
		List* nodePtr = head;
		List* nodeCheck = head->next;
		List* lastNode = head;

		while(nodePtr){
			while(nodeCheck){
				if(nodeCheck->data == nodePtr->data){
					lastNode->next = nodeCheck->next;
					delete nodeCheck;
					nodeCheck = lastNode->next;
				}
				nodeCheck = nodeCheck->next;
				lastNode = lastNode->next;
			}

			nodePtr = nodePtr->next;
			if(nodePtr){
				lastNode = nodePtr;
				nodeCheck = nodePtr->next;

			}
		}

		cout << "New List: ";
		displayList();
		cout << endl;

	}

};



int main() {

	int userNum = 0;
	IntList myList;

	cout << "Enter data. Enter -1 when finished: ";
	while(userNum != -1) {
		cin >> userNum;
		if (userNum == -1) {
			break;
		}
		myList.prependNode(userNum);
	}


	

	myList.displayList();

	//cout << "Enter a search value:";
	//cin >> userNum;

	//myList.searchList(userNum);

	//cout << "Enter value to delete: ";
	//cin >> userNum;

	//myList.deleteItem(userNum);

	//myList.sortInsert();

	myList.deleteMulti();

	return 0;
}