#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;
using std::string;

/*
    that's my vision for imaginng Linked list in memory

    head --> Node [ data | next ] -> Node(prev) [ data | next ] -> Node(cursor) [ data | next ] -> tail [ data | NULL ]
*/

LinkedList::LinkedList()
{
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

LinkedList::~LinkedList()
{
    makeEmpty();
}


// exercises
int LinkedList::getMiddle() {
    if (isEmpty())
        return -1;

    int size = listSize();
    int middle = size / 2;

    NodePointer temp = head;
    int i = 0;
    while (i < middle) {
        temp = temp->next;
        i++;
    }

    return temp->data.id;
}


bool LinkedList::Sorted() {
    if (isEmpty()) return true;

    NodePointer node = head;
    while (node->next != nullptr) {
        if (node->data.id > node->next->data.id)  return false;
        node = node->next;
    }

    return true;
}




void LinkedList::reverse() {
    if (isEmpty()) return;

    NodePointer prevNode = new NodePointer();
    NodePointer nextNode;

    toFirst();

    while (!isCursorEmpty()) {
        nextNode = cursor->next;
        cursor->next = prevNode;
        prevNode = cursor;
        cursor = nextNode;
    }

    head = prevNode;
}



void LinkedList::selectionSort() {
    if (isEmpty()) return;

    toFirst()
    while (cursor->next != NULL) {
            // !
    }
}

void LinkedList::insertionSort() {
    if (isEmpty() || head->next == nullptr) return;

    NodePointer sorted = new NodePointer();
    NodePointer current;

    toFirst();
    current = cursor;

    while (current->next != NULL) {
        NodePointer nextNode = current->next;
        if (sorted->next == NULL || current->data.id < sorted->data.id) {
            current->next = sorted;
            sorted = current;
        } else {
            NodePointer temp = sorted;
            while (temp->next != NULL && temp->next->data.id < current->data.id) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }

    head = sorted;
}

int LinkedList::size(NodePointer h) {
    if (h->next == NULL) return 0;
    return 1 + size(h->next);
}

int LinkedList::RecursiveSize() {
    return size(head);
}

void LinkedList::Dispaly() {
    display(head);
}

void LinkedList::display(NodePointer h) {
    if (h == nullptr) return;
    cout << "Employee ID: " << h->data.id << ", Employee Name: " << h->data.name << endl;
    display(h->next);
}


bool LinkedList::isEmpty() const
{
    return head == NULL ? true : false;
}

bool LinkedList::isCursorEmpty() const
{
    return cursor == NULL ? true : false;
}

void LinkedList::toFirst()
{
    cursor = head;
    prev = NULL;
}

bool LinkedList::atFirst() const
{
    return cursor == head ? true : false;
}

void LinkedList::advance()
{
    /* [data|next]->[data|next]->.... */
    prev = cursor;
    cursor = cursor->next;
}

bool LinkedList::atEnd() const
{
    if (isEmpty()) // Node == null
        return true;

    if (isCursorEmpty()) //
        return false;

    return cursor->next == NULL; // in the tail
}

void LinkedList::toEnd()
{
    if (!isEmpty())
    {
        while (cursor->next != NULL)
        {
            prev = cursor;
            cursor = cursor->next;
        }
    }
}

//  int listSize() const;

int LinkedList::listSize() const
{
    int size = 0;

    if (isEmpty())
        return size;

    while (cursor->next != NULL)
    {
        cursor->next;
        size++;
    }

    return size;
}

// void updateData(const char &)

void LinkedList::updateData(const int &id, int &name)
{

    if (!isEmpty())
    {
        while (cursor->next != NULL)
        {
            if (cursor->data.id == id)
            {
                cursor->data.name = name;
            }
            cursor = cursor->next;
        }
    }
}

bool LinkedList::retrieveData(int id, Data &outData) const
{
    NodePointer newNode = head;
    while (newNode != nullptr)
    {
        if (newNode->data.id == id)
        {
            outData = newNode->data;
            return true;
        }
        newNode = newNode->next;
    }
    return false;
}

void LinkedList::insertFirst(const int &id, const string &name)
{
    toFirst();
    NodePointer newNode = new NodePointer;
    newNode->data.id = id;
    newNode->data.name = name;

    // change roles
    newNode->next = head;
    head = newNode;
    cursor = newNode;
    prev = NULL;
}

void LinkedList::insertAfter(const int &id, const string &name)
{
    NodePointer newNode = new NodePointer;
    newNode->data.id = id;
    newNode->data.name = name;

    newNode->next = cursor->next;
    cursor->next = newNode;
}

void LinkedList::insertBefore(const int &id, const string &name)
{
    NodePointer newNode = new NodePointer;
    newNode->data.id = id;
    newNode->data.name = name;

    newNode->next = cursor;
    prev->next = newNode;
    cursor = newNode
}

void LinkedList::insertEnd(const int &id, const string &name)
{
    if (isEmpty())
    {
        insertFirst(id, name)
    }
    else
    {
        toEnd();
        insertAfter(id, name)
    }
}

void LinkedList::deleteNode()
{
    NodePointer newNode;
    if (!isCursorEmpty())
    {
        if (atFirst())
        {
            newNode = cursor;
            cursor = cursor->next;
            head = cursor;
            delete newNode;
        }

        else
        {
            newNode = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete newNode;
        }
    }
}

void LinkedList::deleteFirst()
{
    if (!isEmpty())
    {
        toFirst();
        deleteNode();
    }
}
void LinkedList::deleteEnd()
{
    if (!isEmpty())
    {
        toEnd();
        deleteNode();
    }
}

void LinkedList::makeListEmpty()
{
    toFirst();
    while (!isEmpty())
        deleteNode();
}

bool LinkedList::search(const int &id)
{
    bool found = false;
    toFirst();
    while (!found && cursor != NULL)
        cursor->data.id == id ? found = true : advance();
    return found;
}

void LinkedList::orderInsert(const string &name, const int &id)
{
    toFirst();
    while ((cursor != NULL) && (id > cursor->id))
        advance();

    prev == NULL ? insertFirst(id, name) : insertBefore(id, name);
}

void LinkedList::traverse()
{

    toFirst();
    while (!isCursorEmpty())
    {
        cout << cursor->data << endl;
        advance();
    }
}