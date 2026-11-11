#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace aan
{
    template <class T>
    class Node 
    {
        private:
        T content;
        Node<T>* links[2];
        
        public:
        Node() 
        {
            content = T();
            links[0] = nullptr;
            links[1] = nullptr;
        }

        Node(const T& obj) 
        {
            content = obj;
            links[0] = nullptr;
            links[1] = nullptr;
        }

        Node(const Node<T>& obj)
        {
            content = obj.content;
            links[0] = nullptr;
            links[1] = nullptr;
        }

        Node<T>& operator=(const Node<T>& rhs)
        {
            if(this != &rhs)
            {
                content = rhs.content;
            }
            return *this;
        }

        ~Node() {}

        const T& data() const {return content;}
        const Node<T>* prev() const {return links[0];}
        const Node<T>* next() const {return links[1];}

        T& data() {return content;}
        Node<T>*& prev() {return links[0];}
        Node<T>*& next() {return links[1];}
    };

    template <typename T>
    Node<T>* clone(Node<T>* ptr)
    {
        if(ptr == nullptr) {return nullptr;}
        
        Node<T>* cp = new Node<T>(ptr->data());
        Node<T>* pt = ptr;
        Node<T>* ct = cp;

        while(pt->next() != nullptr)
        {
            ct->next() = new Node<T>(pt->next()->data());
            ct->next()->prev() = ct;
            ct = ct->next();
            pt = pt->next();
        }
        return cp;
    }

    template <typename T>
    void clear(Node<T>*& ptr)
    {
        Node<T>* t;

        while(ptr != nullptr)
        {
            t = ptr;
            ptr = ptr->next();
            delete t;
            t = nullptr;
        }
    }

    template <typename T>
    std::string toStr(const Node<T>* ptr)
    {
        std::stringstream out;

        out << "[";

        for(const Node<T>* t = ptr;t != nullptr;t = t->next())
        {
            out << t->data();
            if(t->next() != nullptr) {out << ",";}
        }

        out << "]";
        return out.str();
    }

}

#endif