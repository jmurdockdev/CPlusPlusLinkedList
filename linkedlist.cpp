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
		head = NULL;
	}

	~LinkedList(){
		Node* nodePtr;
		Node* nextNode;

		nodePtr = head;

		while (nodePtr != NULL) {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}

	void appendNode(double num){

		Node* newNode; // Point to new Node
		Node* nodePtr; // Move through the LinkedList

		newNode = new Node; // Allocate a new Node
		newNode->value = num;
		newNode->next = NULL;

		// If no nodes in the LinkedList,
		// make newNode the first node
		if (!head){
			head = newNode;
		}else{
			// Initiailize nodePtr to head of LinkedList
			nodePtr = head;
			// Fid last node in the LinkedList
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
		Node* previousNode = NULL;

		newNode = new Node;
		newNode->value = num;

		if (!head){
			head = newNode;
			newNode->next = NULL;
		}else{
			nodePtr = head;
			previousNode = NULL;

			// If value is less than new num
			// insert there
			while (nodePtr != NULL &&  num > nodePtr->value) {
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// is the new node is the first of the list
			if(previousNode == NULL){
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

			while(nodePtr != NULL && nodePtr->value != num){
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

	for(int i = 0; i < 10; i++){
		foo.appendNode(i);
	}

	foo.deleteNode(7);
	foo.displayList();
	foo.~LinkedList();

	return 0;
}
