#include <iostream>

class LinkedList {

private:

	struct Node {
		double value;
		Node* next;
	};

	Node* head;

public:

	LinkedList(){
		head = nullptr;
	}

	~LinkedList(){
		Node* nodePtr;
		Node* nextNode;

		nodePtr = head;

		while (nodePtr != nullptr) {
			nextNode = nodePtr->next;
			delete (nodePtr);
			nodePtr = nextNode;
		}
	}

	void prependNode(double num){

		Node* newNode;
		newNode = new Node;
		newNode->value = num;

		if (!head){
			newNode->next = nullptr;
			head = newNode;
		}else{
			newNode->next = head;
			head = newNode;
		}

	}


	void appendNode(double num){

		Node* newNode; // Point to new Node
		Node* nodePtr; // Move through the LinkedList

		newNode = new Node; // Allocate a new Node
		newNode->value = num;
		newNode->next = nullptr;

		// If no nodes in the LinkedList,
		// make newNode the first node
		if (!head){
			head = newNode;
		}else{
			// Initiailize nodePtr to head of LinkedList
			nodePtr = head;
			// Find last node in the LinkedList
			while (nodePtr->next){
				nodePtr = nodePtr->next;
			}
			// Insert newNode as the last node
			nodePtr->next = newNode;
		}
	}

	void insertNode(double num){
		Node* newNode;
		Node* nodePtr;
		Node* previousNode = nullptr;

		newNode = new Node;
		newNode->value = num;

		if (!head){
			head = newNode;
			newNode->next = nullptr;
		}else{
			nodePtr = head;
			previousNode = nullptr;

			// If value is less than new num
			// insert there
			while (nodePtr != nullptr &&  num > nodePtr->value) {
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// is the new node is the first of the list
			if(previousNode == nullptr){
				head = newNode;
				newNode->next = nodePtr;
			}else{ // Otherwise insert after the previous node
				previousNode->next = newNode;
				newNode->next = nodePtr;
			}
		}
	}


	void deleteNode(double num){

		Node* nodePtr;
		Node* previousNode;

		if (!head) {
			return;
		}else{

			nodePtr = head;

			while(nodePtr != nullptr && nodePtr->value != num){
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr){
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}

		}
	}


	void displayList(){
		Node* nodePtr;
		nodePtr = head;

		while (nodePtr){
			std::cout << nodePtr->value << std::endl;
			nodePtr = nodePtr->next;
		}
	}

};



int main(){

	LinkedList foo;
	foo.prependNode(700);

	for(int i = 0; i < 10; i++){
		foo.appendNode(i);
	}

	foo.deleteNode(7);
	foo.prependNode(8000);
	foo.displayList();
	foo.~LinkedList();

	return 0;
}
