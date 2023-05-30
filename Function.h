#pragma once
#include "Treatment.cpp"

const string nameSelection[] = {"push", "pop", "peek", "insertPos", "deletePos"};
void menuStack(int input);
template <class T>
Stack<T> undoStack(Stack<Stack<T>> &s, bool flag);