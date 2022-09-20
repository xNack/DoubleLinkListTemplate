//
// Created by Gianmarco  Caruso on 14/09/22.
//

#ifndef DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_NODET_H
#define DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_NODET_H

template<typename T>
class NodeT {

public:
    NodeT<T>* next;
    NodeT<T>* prev;
    T val;

};


#endif //DOUBLE_LINK_LIST_TEMPLATE_PRO_GIANMARCO_NODET_H
