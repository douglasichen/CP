// A simple CPP program to introduce
// a linked list
#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};


void printLinkedList(Node* nodePtr) {
	while (nodePtr!=NULL) {
		cout << nodePtr->data << ' ';
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

void insertLinkedList(Node* nodeRefPtr, int data) {
	Node* newNode = new Node();
	newNode->data = data;
	
	Node* rightNode = nodeRefPtr->next;
	nodeRefPtr->next = newNode;
	newNode->next = rightNode;
}

void deleteLinkedList(Node* head, int data) {
	if (head->data == data) {
		
	}
	for (; head!=NULL; head = head->next) {
		if (head->next->data == data) {
			Node* deleteNode = head->next;
			head->next = deleteNode->next;
			delete deleteNode;
			break;
		}
		
	}
}

int main() {	
    Node* head = new Node();

	int n; cin >> n;
	
	Node* currentNode = head;
	for (int i=0; i<n; i++) {
		int inp; cin >> inp;
		currentNode->data = inp;
		currentNode->next = (i!=n-1) ? new Node() : NULL;
		currentNode = currentNode->next;
	}
	printLinkedList(head);
	insertLinkedList(head, 100);
	printLinkedList(head);
	deleteLinkedList(head, 1);
	printLinkedList(head);
}
