#include "Treatment.h"

template <class T>
bool isEmpty(Stack<T> &s) {
    return (s.head == NULL);
}

template <class T>
Node<T>* createNode(T data) {
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

template <class T>
void push(Stack<T> &s) {
    T data;
    do{
        cout << "Inputting the value: "; cin >> data;
        if(cin.fail()) cout << "Inputting the value failed\n";
    }while(cin.fail());
    Node<T> *newNode = createNode(data);
    if (isEmpty(s)) {
        s.head = newNode;
    } else {
        newNode->next = s.head;
        s.head = newNode;
    }
}
template <class T>
void push(Stack<T> &s, T data) {
    Node<T> *newNode = createNode(data);
    if (isEmpty(s)) {
        s.head = newNode;
    } else {
        newNode->next = s.head;
        s.head = newNode;
    }
}
template<class T>
void pop(Stack<T> &s){
    if(isEmpty(s)) cout << "None list!\n";
    else{
        Node<T> *temp = s.head;
        s.head = temp->next;
        delete temp;
    }
}

template <class T>
void peek(Stack<T> &s){
    if(isEmpty(s)) cout << "None list!\n";
    else{
        Node<T> *cur = s.head;
        cout << cur->data << " "; 
    }
}

template <class T>
void createListFromFile(Stack<T> &s){
    fstream file;
    file.open(nameFile, ios::in);
    if(file.is_open()){
        int data = 0;
        Node<T> *newNode = NULL;
        if (isEmpty(s)) {
            file >> data;
            newNode = createNode(data);
            s.head = newNode;
        }
        while(!file.eof()){
            file >> data;
            newNode = createNode(data);
            newNode->next = s.head;
            s.head = newNode;
        }
    }
    else cout << "Opening file failed!\n";
}

template <class T>
void printList(Stack<T> &s){
    if(isEmpty(s)) cout << "None list!\n";
    else{
        Node<T>* cur = s.head;
        while(cur->next != NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
    cout << endl;
}

template <class T>
void clearList(Stack<T> &s){
    if(isEmpty(s)) cout << "None list!\n";
    else {
        Node<T> *temp = NULL;
        while(s.head != NULL){
            temp = s.head;
            s.head = temp->next;
            delete temp;
        }
    }
}

template <class T>
void deletePos(Stack<T> &s) {
    int pos = 0;
    do {
        cout << "inputting the position: ";
        cin >> pos;
        if (pos < 0 || cin.fail()) {
            cout << "Inputting failed!\n";
        }
    } while (pos < 0 || cin.fail());

    if (isEmpty(s)) {
        cout << "None list!\n";
    } else {
        if (pos == 0) {
            Node<T> *temp = s.head;
            s.head = temp->next;
            delete temp;
        } else {
            Node<T> *cur = s.head;
            Node<T> *prev = NULL;
            int count = 0;
            while (cur != NULL && count < pos) {
                prev = cur;
                cur = cur->next;
                count++;
            }
            if (cur != NULL) {
                prev->next = cur->next;
                delete cur;
            }
        }
    }
}


template <class T>
void insertPos(Stack<T> &s){
    int pos = 0, value = 0;
    do{
        cout << "inputting the position and value: ";
        cin >> pos >> value;
        if (pos < 0 || cin.fail()) cout << "Inputting failed!\n";
    } while(pos < 0 || cin.fail());

    Node<T> *newNode = createNode(value);
    if(isEmpty(s)){
        s.head = newNode;
    }
    if(pos == 0){
        newNode->next = s.head;
        s.head = newNode;
    }
    else{
        Node<T> *cur = s.head;
        for(int i = 0; i < pos-1; i++){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// xài cho trường hợp deletePos và insertPos vì hai lệnh này thay đổi giá trị của s toàn bộ
template <class T>
void copyStack(Stack<T> &source, Stack<T> &destination) {
    if (isEmpty(source)) {
        destination.head = NULL;
    } else {
        Node<T> *cur = source.head;
        Node<T> *prev = NULL;
        Node<T> *newNode = createNode(cur->data);
        destination.head = newNode;
        prev = newNode;
        cur = cur->next;

        while (cur != NULL) {
            newNode = createNode(cur->data);
            prev->next = newNode;
            prev = newNode;
            cur = cur->next;
        }
    }
}

template <class T>
int countNode(Stack<T> &s){
    Node<T> *cur = s.head;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}