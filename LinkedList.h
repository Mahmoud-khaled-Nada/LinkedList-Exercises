#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

/*
    * student notes
    - I image {.h} file like interface in other programing language
    - we can here initialis the methods and even args
*/
class LinkedList
{
private:
    struct Data
    {
        int id;
        string name;
    };
    class Node
    {
    public:
        Data data;
        Node *next;
    };

    typedef Node *NodePointer;

    // Pointers
    NodePointer head, cursor, prev;

    // exercises
    int size(NodePointer h);
    void display(NodePointer h);

public:
    /* Create an empty LinkedList Constructor */
    LinkedList();

    /* Destructor */
    ~LinkedList();

    bool isEmpty() const;       // done
    bool isCursorEmpty() const; // done

    void toFirst();       // done
    bool atFirst() const; // done

    bool atEnd() const; // done
    void toEnd();       // done

    void advance(); // done

    int listSize() const;                // done
    void updateData(const int &, int &); // done
    bool retrieveData(int id, Data &outData) const;
    void retrieveData(int &, Data &) const; // done
    void insertFirst(const int &, const string &); // done
    void insertAfter(const int &, const string &); // done
    void insertBefore(const int &, const string &);// done
    void insertEnd(const int &, const string &); // done
    void deleteNode();  // done
    void deleteFirst();  // done
    void deleteEnd();  // done
    void makeEmpty();// done
    bool search(const int &); // done
    void orderInsert(const string &, const int &); // done
    void traverse();

    // exercises
    int getMiddle();
    void reverse();
    bool Sorted();
    void selectionSort();
    void insertionSort();
    int RecursiveSize();
    void Dispaly();
};
#endif