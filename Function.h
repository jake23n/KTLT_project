#pragma once
#include "Treatment.cpp"

const string nameSave = "output.txt";
const string nameMemoryReset = "memory.txt";
const string nameSelection[] = {"push", "insertPos", "deletePos", "sort", "undo", "redo", "reset", "save", "exit"};
static void menuStack(int input);
template <class T>
void undoStack(Stack<Stack<T>> &);
template <class T>
void redoStack(Stack<Stack<T>> &);

template <class T>
void bubbleSort(Stack<T> &s);
template <class T>
void memoryReset(Stack<Stack<T>> &stack);
template <class T>
void save(Stack<T> &s, string nameFile);
static void clearConsole();
static int getConsoleInput();

template <class T>
bool compareStacks(Stack<T>& stack1, Stack<T>& stack2);

