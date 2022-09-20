//
// Created by Gianmarco  Caruso on 14/09/22.
//

#include "DoubleLinkListT.h"
#include <climits>

template<typename T>
DoubleLinkListT<T>::DoubleLinkListT() {
    head = new NodeT<T>;
    tail = new NodeT<T>;
    head->next = tail;
    tail->prev = head;
    size = 0;
}

template<typename T>
DoubleLinkListT<T> *DoubleLinkListT<T>::headInsert(T y) {
    NodeT<T>* n = new NodeT<T>();
    n->val = y;
    NodeT<T>* x = head->next;

    head->next = n;
    n->next = x;

    n->prev = head;
    x->prev = n;

    size++;
    return this;
}

template<typename T>
DoubleLinkListT<T> *DoubleLinkListT<T>::tailInsert(T y) {
    NodeT<T>* n = new NodeT<T>();
    n->val = y;

    NodeT<T>* x = tail->prev;

    n->next = tail;
    x->next = n;
    n->prev = x;
    tail->prev = n;

    size++;
    return this;
}

template<typename T>
NodeT<T> *DoubleLinkListT<T>::_search(T x) {
    NodeT<T>* tmp = head;
    while(tmp->next != tail){
        tmp = tmp->next;
        if(tmp->val == x){
            return tmp;
        }
    }
    return nullptr;
}

template<typename T>
T& DoubleLinkListT<T>::search(T x) {
    NodeT<T>* tmp = _search(x);

    if(tmp) return tmp->val;
    T err;
    return err;
}

template<typename T>
DoubleLinkListT<T>* DoubleLinkListT<T>::deleteItem(T val) {
    NodeT<T>* x = _search(val);
    if(!x) return this;

    NodeT<T>* pred = x->prev;
    NodeT<T>* succ = x->next;

    pred->next = succ;
    succ->prev = pred;

    delete x;
    size--;

    return this;
}


template<typename T>
DoubleLinkListT<T>* DoubleLinkListT<T>::deleteAllItem(T x) {
    NodeT<T>* tmp = head;

    while(tmp->next != tail) {
        tmp = tmp->next;
        if(tmp->val == x) {
            NodeT<T>* y = tmp;
            NodeT<T>* pred = y->prev;
            NodeT<T>* succ = y->next;
            pred->next = succ;
            succ->prev = pred;
            delete y;
            tmp = succ->prev;
            size--;
            if(tmp == tail) return this;
        }
    }
    return this;
}

template<typename T>
T* DoubleLinkListT<T>::iterator() {
    if(current == nullptr || current->next == tail) {
        current = nullptr;
        return nullptr;
    }
    current = current->next;
    return new T(current->val);
}

template<typename T>
void DoubleLinkListT<T>::sort() {
    NodeT<T>* tmp = head;
    NodeT<T>* minN = head;
    NodeT<T>* start = head;

    while(tmp->next != tail) {
        tmp = tmp->next;
        T min = tmp->val;
        minN = tmp;
        start = tmp;

        while(start->next != tail) {
            start = start->next;
            if(start->val < min) {
                min = start->val;
                minN = start;
            }
        }

        if(tmp != minN) { //TODO Capire if e vedere con Luigi se ho capito bene i passaggi prima
            minN->val = tmp->val;
            tmp->val = min;
        }
    }
}


template<typename T>
int DoubleLinkListT<T>::getSize() {
    return size;
}

template<typename T>
std::ostream &DoubleLinkListT<T>::put(std::ostream &os) {
    NodeT<T>* tmp = head;
    os << "H -> ";
    while(tmp->next != tail){
        tmp = tmp->next;
        os << tmp->val << " -> ";
    }
    os << "T";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoubleLinkListT<T>& obj) {
    return obj.put(os);
}

template<typename T>
T& DoubleLinkListT<T>::operator[](int i) {
    NodeT<T>* tmp = head;
    int count = 0;

    while(tmp->next != tail) {
        tmp = tmp->next;
        if(count == i) return tmp->val;
        count++;
    }
    T* err = new T();
    return *err;
}

//TODO Chiedere se va bene messo qui riga 164-167(era nel main e l'ho spostato)


