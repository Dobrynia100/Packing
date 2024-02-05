#include "product.h"
product::product()
{
	width = 0;
	height = 0;	
}
product::product(int width, int height)
{
	this->width = width;
	this->height = height;
	this->square = width * height;
}
void product::setProduct(int width, int height)
{
	this->width = width;
	this->height = height;
	this->square = width * height;
}
void product::setPacked(bool pack)
{
	packed = pack;
}
void product::setcoords(int x,int y)
{
	this->x = x;
	this->y = y;
}
int product::getwidth()
{ 
	return width;
}
int product::getheight()
{
	return height;
}

int product::getsquare()
{
	return square;
}
int product::getx()
{
	return x;
}
int product::gety()
{
	return y;
}
void product::print()
{
	std::cout << "ширина " << width << " высота " << height<< std::endl;
}
void product::flip()
{
	std::swap(width, height);
}
bool product::check()
{
	return packed;
}
bool product::compare(const product& obj1, const product& obj2)
{
	return obj1.square > obj2.square;
}