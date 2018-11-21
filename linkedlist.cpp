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

	foo.displayList();

	return 0;
}
