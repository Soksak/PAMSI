#include <iostream>
using namespace std;



template <typename T>
class Stack{
    struct Node {
        T data;
        Node *next;
        Node(T d) {
            data = d;
            next = nullptr;
        }
    };
    Node* top = NULL;
public:
    Stack();
    ~Stack();
    Stack(const Stack<T> &other);
    void push(const T& newElement);
    T pop();
    void print();
};

template <typename T>
Stack<T>::Stack() {
    top=nullptr;
}

template <typename T>
Stack<T>::~Stack() {
    Node* temp = top;
    while (temp != nullptr) {    //
        top = temp->next;
        delete temp;
        temp = top;
    }
    delete top;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    const auto& node = other.top;
    auto& pnode = top;
    pnode = nullptr;

    while (node)
    {
        pnode = new Node;
        pnode->data = node->data;

        node = node->next;
        pnode = pnode->next;
    }
}


template <typename T>
void Stack<T>::print() {
    Node* temp=top;
    cout<< "Stos:"<<endl;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

template <typename T>
void Stack<T>::push(const T &newElement) {
    Node* newnode=new Node(newElement);
    newnode->next=top;
    top=newnode;
}

template <typename T>
T Stack<T>::pop() {
    Node* temp=new Node(0);
    if(top==NULL)
        cout<<"Stack Underflow"<<endl;
    else {
        temp = top;
        top = top->next;
    }
    delete(temp);
}
