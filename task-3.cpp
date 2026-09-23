#include <iostream>
using namespace std;

//Node structure 
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;   // head pointer, starts empty

// 1. Insert at head 
void insertAtHead(int value) {
    Node* newNode = new Node();   // create new node
    newNode->data = value;
    newNode->next = head;         // new node points to old head
    head = newNode;                // head now points to new node
    cout << "Inserted " << value << " at head.\n";
}

//2. Insert at 3rd position 
void insertAtThird(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    // if list has fewer than 2 nodes, it is not possibe to have "3rd position" properly (SAD)
    if (head == NULL || head->next == NULL) {
        cout << "List has fewer than 2 nodes. Inserting at the end instead.\n";
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            head->next = newNode;
        }
        return;
    }

    // makin a third node
    Node* temp = head->next;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at 3rd position.\n";
}

//3. Display the list
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//4. Delete last node
void deleteLast() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    // only one node in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted the only node in the list.\n";
        return;
    }

    // traverse until second-to-last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;      // delete the last node
    temp->next = NULL;      // second-to-last is now the last
    cout << "Deleted last node.\n";
}

// 5. Count nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 6. Reverse the list (iterative) 
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // save next node before we overwrite it
        curr->next = prev;   // reverse the link
        prev = curr;          // move prev forward
        curr = next;          // move curr forward
    }
    head = prev;   // prev is the new head after the loop ends
    cout << "List reversed.\n";
}

// 7. Search for a value//
void searchValue(int value) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " not found in the list.\n";
}

//8. Menu-driven main 
int main() {
    int choice, value;

    while (true) {
        // print menu
        cout << "\n----- Linked List Menu -----\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at 3rd position\n";
        cout << "3. Display list\n";
        cout << "4. Delete last node\n";
        cout << "5. Count nodes\n";
        cout << "6. Reverse list\n";
        cout << "7. Search for a value\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // handle each menu option
        if (choice == 1) {
            cout << "Enter value to insert at head: ";
            cin >> value;
            insertAtHead(value);
        }
        else if (choice == 2) {
            cout << "Enter value to insert at 3rd position: ";
            cin >> value;
            insertAtThird(value);
        }
        else if (choice == 3) {
            displayList();
        }
        else if (choice == 4) {
            deleteLast();
            displayList();   // show updated list after deletion
        }
        else if (choice == 5) {
            cout << "Number of nodes: " << countNodes() << endl;
        }
        else if (choice == 6) {
            reverseList();
            displayList();   // show updated list after reversal
        }
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> value;
            searchValue(value);
        }
        else if (choice == 8) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }

    // Delete the list
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;

    return 0;
}