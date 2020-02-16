/* 
============================ Question ============================
Program to insert a node at a specific position in a linked list
Position: 0 (begining of linked list)
==================================================================
*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node *newNode(int data){
	struct Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct Node * insertInLL(struct Node *head, int data, int position){
	if(!head){
		return newNode(data);
	}
	if(position == 0){
		struct Node *temp = newNode(data);
		temp->next = head;
		return temp;
	} else {
		head->next = insertInLL(head->next,data,position-1);
		return head;
	}
}

void printList(struct Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main() {
	struct Node *head = NULL;
	head = insertInLL(head,3,0);
	head = insertInLL(head,2,0);
	head = insertInLL(head,1,300);
	printList(head);
	return 0;
}