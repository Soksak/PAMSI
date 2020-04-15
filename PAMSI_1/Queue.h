#include <iostream>
using namespace std;


template <typename T>
class Queue{
    struct Node {
        T data;
        Node *next;
        Node(T d) {
            data = d;
            next = nullptr;
        }
    };
    Node *front, *rear;
public:
    Queue(){
        front = rear = NULL;
    };
    ~Queue();
    Queue(const Queue& obj);
    void enqueue(const T& newElement);
    T dequeue ();
    void print();
};

template <typename T>
Queue<T>::~Queue() {
    Node* temp = front;
    while(front!=nullptr){
        temp = front;
        front = front->next;
        delete (temp);
    }

}

template <typename T>
Queue<T>::Queue(const Queue &obj)
{
    if (obj.front == NULL) {
        front = NULL;
    }
    else {
        front = new Node(obj.front->data);
        Node *current = front;
        Node *objfront = objfront;
        Node *currentObj = obj.front;
        while (currentObj->next != NULL) {
            current->next = new Node(currentObj->next->data);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
}

template <typename T>
void Queue<T>::enqueue(const T &newElement) {
    // Create a new LL node
    Node* temp = new Node(newElement);
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

template <typename T>
T Queue<T>::dequeue() {
    Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;

    delete (temp);
}


template <typename T>
void Queue<T>::print() {
    Node* temp=front;
    cout<<"kolejka:"<<endl;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}