#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
const string nameFile = "input.txt";

template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
struct Stack {
    Node<T> *head = NULL;
};


template <class T>
bool isEmpty(Stack<T> &s);
template <class T>
Node<T>* createNode(T data);
template <class T>
void push(Stack<T> &s);
template <class T>
void push(Stack<T> &s, T data);
template<class T>
void pop(Stack<T> &s);
template <class T>
void peek(Stack<T> &s);
template <class T>
void createListFromFile(Stack<T> &s);
template <class T>
void printList(Stack<T> &s);
template <class T>
void clearList(Stack<T> &s);
template <class T>
void deletePos(Stack<T> &s);
template <class T>
void insertPos(Stack<T> &s);
template <class T>
void copyStack(Stack<T> &source, Stack<T> &destination);