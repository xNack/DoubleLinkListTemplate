//
// Created by Gianmarco  Caruso on 14/09/22.
//

#ifndef DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_DOUBLELINKLISTT_H
#define DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_DOUBLELINKLISTT_H
#include "NodeT.h"
#include <iostream>

template<typename T>
class DoubleLinkListT {

private:
    NodeT<T>* head;
    NodeT<T>* tail;
    NodeT<T>* current;
    int size;

    /**
     * @brief Support function for search
     * @param x
     * @return NodeT<T>
     */
    NodeT<T>* _search(T x);

public:

    /**
     * @brief Construct a new DoubleLinkListT object
     */
    DoubleLinkListT();

    /**
     * @brief Head Inserting of an element inside the DoubleLinkListT
     * @param x
     * @return DoubleLinkListT<T>
     */
    DoubleLinkListT<T>* headInsert(T x);

    /**
     * @brief Tail Inserting of an element inside the DoubleLinkListT
     * @param x
     * @return DoubleLinkListT<T>
     */
    DoubleLinkListT<T>* tailInsert(T x);

    /**
     * @brief Search an item inside the object
     * @param x
     * @return T&
     */
    T& search(T x);

    /**
     * @brief Delete an item inside the DoubleLinkListT
     * @param val
     * @return
     */
    DoubleLinkListT<T>* deleteItem(T val);

    /**
     * @brief Delete all items with the same value inside the DoubleLinkListT
     * @param val
     * @return
     */
    DoubleLinkListT<T>* deleteAllItem(T x);

    /**
     * @brief Inizialiting of Iterator
     */
    void initIterator() { current = head; }

    /**
     * @brief Iterator
     * @return
     */
    T* iterator();

    /**
     * @brief Sort the DoubleLinkListT
     */
    void sort();

    /**
     * Return Size of DoubleLinkListT
     * @return int
     */
    int getSize();

    /**
     * Printing of DoubleLinkListT
     * @param os
     * @param obj
     * @return std::ostream
     */
     std::ostream& put(std::ostream& os);

    /**
     * @brief Overloading []
     * @param i
     * @return
     */
     T& operator[](int i);

};

#include "DoubleLinkListT.tpp"
#endif //DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_DOUBLELINKLISTT_H
