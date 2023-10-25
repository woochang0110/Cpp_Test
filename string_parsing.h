#pragma once
#ifndef STRING_PARSING_H
#define STRING_PARSING_H

#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

class String_Parsing
{
private:
	char* ptr;
	char input[100];
	int order;
public:
	String_Parsing();
	~String_Parsing();
	char* get_char_ptr(void);
	string get_menu_size(void);
	int get_menu_price(void);
	void insert_menu(string coffee, string size, int price);
};


#endif