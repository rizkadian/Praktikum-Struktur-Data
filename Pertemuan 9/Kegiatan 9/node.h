template <class T> class LinkedQueue;

template <class T>
class Node {
    friend LinkedQueue<T>;
private:
    T data;
    Node<T> *link;
};