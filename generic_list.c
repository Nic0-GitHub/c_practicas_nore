#include <stdlib.h>
#include <stdbool.h>
#define LIST_DATA_TYPE int
#define LIST_DATA_NAME data


typedef struct l{
    LIST_DATA_TYPE LIST_DATA_NAME;
    struct l *next;
}SimpleList;

typedef struct l2{
    LIST_DATA_TYPE LIST_DATA_NAME;
    struct l2 *prev;
    struct l2 *next;
}DoubleList;


typedef SimpleList* List;
typedef SimpleList* Node;

// creates a node with the data passed
Node createNode(LIST_DATA_TYPE data);

// add a node to the list (at start).
void appendNode(List* l, Node node);

// add a node to the list (at end).
void queueNode(List* l, Node node);

// quit a node of the list.
Node deQueueNode(List* l);

// add a node to the list if posible (at anywhere).
int insertNode(List* l, int index, Node node);

// delete a node of the list.
void deleteNode(List *l, int index);

// return the element if found.
Node searchNodeById(List l, int id);

// return the element if found.
Node searchNodeByIndex(List l, int index);

// return a new filtered list based on the function given
List filter(List l, bool (*function)(Node node));

// return a copy of every element of the list.
List copy(List l);

// return the size of nodes that a list has
int listSize(List l);


//////////////////////////////////////////////////////////////////////////////////////////

Node createNode(LIST_DATA_TYPE data)
{
    Node newNode = (Node) malloc( sizeof(SimpleList) );

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
};

void appendNode(List* l, Node node)
{
    if ((*l) == NULL){
        (*l) = node;
        return;
    }
    List aux =(*l)->next;

    while (aux->next != NULL) aux = aux->next;

    aux->next = node;
    node->next = NULL;
};

void queueNode(List* l, Node node)
{
    node->next = *l;
    *l = node;
};

Node deQueueNode(List* l)
{
    if ((*l) == NULL) return NULL;

    Node aux = *l;
    *l = (*l)->next;
    return aux;
};

int insertNode(List* l, int index, Node node)
{
    int i = 0;

    if (index == 0) {
        (*l) = node;
        return 0;
    }

    for (Node n = (*l); (n != NULL) ; n = n->next, ++i){
        if (i == index){
            node->next = n->next;
            n->next = node;
            return 0;
        }
    }

    return -1;
};

Node searchNodeById(List l, int id)
{
    for (Node n = l; (n != NULL) ; n = n->next){
        // FIXME: xd
        if (n->LIST_DATA_NAME.id == id) return n;
    }

    return NULL;
};

Node searchNodeByIndex(List l, int index)
{
    int i = 0;
    for (Node n = l; (n != NULL) ; n = n->next, ++i) if (i == index) return n;

    return NULL;
};

List filter(List l, bool (*filterFunction)(Node node))
{
    List new_list = NULL;

    for (Node n = l; (n != NULL) ; n = n->next)
    {
        if (filterFunction(n))
        {
            appendNode(&new_list, createNode(n->data));
        }
    }
    return new_list;
};

List copy(List l)
{
    List newList = NULL;

    Node auxNode;
    for (Node n = l; (n != NULL) ; n = n->next)
    {
        auxNode = (Node) malloc(sizeof(SimpleList));
        auxNode->LIST_DATA_NAME = n->LIST_DATA_NAME;
        auxNode->next = NULL;

        appendNode(&newList, auxNode);
    }
   return newList;
};

int listSize(List l)
{
    int i = 0;
    for (Node n = l; (n != NULL) ; n = n->next) ++i;
    return i;
}