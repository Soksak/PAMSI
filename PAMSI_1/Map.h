#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

static const unsigned int capacity=100;

template<typename KeyType, typename ValueType>
class HashNode
{
public:
    ValueType value;
    KeyType key;
    HashNode(KeyType key, ValueType value)
    {
        this->value = value;
        this->key = key;
    }
};

template <typename KeyType, typename ValueType>
class Map{
    HashNode<KeyType,ValueType> **arr;
    HashNode<KeyType,ValueType> *dummy;
    int size;

public:
    Map();
    ~Map();
    int hashCode(KeyType key)
    {
        return key % capacity;
    }
    Map(const Map<KeyType, ValueType>* other);
    void insert(const KeyType& key ,const ValueType& value);
    ValueType& operator[](const KeyType& key);
    void remove(const KeyType& key);
    void display();
    int sizeofMap()
    {
        return size;
    }
};


template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map() {
    arr = new HashNode<KeyType,ValueType>*[capacity];
    int size=0;
    for(int i=0 ; i < capacity ; i++)
        arr[i] = NULL;
    dummy = new HashNode<KeyType,ValueType>(-1, -1);
}

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::~Map() {
    for(int i=0;i<capacity;i++){
        delete(arr[i]);
    };
}

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map(const Map<KeyType, ValueType> *other) {
    other=new HashNode<KeyType,ValueType>*[capacity];
    for(int i=0;i<capacity;i++){
        other[i]=arr[i];
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::insert(const KeyType &key, const ValueType &value) {
    HashNode<KeyType,ValueType> *temp = new HashNode<KeyType,ValueType>(key, value);

    int hashIndex = hashCode(key);
    while(arr[hashIndex] != NULL && arr[hashIndex]->key != key)
    {
        hashIndex++;
        hashIndex %= capacity;
    }
    arr[hashIndex] = temp;
    size++;
}

template <typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::remove(const KeyType &key) {
    int hashIndex = hashCode(key);
    while (arr[hashIndex] != NULL) {
        if (arr[hashIndex]->key == key) {
            HashNode<KeyType, ValueType> *temp = arr[hashIndex];
            arr[hashIndex]=NULL;
            size--;
        }
        hashIndex++;
        hashIndex %= capacity;
    }
}

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType,ValueType>::operator[](const KeyType &key) {
    int hashIndex=hashCode(key);
    while(arr[hashIndex]->key!=key){
        hashIndex++;
        hashIndex %= capacity;
    }
    return arr[hashIndex]->value;
}

template <typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::display()
{
    for(int i=0 ; i<capacity ; i++)
    {
        if(arr[i] != NULL && arr[i]->key != -1)
            cout << "key = " << arr[i]->key
                 <<"  value = "<< arr[i]->value << endl;
    }
}