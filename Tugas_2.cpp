#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node* next;
    Node* prev;
};

struct Node* buatnode(string data){
    // Node* newNode = new Node{data, NULL, NULL};
    Node* newNode = (Node*)malloc(sizeof(data));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev= NULL;
    return newNode;
}

void sisipnodedepan(Node** head, string data){

    Node* newNode = buatnode(data);
    newNode->next = *head;
    if(*head != NULL){

        (*head)->prev = newNode;

    }
    *head = newNode;
}

void sisipnodebelakang(Node** head, string data){

    Node* newNode = buatnode(data);
    if(*head == NULL){

        *head = newNode;
        return;

    }
    Node* bantu = *head;
    while(bantu->next != NULL){
        bantu = bantu->next;
    }
    bantu->next = newNode;
    newNode->prev = bantu;

}

Node* searching(Node* head, string key){

    Node* bantu = head;
    while(bantu != NULL){
        if(bantu->data == key){
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL;

}
void printdaridepan(Node* head){

    if(head == NULL){
        cout << "Node nya ga ada!" << endl;
    }
    Node* bantu = head;
    while(bantu != NULL){
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}