#include <iostream>
using namespace std;


class List
  {
    public:
    // TYPEDEF
      typedef int Item;                   // The data type of the items in a list.

    // CONSTRUCTORS
      List() ;          // Inline
      List(const List& source );         // Copy constructor

    // DESTRUCTOR
      ~List( );

    // MODIFICATION MEMBER FUNCTIONS
      void make_empty ( );
      void insert ( const Item& entry );
      void remove ( const Item& target );
      void operator = ( const List& source );

    // CONSTANT MEMBER FUNCTIONS
      bool is_empty( );
      std::size_t length( );
      bool present ( const Item& target );
      Item kth (Item& k);
	  void Merge (List, List, List &);
	  void print();

    // FRIEND FUNCTION for the List class:
      friend std::ostream& operator << ( std::ostream& out_s,
                                         const List& l );
    private:
    // DATA MEMBERS
      struct Node
      {
        Item data;
        Node *next;
      };
      Node *first;

    // PRIVATE FUNCTION
      Node* get_node ( const Item& entry, Node* link );
  };


 






		