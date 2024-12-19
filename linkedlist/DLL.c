// DLL.c
// Implements the operations on a Doubly Linked List (DLL)
// WRITTEN BY: SITAMSH RIJAL

#include <stdio.h>
#include <stdlib.h>

// struct Node represents nodes of a linked list
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} *head; // end struct Node

// function prototypes
void displayInstructions();
void print();
void insertAtFront( int );
void insertAtBack( int );
void insertAtArbitraryLocation( int, int );
void removeFromFront();
void removeFromBack();
void removeByValue( int );
void removeByLocation( int );
struct Node *search( int );
struct Node *getNewNode( int );
void sort();
int length();
void reverse();
int isEmpty();

// start program execution
main()
{
	head = NULL; // the List is empty
	
	int choice; // stores user choice
	
	do
	{
		displayInstructions();
		scanf( "%d", &choice );
		
		switch ( choice ) 
		{
			case 1:
			{
				int value;
				
				printf( "Enter an integer: " );
				scanf( "%d", &value );
				
				insertAtFront( value );
				print(); // print list after insertion
				break;
			}
			case 2:
			{
				int value;
		
				printf( "Enter an integer: " );
				scanf( "%d", &value );
				
				insertAtBack( value );
				print(); // print list after insertion
				break;
			}
			case 3:
			{
				int value, location;

				printf( "Enter an integer and an insert location: ");
				scanf( "%d %d", &value, &location );

				insertAtArbitraryLocation( value, location );
				print(); // prints the list after insertion
				break;
			}
			case 4:
			{
				removeFromFront();
				print(); // prints list after deletion
				break;
			}
			case 5:
			{
				removeFromBack();
				print(); // prints list after deletion
				break;
			}
			case 6:
			{
				int location;

				printf( "Enter a location for deletion: " );
				scanf( "%d", &location );

				removeByLocation( location );
				print( ); // prints the list after deletion
				break;
			}
			case 7:
			{
				int value;

				printf( "Enter an integer: " );
				scanf( "%d", &value );

				removeByValue( value );
				print(); // prints list after deletion
				break;
			}
			case 8:
			{
				sort();
				print(); // prints the sorted list
				break;
			}
			case 9:
			{
				print(); // prints the list
				break;
			}
		} // end switch
	} while ( choice < 10 ); // end do...while
} // end main

// inserts a new node at the front of the list
// new node's key = value
void insertAtFront( int value )
{
	// allocate space for new node to be inserted
	struct Node *newNode = getNewNode( value );

	if ( isEmpty() ) // List is empty		
		head = newNode;
	else // List is not empty
	{
		newNode->next = head;
		newNode->prev = NULL; // newNode is the new first node
		
		head = newNode;
	} // end else
} // end function insertAtFront

// inserts a node at the end of the list
// new node's key = value
void insertAtBack( int value )
{
	// allocate space for a new node
	struct Node *newNode = getNewNode( value );

	if ( isEmpty() ) // List is empty
		head = newNode;
	else 
	{
		struct Node *currentPtr = head;
		
		while ( currentPtr->next != NULL ) // reaches the last node when terminated
			currentPtr = currentPtr->next;
		
		currentPtr->next = newNode;
		newNode->prev = currentPtr;
	} // end else
} // end function insertAtBack

// inserts a node at the specified location with key = value
void insertAtArbitraryLocation( int value, int location )
{
	// allocate space for a new node to be inserted
	struct Node *newNode = getNewNode( value );

	if ( location == 1 ) // insert at the front
		insertAtFront( value );
	else if ( location == length() + 1 )
		insertAtBack( value );
	else
	{
		// traverses the list
		struct Node *currentPtr = head;

		// reaches the node after which the new node should be inserted
		for ( int i = 1; i < location - 1; i++ )
			currentPtr = currentPtr->next;

		newNode->next = currentPtr->next;
		currentPtr->next = newNode;
		
		newNode->prev = currentPtr;
		( newNode->next )->prev = newNode;
	} // end else
} // end function insertAtArbitraryNode

// removes the node at the front of the list
void removeFromFront()
{              
	struct Node *delNode = head;                                                                                           
	if ( isEmpty() ) // List is empty
		printf( "List is empty. Cannot remove.\n" );
	else if ( head->next == NULL ) // List has a single node
		free (delNode); // List is empty after removing the only node
	else // List has more than one nodes
	{
		 // the node to be deleted

		head = head->next; // target the head pointer to the current second node
		head->prev = NULL;

		free( delNode );
	} // end else
} // end function removeFromFront

// removes the node at the end of the list
void removeFromBack()
{
	if ( isEmpty() ) // List is empty
		printf( "List is empty. Cannot remove.\n" );
	else if ( head->next == NULL ) // List has a single node
		removeFromFront();
	else // List has more than one nodes
	{
		struct Node *delPtr = head; // node to be deleted
		
		while ( delPtr->next != NULL ) // reaches the end of the list after stopping
			delPtr = delPtr->next;

		struct Node *prevPtr = delPtr->prev; // previous node of node delPtr
		
		prevPtr->next = NULL;
		delPtr->prev = NULL;

		free( delPtr );
	} // end else
} // end function removeFromBack

// removes the node at a specific location
void removeByLocation( int location )
{
	if ( location < 1 || location > length() )
		printf( "Invalid location" );
	else if ( location == 1 )
		removeFromFront();
	else if ( location == length() )
		removeFromBack();
	else
	{
		struct Node *currentPtr = head;

		// locates the node to be removed
		for ( int i = 1; i < location; i++ )
			currentPtr = currentPtr->next;

		// node before the node to be removed
		struct Node *prevPtr = currentPtr->prev;

		prevPtr->next = currentPtr->next;
		( prevPtr->next )->prev = prevPtr;

		free( currentPtr );
	} // end else
} // end function deleteByLocation

// searches for the first node with the given data field
// and removes it
void removeByValue( int value )
{
	// searches for first node with data field == value
	struct Node *delPtr = search( value );

	if ( delPtr == NULL )
		printf( "Value not found. Cannot remove.\n" );
	else
	{
		if ( delPtr->prev == NULL ) // first node
			removeFromFront();
		else if ( delPtr->next == NULL ) // last node
			removeFromBack();
		else
		{
			struct Node *prevPtr = delPtr->prev;

			prevPtr->next = delPtr->next;
			( prevPtr->next )->prev = prevPtr;

			free( delPtr );
		} // end else
	} // end else
} // end function removeByValue

// is List empty?
// returns 1 if it is; otherwise returns 0
int isEmpty()
{
	if ( head == NULL )
		return 1;
	else
		return 0;
} // end function isEmpty

// display the contents of the list
void print()
{
	if( isEmpty() ) // List is empty
	{
		printf( "\nList is empty.\n\n" );
		return;
	} // end if
	else
	{
		struct Node *currentPtr = head; // start at the head of the list
		
		printf( "\nThe List is: " );
		
		// currentPtr is used to traverse every node in the list
		while ( currentPtr != NULL )
		{
			printf( "%d ", currentPtr->data );
			currentPtr = currentPtr->next;
		} // end while
		
		printf( "\n\n" );
	} // end else
} // end function print

// finds and returns the first node with data == searchKey
struct Node *search( int searchKey )
{
	struct Node *traversePtr = head;
	
	while ( traversePtr != NULL && traversePtr->data != searchKey )
		traversePtr = traversePtr->next;
		
	return traversePtr;
} // end function search

// displays the available operations on a linked list
void displayInstructions()
{
	printf( "Please enter one of the following: \n" );
	printf( " 1 - Insert at the front of the list\n" );
	printf( " 2 - Insert at the end of the list\n" );
	printf( " 3 - Insert at an arbitrary location\n" );
	printf( " 4 - Remove from the front of the list\n" );
	printf( " 5 - Remove from the end of the list\n" );
	printf( " 6 - Remove from any given location\n" );
	printf( " 7 - Remove the first node with a given data field\n" );
	printf( " 8 - Sort the list in incresing order\n" );
	printf( " 9 - Display the contents of the list\n" );
	
	// prompts the user to enter a choice
	printf( "\n? " );
} // end function displayInstructions

// allocates a new node and initializes it
struct Node *getNewNode( int value )
{
	// allocate space for a new node
	struct Node *newNode = ( struct Node * )malloc( sizeof( struct Node ) );

	// initialize the attributes of newNode to appropriate values
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
} // end function getNewNode

// returns the number of nodes in the list
int length()
{
	int count = 0; // number of nodes

	struct Node *currentPtr = head;

	// currentPtr used to traverse the entire list
	while ( currentPtr != NULL )
	{
		count++;
		currentPtr = currentPtr->next;
	} // end while

	return count; // number of nodes
} // end function length

// sorts the linked list in increasing order
void sort()
{
	struct Node *currentPtr, *nextPtr; // i and j in case of ints

	// sorts using bubble sort
	for ( currentPtr = head; currentPtr != NULL; currentPtr = currentPtr->next )
	{
		for ( nextPtr = currentPtr->next; nextPtr != NULL; nextPtr = nextPtr->next )
		{
			if ( currentPtr->data > nextPtr->data )
			{
				// exchnages currentPtr->data with nextPtr->data
				int temp = currentPtr->data;
				currentPtr->data = nextPtr->data;
				nextPtr->data = temp;
			} // end if 
		} // end inner for
	} // end outer for
} // end function sort