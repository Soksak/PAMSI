#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Map.h"
using namespace std;
int main() {
    List<int> a;
    cout<<"Działanie listy"<<endl;
    a.pushFront(1);
    a.pushFront(2);
    a.pushFront(3);
    a.pushFront(4);
    cout<<"Dodane elementy przy użyciu push front:"<<endl;
    a.print();
    a.pushBack(1);
    a.pushBack(2);
    cout<<"Dodane elementy przy użyciu push back:"<<endl;
    a.print();
    a.insert(10,4);
    cout<<"Dodanie elementu przy użyciu insert:"<<endl;
    a.print();
    a.remove(3);
    cout<<"Usuniecie elementu przy użyciu remove:"<<endl;
    a.print();
    int r= a[0];
    cout << "przeciazenie operatora []:"<<endl<<r<<endl;
    Stack<int> p;
    cout << endl << "Dzialanie stosu"<<endl;
    p.push(1);
    p.push(2);
    p.push(3);
    cout<<"Stos po dodaniu elementu za pomoca push"<<endl;
    p.print();
    p.pop();
    cout<<"Stos po usunieciu elementu za pomoca pop"<<endl;
    p.print();
    cout << endl << "Dzialanie kolejki"<<endl;
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"Kolejka po dodaniu elementow za pomoca enqueue"<<endl;
    q.print();
    q.dequeue();
    cout<<"Kolejka po użyciu degueue"<<endl;
    q.print();
    cout<<endl<<"Działanie kolejki priorytetowej(dane-priorytet)"<<endl;
    PriorityQueue<int> pq;
    pq.enqueue(1,0);
    pq.enqueue(2,3);
    pq.enqueue(3,2);
    pq.print();
    pq.dequeue();
    cout<<"Kolejka po użyciu degueue"<<endl;
    pq.print();
    cout<<endl<<"Działanie tablicy z haszowaniem"<<endl;
    Map<int, int> *h = new Map<int, int>;
    h->insert(1,1);
    h->insert(2,3);
    cout<<"Tablica po dodaniu par klucz-wartosc przy uzyciu insert"<<endl;
    h->display();
    cout<<"Tablica po usunieciu pary klucz-wartosc przy uzyciu remove"<<endl;
    h->remove(1);
    h->display();
    cout<<"Aktualny rozmiar tablicy  "<<h->sizeofMap()<<endl;


    return 0;

}