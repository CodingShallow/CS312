#include <iostream>
#include <string>
#include "Elementary.h"

int main()
{
    aan::Stack<int> s;
    aan::Queue<int> q;
    int c;
    int a;

    while(true)
    {
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter choice: ";
        
        while(true)
        {
            std::cin >> c;
            if(c >= 1 && c <= 3) {break;}
            std::cout << "Invalid Choice. Enter choice: ";
        }

        if(c == 1)
        {
            std::cout << "Enter value: ";
            std::cin >> a;

            s.push(a);
            q.enqueue(a);

            std::cout << "Stack:\n" << s << " " << s.peek() << "\n";
            std::cout << "Queue:\n" << q << " " << q.peek() << "\n";
        }
        else if(c == 2)
        {
            s.pop();
            q.dequeue();

            std::cout << "Stack:\n" << s << " ";

            if(s.empty()) {std::cout << "$\n";}
            else {std::cout << s.peek() << "\n";}

            std::cout << "Queue:\n" << q << " ";

            if(q.empty()) {std::cout << "$\n";}
            else {std::cout << q.peek() << "\n";}
        }
        else 
        {
            std::cout << "Program terminating\n";
            break;
        }
    }
    return 0;

}