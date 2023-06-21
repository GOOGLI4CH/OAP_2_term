#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct ADDRESS
{
	string x;			//Для функции из задания
	string name;
	string city;
	ADDRESS* next;
	ADDRESS* prev;

	ADDRESS() { next = NULL; prev = NULL; };
};

void insert(ADDRESS*, ADDRESS*&, ADDRESS*&);
ADDRESS* set();
void print(ADDRESS*&);
void del(string, ADDRESS*&, ADDRESS*&);
void toFile(ADDRESS*&);
void fromFile(ADDRESS*&, ADDRESS*&);
void delX(string, ADDRESS*&, ADDRESS*&);