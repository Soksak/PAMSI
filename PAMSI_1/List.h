#include <iostream>
using namespace std;

template <typename T>
class List {
    struct Node {
        T value;

        Node* next;
        Node(T d) {
            value = d;
            next = nullptr;
        }
    };

    Node* head; // Wskaźnik do głowy listy.
    Node* tail; // Wskaźnik do ogona listy.

public:
    class iterator {
        friend class list;
    private:
        Node *nodePtr;
        iterator(Node *newPtr) : nodePtr(newPtr) {}
    public:
        iterator() : nodePtr(nullptr) {}
        bool operator!=(const iterator& itr) const {
            return this->Node != itr.nodePtr;
        }

        T& operator*() const {
            return nodePtr->next->data;
        }

        iterator operator++(int) {
            iterator temp = *this;
            nodePtr= nodePtr->next;
            return temp;
        }
    };
    List();
    ~List();
    List(const List& obj);
    void pushBack(const T& newElement );
    void pushFront(const T& newElement);
    void insert(const T& newElement ,int index);
    void remove(const T& element);
    void print();
    iterator  begin (){
        return iterator(head);
    };
    iterator  end(){
        return iterator(tail);
    };
    T& operator[](int index);
};



template <typename T>
void List<T>::print() {
    Node* temp=head;
    cout << "Elementy listy:"<<endl;
    while(temp!=tail){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout <<endl;
}
template <typename T>
List<T>::List() {

    head = nullptr;

    tail = nullptr;

}

template <typename T>
List<T>::~List() {

    Node* temp = head;
    while (temp != nullptr) {    //
        head = temp->next;
        delete temp;
        temp = head;
    }
    delete tail;
}

template <typename T>
List<T>::List(const List & obj)
{
    if (obj.head == NULL) {
        head = NULL;
    }
    else {
        head = new Node(obj.head->value);
        Node *current = head;
        Node *objHead = obj.head;
        Node *currentObj = objHead;
        while (currentObj->next != NULL) {
            current->next = new Node(currentObj->next->value);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
}
template <typename T>
void List<T>::pushBack(const T& newElement) {
    Node* temp = new Node(newElement);
    temp->value=newElement;
    Node* pCurrent = head;
    if( pCurrent != NULL ){
        while (pCurrent->next != NULL)
            pCurrent = pCurrent->next;


        pCurrent->next = temp;
    } else {
        pCurrent = temp;
    }
}





template <typename T>
void List<T>::pushFront(const T &newElement) {
    Node* temp= new Node(newElement);
    temp->value=newElement;
    temp->next=head;
    head=temp;
}

template <typename T>
void List<T>::insert(const T &newElement, int index) {
    Node* temp=head;
    Node* prev = nullptr;
    Node* change=new Node(newElement);

    for(int i=1; i<index;i++){
        if (temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        else{
            cout << "Lista jest krótsza niż argument w remove!";
            i=index;
        }
    }
    prev->next=change;
    change->next=temp;
    change->value=newElement;

}

template <typename T>
void List<T>::remove(const T &element) {
    Node* temp = head;
    Node* prev = nullptr;
    while (temp->value!=element){  // W pętli będziemy szukać elementu do usuniecia.
        if (temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        else
            throw "Lista jest krótsza niż argument w remove!";
    }
    prev->next = temp->next;
    delete temp;
}

template< typename T >
T& List<T>::operator[](int index) {
    Node *current=new Node(0);
    int i = 0;

    for(current = head;current != NULL;current = current->next) {
        if(i == index) {
            return current->value;
        }
        i++;
    }
}