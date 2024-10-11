#include "dlist.h"
#include "dlist.cpp"
using namespace std;

void build(node *&head) {
    int input;
    cout << "Enter a list of integers ending with -1: ";
    cin >> input;
    while (input != -1) {
        node *newNode = new node;
        newNode->data = input;
        newNode->next = head;
        head = newNode;
        cin >> input;
    }
}

void display(node *head) {
    cout << "List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int largerSum = sumLarger(head);
	cout << "Total number of nodes larger than the head: ";
        cout << largerSum <<endl;

	node* newHead = nullptr;
	int largerCount = copyLarger(head, newHead);
  	cout << largerCount << " nodes are copied larger than the head:";
        cout << endl;
	display(newHead);
 

    display(head);
    destroy(head);    
    return 0;
};

void destroy(node *&head) {
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
