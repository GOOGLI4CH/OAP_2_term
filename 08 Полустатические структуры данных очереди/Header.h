#pragma once
#include <iostream>

using namespace std;

struct Queue
{
	char data;
	Queue* next;
};

void insert(Queue*& begin, Queue*& end, char value);
void print(Queue*& begin);
void del(Queue*& begin);
int size_count(Queue*& begin);