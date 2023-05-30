#include "Function.h"

int getConsoleInput() {
    int c = _getch();
    if (c == 0 || c == 224) {
        switch (_getch()) {
            case 72:  // move up
                return 2;
            case 75:  // move left
                return 3;
            case 77:  // move right
                return 4;
            case 80:  // move down
                return 5;
            default:
                return 0;
        }
    } else {
        if (c == 27)  // esc
            return 1;
        else if (c == 87 || c == 119)  // W, w
            return 2;
        else if (c == 65 || c == 97)  // A, a
            return 3;
        else if (c == 68 || c == 100)  // D, d
            return 4;
        else if (c == 83 || c == 115)  // S, s
            return 5;
        else if (c == 13)  // Enter
            return 6;
        else if (c == 76 || c == 108)  // L, l (lưu game)
            return 7;
        else if (c == 84 || c == 116)  // T, t (load game)
            return 10;
        else if (c == 89 || c == 121)  // Y, y
            return 11;
        else if (c == 77 || c == 109)  // M, m (turn off sound)
            return 8;
        else if (c == 78 || c == 110)  // N, n (turn on sound)
            return 9;
        else if (c == 90 || c == 122)  // Z, z (undo)
            return 12;
        else if (c == 69 || c == 101)  // E, e (setting)
            return 13;
        else if (c == 72 || c == 104)  // H, h (gợi ý)
            return 14;
        else
            return 0;
    }
}

template <class T>
Stack<T> undoStack(Stack<Stack<T>>& s, bool flag) {
    if (s.head != NULL && s.head->next != NULL) {
        Stack<T> copy;
        copyStack(s.head->data, copy);
        pop(s.head->data);
        return copy;
    }
    return Stack<T>();
}

void menuStack(int input) {
    Stack<int> s;
    createListFromFile(s);
    Stack<Stack<int>> stack;
    push(stack, s);

    for (int i = 0; i < 5; i++) {
        cout << i << ": " << nameSelection[i] << endl;
    }
    cout << "W A D S\n";
    cout << "Z: undo\n";
    bool flag = false;
    Stack<int> copy;

    while (input != 1) {
        input = getConsoleInput();
        switch (input) {
            case 2: {
                flag = false;
                push(s);
                printList(s);
                push(stack, s);
                break;
            }
            case 3: {
                flag = false;
                pop(s);
                printList(s);
                push(stack, s);
                break;
            }
            case 4: {
                flag = false;
                copyStack(stack.head->data, s);
                peek(s);
                break;
            }
            case 5: {
                flag = true;
                Stack<int> copy;
                copyStack(s, copy);
                deletePos(copy);
                push(stack, copy);
                printList(copy);
                break;
            }
            case 12: {
                copy = undoStack(stack, flag);
                printList(stack.head->data);
                break;
            }
            case 11: {
                push(stack, copy);
                printList(stack.head->data);
                break;
            }
            case 13:{
                printList(stack.head->data);
            }
        }
    }
}
