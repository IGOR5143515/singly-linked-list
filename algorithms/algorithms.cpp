#include <iostream>

struct Node {
    std::string str;
    Node* next;
    Node(std::string s):str(s),next(nullptr){}

};

class list {
private:
    Node* first;
    Node* last;

public:
    
    list() :first(nullptr), last(nullptr){}

    bool isAmpty() {

        return first == nullptr;

    }

    void pushBack(std::string s){
    
        Node* ptr = new Node(s);
        
        if (first == nullptr)
            first = last = ptr;
        else
            last->next = ptr;

        last = ptr;
    
    }

    void print() {

        
        while (!isAmpty()) {

            std::cout << first->str;
            first = first->next;

        }
       
    }

    Node* find(std::string s) {
        Node* p = first;

        while(p->str!=s&&!isAmpty())
            p=p->next;

        if (p->str == s)
            return p;
        else
            return nullptr;
        


    }

    void renoveFirst() {

        if (!isAmpty()) {

            Node* p = first;
            first = first->next;

            delete p;
            p = nullptr;

        }

    }

    void RemoveLast() {

        if (!isAmpty() && first == last) {
            renoveFirst();
            return;
        }

        Node* p = first;

        while (p->next != last)
            p = p->next;

        p->next = nullptr;
        delete last;
        last = p;


    }

    void remove(std::string s) {

        if (isAmpty())return;


        if (first->str == s) {
            renoveFirst();
            return;
        }

        if (last->str == s) {
            RemoveLast();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;

        while (fast->str != s) {

            slow = slow->next;
            fast = fast->next;

        }

        slow->next = fast->next;
        delete fast;



    }
    Node* operator[](int a) {

        if (isAmpty())return nullptr;
        Node* p = first;
        for (size_t i = 1; i < a; i++)
        {
            p = p->next;
        }
        return p;


    }

};



int main()
{

       list l;
       l.pushBack("1");
       l.pushBack("2");
       l.pushBack("3");
       l.pushBack("4");
    
       std::cout << l[2]->str;

}


