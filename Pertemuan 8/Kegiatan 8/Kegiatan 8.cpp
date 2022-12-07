#include <iostream>
#include "xcept.h"
using namespace std;

template <class T> class LinkedQueue;
template <class T> class LinkedStack;
template <class T>
class Node {
    friend LinkedStack<T>;
    friend LinkedQueue<T>;
    private:
        T data;
        Node<T> *link;
};

template<class T>
class LinkedQueue {// FIFO objects 
    public:
        Node<T> *rear; // pointer to last node
        LinkedQueue() {front = rear = 0;}
        ~LinkedQueue(); 
        bool IsEmpty() const
        {return ((front) ? false : true);} 
        bool IsFull() const;
        T First() const; 
        T Last() const;
        LinkedQueue<T>& Add(const T& x); 
        LinkedQueue<T>& Delete(T& x);
    private:
        Node<T> *front; // pointer to first node 
};

template<class T> 
LinkedQueue<T>::~LinkedQueue(){
    Node<T> *next; 
    while (front) {
        next = front->link; 
        delete front; 
        front = next;
    }
}

template<class T>
bool LinkedQueue<T>::IsFull() const{
    Node<T> *p;
    try {p = new Node<T>; 
    delete p;
    return 0;} //false;} 
    catch (NoMem) {return 1;}
}

template<class T>
T LinkedQueue<T>::First() const{
    if (IsEmpty()) throw OutOfBounds(); 
    return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const{
    if (IsEmpty()) throw OutOfBounds(); 
    return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x){ // membuat node elemen baru
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = 0;
    // menambah node baru queue paling belakang
    if (front) rear->link = p; // queue not empty
    else front = p; // queue empty
    rear = p;

    return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x){
    if (IsEmpty()) throw OutOfBounds();
    // menyimpan data elemen terdepan 
    x = front->data;
    // menghapus elemen pertama 
    Node<T> *p = front;
    front = front->link; 
    delete p;
    return *this;
}

main(){
    LinkedQueue<int> Q;
    int x;
    Q.Add(1).Add(2).Add(3).Add(4);
    cout << "No queue add failed" << endl;
    cout << "Queue is now 1234" << endl;
    Q.Delete(x);
    cout << "Deleted " << x << endl;
    cout << Q.First() << " is at front" << endl;
    cout << Q.Last() << " is at end" << endl;
    Q.Delete(x);
    cout << "Deleted " << x << endl;
    Q.Delete(x);
    cout << "Deleted " << x << endl;
    Q.Delete(x);
    cout << "Deleted " << x << endl;
    cout << "No queue delete failed " << endl;
}