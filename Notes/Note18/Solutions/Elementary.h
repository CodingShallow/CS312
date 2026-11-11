#ifndef ELEMENTARY_H
#define ELEMENTARY_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace aan
{
    class Object 
    {
        private:
        virtual std::string toString() const = 0;

        friend std::ostream& operator<<(std::ostream& out,const Object& obj)
        {
            out << obj.toString();
            return out;
        }
    };

    template <class T>
    class Stack : public Object
    {
        private:
        std::vector<T> data;
        int top;

        std::string toString() const override 
        {
            std::stringstream out;

            out << "[";

            for(int i = top - 1;i >= 0;i -= 1)
            {
                out << data[i];
                if(i > 0) {out << ",";}
            }
            out << "]";
            return out.str();
        }

        void resize() 
        {
            std::vector<T> t = data;
            data = std::vector<T>(data.size() * 2);

            for(int i = 0;i < top;i += 1)
            {
                data[i] = t[i];
            }
        }

        public:
        //Default Constructor
        Stack()
        {
            data = std::vector<T>(100);
            top = 0;
        }

        //Copy Constructor
        Stack(const Stack<T>& obj)
        {
            data = obj.data;
            top = obj.top;
        }

        //Assignment Operator
        Stack<T>& operator=(const Stack<T>& rhs)
        {
            if(this != &rhs)
            {
                data = rhs.data;
                top = rhs.top;
            }
        }

        //Destructor
        ~Stack() {}

        void push(const T& obj)
        {
            if(top == data.size()) {resize();}
            data[top] = obj;
            top += 1;
        }

        void pop() 
        {
            if(top > 0) 
            {
                top -= 1;
            }
        }

        const T& peek() const
        {
            if(top == 0) 
            {
                throw std::out_of_range("underflow error");
            }
            return data[top-1];
        }

        bool empty() const 
        {
            return top == 0;
        }
    };


    template <class T>
    class Queue : public Object
    {
        private:
        std::vector<T> data;
        int front;
        int back;

        
        std::string toString() const override 
        {
            std::stringstream out;

            out << "[";

            for(int i = front;i % data.size() != back;i = (i + 1) % data.size())
            {
                out << data[i];
                if((i + 1) % data.size() != back) {out << ",";}
            }
            out << "]";
            return out.str();
        }

        void resize() 
        {
            std::vector<T> t;

            for(int i = 0;(front + i) % data.size() != back;i += 1)
            {
                t[i] = data[(front + i) % data.size()];
            }

            data = std::vector<T>(data.size() * 2);

            for(int i = 0;i < t.size();i += 1)
            {
                data[i] = t[i];
            }
            front = 0;
            back = t.size();
        }

        public:
        //Default Constructor
        Queue()
        {
            data = std::vector<T>(101);
            front = 0;
            back = 0;
        }

        //Copy Constructor
        Queue(const Queue<T>& obj)
        {
            data = obj.data;
            front = obj.front;
            back = obj.back;
        }

        //Assignment Operator
        Queue<T>& operator=(const Queue<T>& rhs)
        {
            if(this != &rhs)
            {
                data = rhs.data;
                front = rhs.front;
                back = rhs.back;
            }
        }

        //Destructor
        ~Queue() {}

        void enqueue(const T& obj)
        {
            if((back + 1) % data.size() == front) {resize();}
            data[back] = obj;
            back = (back + 1) % data.size();
        }

        void dequeue() 
        {
            if(front != back) 
            {
                front = (front + 1) % data.size();
            }
        }

        const T& peek() const
        {
            if(front == back) 
            {
                throw std::out_of_range("underflow error");
            }
            return data[front];
        }

        bool empty() const 
        {
            return front == back;
        }
    };
}

#endif //ELEMENTARY_H