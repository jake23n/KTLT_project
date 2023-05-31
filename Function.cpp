#include "Function.h"

int getConsoleInput() {
     int c = _getch();
    if (c == 0 || c == 224)
    {
        switch (_getch())
        {
        case 72:				//move up
            return 2;
        case 75:				//move left
            return 3;
        case 77:				//move right
            return 4;
        case 80:				//move down
            return 5;
        default:
            return 0;
        }
    }
    else
    {
        switch (c) {
            case 27:  // Esc
                return 0;
            case 90:
                return 11;
            case 122:  // Z, z (undo)
                return 11;
            case 82:
                return 12;
            case 114:  // R, r
                return 12;
            case 49:  // 1
                return 1;
            case 50:  // 2
                return 2;
            case 51:  // 3
                return 3;
            case 52:  // 4
                return 4;
            case 53:  // 5
                return 5;
            case 54:  // 6
                return 6;
            case 55:  // 7
                return 7;
            case 56:  // 8
                return 8;
            case 57:  // 9
                return 9;
            default:
                return 0;
        }
    }
}

template <class T>
void memoryReset(Stack<Stack<T>>& stack) {
    Node<Stack<T>>* cur = stack.head;
    while (cur != NULL) {
        save(cur->data, nameMemoryReset);  // Make sure to define the `save` function or provide its implementation
        cur = cur->next;
    }
}

template <class T>
void undoStack(Stack<Stack<T>>& s) {
    if (isEmpty(s)) cout << "Can't undo\n";
    if (s.head != NULL && s.head->next != NULL) {
        Node<Stack<T>> *cur = s.head;
        pop(cur->data);
        s.head = cur->next;
    }
}
template <class T>
void redoStack(Stack<Stack<T>>& s) {
    if (isEmpty(s)) cout << "Can't redo\n";
    else if (s.head != NULL && s.head->next != NULL) {
        Node<Stack<T>>* cur = s.head;
        pop(cur->data);
        s.head = cur->next;
    }
}




void menuStack(int input) {
    bool SAVE = false;
    bool RESET = false;
    Stack<int> s;
    createListFromFile(s);
    Stack<Stack<int>> undo;
    Stack<Stack<int>> redo;
    push(undo, s);
    printList(s);

    cout << "Number current selection\n";
    for (int i = 1; i <= 9; i++) {
        if (i == 5)
            cout << "z: " << nameSelection[i - 1] << endl;
        else if (i == 6)
            cout << "r: " << nameSelection[i - 1] << endl;
        else
            cout << i << ": " << nameSelection[i - 1] << endl;
    }
    Stack<int> copy;
    while (input != 0) {
        input = getConsoleInput();
        switch (input) {
            case 1: {
                push(s);
                printList(s);
                push(undo, s);
                break;
            }
            case 2: {
                copyStack(s, copy);
                insertPos(copy);
                push(undo, copy);
                printList(copy);
                copyStack(copy, s);
                break;
            }
            case 3: {
                copyStack(s, copy);
                deletePos(copy);
                push(undo, copy);
                printList(copy);
                copyStack(copy, s);
                break;
            }
            case 4: {
                copyStack(s, copy);
                bubbleSort(copy);
                push(undo, copy);
                printList(copy);
                copyStack(copy, s);
                break;
            }
            case 7: {
                clearList(s);
                clearConsole();
                menuStack(-1);                
                memoryReset(undo);
                RESET = true;
                break;
            }
            case 8: {
                save(s, nameSave);
                SAVE = true;
                break;
            }
            case 9: {
                exit(0);
                clearConsole();
                break;
            }
            case 11: {
                cout << "undo\n";
                undoStack(undo);
                copyStack(undo.head->data, copy);
                push(redo, copy);
                if (isEmpty(undo)) {
                    cout << "Can't undo\n";
                } else {
                    printList(undo.head->data);
                }
                break;
            }
            case 12: {
                cout << "redo\n";
                redoStack(redo);
                copyStack(redo.head->data, copy);
                push(undo, copy);
                if (isEmpty(redo)) {
                    cout << "Can't redo\n";
                } else {
                    printList(redo.head->data);
                }
                break;
            }
        }
    }
}


template <class T>
void save(Stack<T> &s, string nameFile){
    fstream file;
    file.open(nameFile, ios::out | ios::app);
    if(file.is_open()){
        Node<T> *cur = s.head;
        while(cur != NULL){
            file << cur->data << " ";
            cur = cur->next;
        }
        file << endl;
    }
    else cout << "Openning file to save failed\n";
    file.close();
}
void clearConsole(){
    system("cls");
}
// sắp xếp từ nhỏ tới lớn
template <class T>
void bubbleSort(Stack<T> &s) {
    Node<T> *cur = s.head;
    while (cur != NULL) {
        Node<T> *cur2 = cur->next;
        while (cur2 != NULL) {
            if (cur2->data < cur->data) {
                swap(cur2->data, cur->data);
            }
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
}
