#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//static function prototypes
//
//display the data of the node
//
static void displayItem( const Item * pItem );

//show and remove an item
static void showItem( Item * pItem );


//interface functions
//
//initialize the queue
//
Queue initQueue ( void )
{
    Queue ret_val = NULL;
    return ret_val;
}

//if the queue is empty, return 1
//
int isEmpty ( const Queue queue )
{
    return queue ? 0 : 1;
}

//if the queue is full, return 1
//
int isFull ( void )
{
    Node *pNode = ( Node * ) malloc ( sizeof ( Node ) );
    int isFull = pNode ? 0 : 1;
    free ( pNode );
    return isFull;
}

//return the number of items in queue
//
unsigned countQueueNumber ( const Queue queue )
{
    Node *pNode = queue;
    unsigned count = 0;

    if ( !pNode )
        ;
    else
        while ( pNode )
        {
            count ++;
            pNode = pNode->next;
        }

    return count;
}

//push the item into the queue
int EnQueue ( Item item, Queue * pQueue )
{
    if ( isFull () )
        return 0;

    Node *pNode = ( Node * )malloc( sizeof( Node ) );
    pNode->data = item;
    pNode->next = NULL;

    if ( isEmpty( *pQueue ) )
        *pQueue = pNode;
    else
    {
        pNode->next = *pQueue;
        *pQueue = pNode;
    }
    return 1;
}

//pop the item out of the queue
//
Item* DeQueue( Queue * pQueue )
{
    if ( isEmpty( *pQueue ) )
        return NULL;
    else
    {
        Node *pNode = *pQueue;
        int count = countQueueNumber( *pQueue );
        if ( count != 1 )
        {
            int i;
            for ( i = 2; i < count; i++ )
                pNode = pNode->next;
            Node *pTail = pNode->next;

            Item *pItem = ( Item * )malloc( sizeof( Item ) );
            *pItem = pTail->data;
            pNode->next = NULL;
            free( pTail );
            return pItem;
        }
        else
        {
            Item *pItem = ( Item * )malloc( sizeof( Item ) );
            *pItem = pNode->data;
            free( pNode );
            *pQueue = NULL;
            return pItem;
        }
    }
}

//remove the item from the queue and show the item
void showDeQueue( Queue * pQueue )
{
    Item *pItem = DeQueue( pQueue );
    showItem( pItem );
}

//free memory allocated by malloc()
//set queue pointer to NULL
void emptyQueue (Queue * pQueue)
{
	Node * pNode;

	while ( *pQueue )
	{
		pNode = ( *pQueue )->next;
		free( *pQueue );
		*pQueue = pNode;
	}
}

//visit each node and execute function pointed to by pFun
void traverseQueue (Queue queue, void (* pFun)(Item item))
{
	Node * pNode = queue;

	while (pNode != NULL)
	{
		(*pFun)(pNode->data);
		pNode = pNode->next;
	}

	return;
}

//display all the nodes in the queue
void displayQueue ( const Queue queue )
{
    Node * pNode = queue;
    while ( pNode )
    {
        displayItem( &pNode->data );
        pNode = pNode->next;
    }
}

//static functions
//
//display an item
static void displayItem ( const Item * pItem )
{
    if ( pItem )
        printf( "%4d", pItem->number );
    else
        printf( "%4s", " " );
}

//show and remove an items
static void showItem ( Item * pItem )
{
    displayItem ( pItem );
    free ( pItem );
}