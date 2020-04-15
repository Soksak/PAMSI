#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue{
    struct Node {
        T data;
        int priority;
        Node *next;
        Node(T d,int priorit) {
            data = d;
            priority = priorit;
            next = nullptr;
        }
    };
    Node *front;
public:
    PriorityQueue(){
        front = NULL;
    };
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue& obj);
    void enqueue(const T& newElement, int priority);
    T dequeue ();
    void print();
};

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    Node *temp=front;
    while(front!=nullptr){
        temp=front;
        front=front->next;
        delete(temp);
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj) {
    if (obj.front == NULL) {
        front = NULL;
    }
    else {
        front = new Node(obj.front->data,obj.front->priority);
        Node *current = front;
        Node *objfront = objfront;
        Node *currentObj = obj.front;
        while (currentObj->next != NULL) {
            current->next = new Node(currentObj->next->data,currentObj->next->priority);
            currentObj = currentObj->next;
            current = current->next;
        }
    }

}
template <typename T>
void PriorityQueue<T>::enqueue(const T &newElement, int priority) {
    {
        Node *tmp=new Node(newElement, priority);
        Node *q;
        if (front == NULL || priority > front->priority) {
            tmp->next = front;
            front = tmp;
        } else {
            q = front;
            while (q->next != NULL && q->next->priority >= priority)
                q = q->next;
            tmp->next = q->next;
            q->next = tmp;
        }
    }
}

template <typename T>
T PriorityQueue<T>::dequeue() {
    Node* temp = front;
    front = front->next;
    delete (temp);
}

template <typename T>
void PriorityQueue<T>::print() {
    Node* temp=front;
    cout<<"Kolejka priorytetowa"<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<"-"<<temp->priority<<" ";
        temp=temp->next;
    }
    delete(temp);
    cout<<endl;
}


