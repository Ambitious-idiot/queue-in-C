//queue.h--head file for a queue
#ifndef QUEUE_H_
#define QUEUE_H_

//program-specific definitions

typedef struct ITEM{
	int number;
}Item;

//general type definitions

typedef struct node {
    Item data;
    struct node *next;
} Node, *Queue;

//function prototypes

//operation:	    initialize a queue
//postconditions:	the queue is initialized to empty
Queue initQueue ( void );

//operation:		determine if queue is empty
//preconditions:	pQueue points to an initialized queue
//postconditions:	function returns 1 if queue is empty
//					and returns 0 otherwise
int isEmpty ( const Queue queue );

//operation:		determine if queue is full
//preconditions:	pQueue points to an initialized queue
//postconditions:	function returns True if queue is full
//					and returns False otherwise
int isFull ( void );

//operation:		determine number of items in queue
//preconditions:	pQueue points to an initialized queue
//postconditions:	function returns number of items in queue
unsigned int countQueueNumber ( const Queue queue );

//operation:		push item into queue
//preconditions:	pQueue points to an initialized queue
//					item is an item to be pushed to queue
//postconditions:	if possible, function push item into queue
//					 and returns True; otherwise the
//					function returns False
int EnQueue ( Item item, Queue * pQueue );

//operation:		apply a function to each item in queue
//preconditions:	pQueue points to an initialized queue
//					pFun points to a function that takes an
//					Item argument and has no return value
//postconditions:	the function pointed to by pFun is
//					executed once for each item in the queue
void traversequeue ( Queue queue, void ( *pFun )( Item item ) );

//operation:		pop an item out of the queue
//preconditions:	pQueue points to an initialized queue
//					item is an item to be popped
//postconditions:	if possible, function delete item in the
//					queue and returns its item; otherwise the
//					function returns NULL
Item *DeQueue ( Queue * pQueue );


//operation:		pop an item out of the queue and show its item
//preconditions:	pQueue points to an initialized queue
//postconditions:    if possible, function delete item in the queue and
//			      show its item; otherwise the function shows nothing
void showDeQueue ( Queue * pQueue );

//operation:		free allocated memory
//preconditions:	pQueue points to an initialized queue
//postconditions:	any memory allocated for the queue is
//					freed, and the queue is set to empty
void emptyQueue ( Queue * pQueue );

//operation:        display the queue
//preconditions:	pQueue points to an initialized queue
//postconditions:   all the items in the queue are shown
void displayQueue ( const Queue queue );

#endif