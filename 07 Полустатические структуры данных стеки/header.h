#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Stack
{
	int number;
	Stack* next;
	Stack* head;
};

void push(Stack*& st, int value);
int pop(Stack*& st);
void print(Stack*& st);
void clear(Stack*& st);
void toFile(Stack*& st, string path);
void fromFile(Stack*& st, string path);
void main_task(Stack*& st, Stack*& st1, Stack*& st2);
void main_task1(Stack*& st, Stack*& st1, Stack*& st2);