#include <iostream>
#include "List.h"
using namespace std;

	List:: List()
	// post condition: A list object is initialized to be empty.
	{
		first = NULL;
	}
	
	List:: List(const List & source)
	// pre condition: the source list must be a valid linked list object
	// post condition: the list is intialized as a copu of the source list.
	{
		Node * p;
		Node * last;
		
		if (source.first == NULL)
			first = NULL;
		else
		{
			first = get_node(source.first -> data , NULL);
			last = first;
			p = source.first -> next;
			
			
			while (p!= NULL)
			{
				last -> next = get_node(p->data, NULL);
				last = last -> next;
				p = p-> next;
			}
		}
	}
	
	//Destructor
	List:: ~List()
	// post condition: The lest is made empty.
	{
		Node * temp;
		
		while(first != NULL)
		{
			temp = first;
			first = first -> next;
			delete temp;
		}
		
	}
	
	// modification member functions 
		
	void List:: make_empty()
	// pre condition: a linked list has to exist to call this function
	// post condition: the contents of the list are deleted and an empty list is made.
	{
		Node * temp;
		
		while(first != NULL)
		{
			temp = first;
			first = first -> next;
			delete temp;
		}
	}
	
	
	void List:: insert(const Item& entry)
	// pre condition: the item entry must be of type int
	// post condition: the item is added to the linked list in the correct order.
	{
		Node * pre;
		if(first == NULL || entry < first -> data)
			first = get_node(entry, first);
		else
		{
			pre = first;
			while (pre -> next != NULL && pre -> next -> data < entry)
				pre = pre -> next;
			pre -> next = get_node(entry, pre -> next);
		}
	}
	
	
	void List:: remove (const Item& target)
	// pre condition: the target must be an integer.
	// post condition: the target value is removed from the list if it is a value
	// that is in the list.
	{
		Node * pre = first;
		Node * temp;
		
		if (first -> data == target )
		{
			first = first -> next;
			delete pre;
		}
		
		else
		{
			while (pre -> next -> data != target)
				pre = pre -> next;
			
			temp = pre -> next;
			pre -> next = temp -> next;
			delete temp;
		}
	}
	
	void List:: operator = (const List& source)
	// pre condition: the source list must be a valid linked list
	// post condition: the = operator is overidden so that the data members
	// of the linked list are copied over as well and not just the pointer values.
	{
		Node * p;
		Node * last;
		
		if (&source.first != NULL)
		{
			make_empty();
			
			if(source.first != NULL)
			{
				first = get_node(source.first -> data , NULL);
				last = first;
				p = source.first -> next;
			
			
				while (p!= NULL)
				{
					last -> next = get_node(p->data, NULL);
					last = last -> next;
					p = p-> next;
				}
				
			}
		}
	}
		
	void List :: print ()
	//post condition: the contents of the linked list are printed out to the terminal.
	{
		Node *cursor;

    for ( cursor=first; cursor != NULL; cursor=cursor->next )
      cout << cursor ->data << " ";
		
	cout << endl;
	}
		
	// constant member functions
	bool List :: is_empty()
	// pre condition: A link list is initialized
	// post condition: determines weather or not a list is empty.  
	// if it is empty it will return true otherwise it will return false.
	{
		if (first == NULL)
			return true;
		else 
			return false;
	}

	
	 size_t List::length( )
	 // pre condition: a link list is initialized 
	 // post condition: returns the length of the list.
  {
    Node *cursor;
    size_t count;

    count = 0;
    for ( cursor=first; cursor != NULL; cursor=cursor->next )
      ++count;
    return count;
  }
	
	bool List :: present(const Item& target)
	// pre condition: the target value is of the type integer.
	// post condition: If the target value is in the list true will be returned 
	// otherwise the function returns false.
	{
		Node * p = first;
		while (p != NULL && p-> data != target)
			p = p-> next;
		
		return p!= NULL;
	}
	
	int List :: kth (Item& k)
	// pre condition: k must be an integer
	// post condition: the function returns the value of the kth number in the list.
	{
		Node * p = first;
		int i;
		
		for (i=1; i<k;i++)
			p = p-> next;
		
		return p -> data;
	}
	
	void List :: Merge(List L1, List L2, List  & L3)
	// pre condition: three list objects must be initialized 
	// post condition: The contents of the first two lists are merged 
	// and stored in the third list.  Duplicates are removed from the list.
	{
		L3 = L1;
		
		Node *cursor;
		Node * p = L2.first;

		for ( cursor=L3.first; cursor != NULL; cursor=cursor->next )
		{
			while(p!=NULL)
			{
				if(p != cursor)
					if(!L3.present(p->data))
						L3.insert(p->data);
				p = p->next;
			}
		}
		
	}
	
	ostream& operator << ( ostream& out_s, const List& l )
	// pre condition: a list object is initialized and and outstream is available 
	// post condition: The contents of the list are outputted to a stream.
  {
    List::Node *cursor;

    out_s << '(';
    for ( cursor=l.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
      out_s << cursor->data << ", ";
    if ( cursor != NULL )
      out_s << cursor->data;
    out_s << ')';

    return out_s;
  }

	//Private member functions
	List::Node* List::get_node ( const Item& entry, Node* link )
	// pre condition: entry is of the type integer and a pointer value link exists
	// post condition: returns the pointer to the specific node that the user is looking for.
  {
    Node *temp;

    temp = new Node;
    temp->data = entry;
    temp->next = link;
    return temp;
  }

