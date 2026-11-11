#include <iostream>
#include <string>
#include "Node.h"

int main()
{
    aan::Node<int>* a = new aan::Node<int>(1);
    aan::Node<int>* b = a;

    for(int i = 2;i <= 20;i += 1)
    {
        b->next() = new aan::Node<int>(i);
        b->next()->prev() = b;
        b = b->next();
    }

    std::cout << aan::toStr(a) << "\n";

    aan::Node<int>* c = aan::clone(a);
    b = a;
    aan::Node<int>* d = c;

    while(b != nullptr || d != nullptr)
    {
        if(b->data() != d->data()) {break;}
        b = b->next();
        d = d->next();
    }

    if(b == nullptr && d == nullptr)
    {
        std::cout << aan::toStr(c) << "\n";
    }
    else 
    {
        std::cout << "Copy unsuccessful\n";
    }
    
    aan::clear(a);
    aan::clear(c);

    return 0;
}