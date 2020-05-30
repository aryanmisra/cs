#include <iostream>

using namespace std;

class Node {
        public:
            int data;
        Node*next;
        
};
//  * after a class means its a pointer
void print_ll(Node*head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
};
// struct has public members by default. very similar to class
// ** declares a pointer to a pointer
void insert_start(struct Node ** head, int data){
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = ( * head);
    (* head) = new_node;
};

void insert_end(struct Node ** head, int data){
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    // hol up so im making a pointer of struct of a class that points to a pointer of head
    struct Node * last = * head;
    new_node -> data = data;
    new_node -> next = NULL;
    while (last -> next != NULL){
        last = last -> next;
    };
    last->next = new_node;

}
void insert_after(struct Node * prev, int data){
    if (prev == NULL){
        printf("prev node cant be null");
        return;
    }
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = prev-> next;
    prev-> next = new_node;
}


int main(){
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3; 
    third -> next = NULL;

    print_ll(head);
    cout<<endl;
    insert_start(&head, 112);
    print_ll(head);
    cout<<endl;
    insert_end(&head, 212);
    print_ll(head);
    cout<<endl;
    insert_after(second, 2110);
    print_ll(head);
    cout<<endl;

}