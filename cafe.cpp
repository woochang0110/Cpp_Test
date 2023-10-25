#include "cafe.h"

//===============Cafe_Menu Class


Cafe_Menu::Cafe_Menu()
{
	coffee.clear();//string clear strlen=0
	size.clear();
	price = 0;
}


Cafe_Menu::~Cafe_Menu()
{

}

string Cafe_Menu::get_menu_coffee(void)
{
	return this->coffee;
}

string Cafe_Menu::get_menu_size(void)
{
	return this->size;
}


int Cafe_Menu::get_menu_price(void)
{
	return this->price;
}

void Cafe_Menu::insert_menu(string coffee, string size, int price)
{
	this->coffee = coffee;
	this->size = size;
	this->price = price;
}


//====================Cafe Class

int Cafe::total_price = 0;


Cafe::Cafe()
{
	this->coffee.clear();//string clear strlen=0
	this->size.clear();
	this->price = 0;
}

Cafe::~Cafe()
{

}

void Cafe::enter_menu(string coffee, string size, int price)
{
	this->coffee = coffee;
	this->size = size;
	this->price = price;
}

void Cafe::display_menu(int index)
{
	std::cout << "[" << index + 1 << "] " << coffee<<" " << size<< " " << ((double)price / 1000) << "\n";

}

void Cafe::display_menu(int index,int order_count)
{
	std::cout << "[" << index + 1 << "] " << coffee << " " << size << " " << order_count << "°³\n";

}


int Cafe::get_price(void)
{
	return this->price;
}

void Cafe::get_total_price(int input) {
	total_price += input;
}


