//driver program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define SIZE 10
int main( void )
{
    srand ( ( unsigned ) time( NULL ) );

    Queue queue = initQueue();
    int i;
    printf( "%d\n", isEmpty( queue ) );

    for ( i = 0; i < SIZE; i++ )
        if ( !isFull() )
        {
            Item item;
            item.number = rand() % 100 + 1;
            EnQueue( item, &queue );
        }
    printf("\nEnqueue result:\n");
    displayQueue( queue );
    printf("\nTotal %d nodes\n", countQueueNumber( queue ) );

    printf("\nDequeue result:\n");
    while( !isEmpty( queue ) )
        showDeQueue( &queue );
    printf("\nTotal %d nodes\n", countQueueNumber( queue ) );

    emptyQueue( &queue );

    getchar();

    return 0;
}