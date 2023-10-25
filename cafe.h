#pragma once
#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <string>
#include "string_parsing.h"
#pragma warning(disable:4996)
#define MENU 12

using namespace std;


class Cafe_Menu
{
private:
	string coffee;
	string size;
	int price;

public:
	Cafe_Menu();
	~Cafe_Menu();
	string get_menu_coffee(void);
	string get_menu_size(void);
	int get_menu_price(void);
	void insert_menu(string coffee, string size, int price);
};


class Cafe
{
private:
	string coffee;
	string size;
	int price;

public:
	Cafe();
	~Cafe();
	void enter_menu(string coffee, string size, int price);
	void display_menu(int index);
	void display_menu(int index, int order_count);
	int get_price(void);
	static int total_price; // °ø±Ý
	static void get_total_price(int input);
	
};




#endif