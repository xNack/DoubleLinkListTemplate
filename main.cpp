#include <iostream>
#include "DoubleLinkListT.h"

using namespace std;

int main() {

    DoubleLinkListT<string> *l1 = new DoubleLinkListT<string>();
    DoubleLinkListT<double> *l2 = new DoubleLinkListT<double>();
    DoubleLinkListT<int> *l3 = new DoubleLinkListT<int>();
    DoubleLinkListT<short> *l4 = new DoubleLinkListT<short>();
    DoubleLinkListT<string> *l5 = new DoubleLinkListT<string>();

    l1->headInsert("O")->headInsert("S")->headInsert("S")->headInsert("O");
    l2->headInsert(4.52)->headInsert(6.89)->headInsert(7.124)->headInsert(2.0563);
    l3->headInsert(0)->headInsert(1)->headInsert(2)->tailInsert(3)->headInsert(4);
    l4->tailInsert(1)->tailInsert(1)->tailInsert(1)->tailInsert(1)->tailInsert(1);
    l5->headInsert("Gianmarco")->headInsert("Alessia")->headInsert("Zante")->headInsert("Ludovica");


    cout << "l1<string>(head insert): " << *l1 << endl;
    cout << "l2<double>(head insert): " << *l2 << endl;
    cout << "l3<int>(head insert): " << *l3 << endl;
    cout << "l4<short>(tail insert): " << *l4 << endl;
    cout << "l5<string>(head insert): " << *l5 << endl << endl;

    cout << "La dimensione della lista l1<string> è di " << l1->getSize() << " elementi. " << endl;
    cout << "La dimensione della lista l2<double> è di " << l2->getSize() << " elementi. " << endl;
    cout << "La dimensione della lista l4<short> è di " << l4->getSize() << " elementi. " << endl << endl;

    //Cerco un valore all'interno della lista e lo modifico mediante il puntatore
    cout << "Ricerca valore 'O' all'interno della lista l1<string> e lo modifico con il valore 'Luigi'(se è presente ovviamente)" << endl;
    cout << *l1 << endl;
    cout << "Invocazione funzione l1->search():" << endl;
    cout << "l1->search = 'Luigi'" << endl;
    l1->search("O") = "Luigi";
    cout << *l1 << endl << endl;

    //Cancello un valore mediante la funzione deleteItem()
    cout << "Eliminazione singolo elemento 'Luigi' dalla lista l1<string> (se è presente ovviamente)" << endl;
    cout << *l1 << endl;
    cout << "Invocazione funzione l1->deleteItem():" << endl;
    l1->deleteItem("Luigi");
    cout << *l1 << endl << endl;

    //Cancello tutti i valori 1 dalla DoubleLinkListT
    cout << "Elminazione di tutti i valori '1' dalla lista l4<short>" << endl;
    cout << *l4 << endl;
    cout << "Invocazione funzione l4->deleteAllItem():" << endl;
    l4->deleteAllItem(1);
    cout << *l4 << endl << endl;

    //Cancello tutti i valori "S" dalla DoubleLinkListT
    cout << "Eliminazione di tutti i valori 'S' dalla lista l1<string>" << endl;
    cout << *l1 << endl;
    cout << "Invocazione funzione l1->deleteAllItem():" << endl;
    l1->deleteAllItem("S");
    cout << *l1 << endl << endl;

    //TODO Chiedere se iterator tornava elemento corrente o primo elemento
    //Test iterator
    cout << "Elemento corrente l1<string>: ";
    l1->initIterator();
    cout << *(l1->iterator()) << endl << endl;

    cout << "Elemento corrente l2<double>: ";
    l2->initIterator();
    cout << *(l2->iterator()) << endl << endl;

    //TODO Capire sort() in particolare l'if finale nella funzione
    cout << "Sorting della lista l3<int>: " << endl;
    cout << *l3 << endl;
    l3->sort();
    cout << "Invocazione funzione l3->sort(): " << endl;
    cout << *l3 << endl << endl;

    cout << "Sorting della lista l5<string>: " << endl;
    cout << *l5 << endl;
    l5->sort();
    cout << "Invocazione l5->sort(): " << endl;
    cout << *l5 << endl << endl;

    cout << "Overloading membro [] per stampare in modo diretto un elemento specifico della lista l5<string> " << endl;
    cout << *l5 << endl;
    for(int i=0;i<l5->getSize();i++) {
        cout << "(*l5)[" << i << "]:" << (*l5)[i] << endl;
    }
    cout << endl;

    cout << "Overloading membro [] per stampare in modo diretto un elemento specifico della lista l3<int> " << endl;
    cout << *l3 << endl;
    for(int i=0;i<l3->getSize();i++) {
        cout << "(*l3)[" << i << "]:" << (*l3)[i] << endl;
    }

    return 0;
}
