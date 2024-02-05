#pragma once
#include <iostream>
class product
{  
    private:
        int width, height,square,x,y;
        bool packed=false;
    public:
        product();
        product(int width, int height);
        void setProduct(int width, int height);
        void setPacked(bool pack);
        void setcoords(int x, int y);
        int getwidth();
        int getheight();     
        int getsquare();
        int getx();
        int gety();
        void print();
        void flip();
        bool check();
        bool compare(const product &obj1, const product &obj2);
   
};

