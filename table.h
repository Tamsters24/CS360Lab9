// Chapter 11 of C++ How to Program
// table.h
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
using std::ostream;
using std::istream;
#include <new>
/* CS360: Write code that specifies Table as a class template
   with type parameter T */
class Table {
public:
    Table( int = 10, int = 10 );  // default constructor
    Table( const Table<  > & ); // copy constructor
    ~Table();

    void print() const;
    void inputValues();
    const Table<  > &operator=(
            const Table<  > & );
    bool operator==( const Table<  > & ) const;
    // determine if two arrays are not equal and
    // return true, otherwise return false (uses operator==)
    bool operator!=( const Table<  > &right ) const {
        return !( *this == right );
    }
    T &operator()( int, int );
    const hmmm &operator()( int, int ) const;
private:
    int rows;             // number of rows in array
    int columns;          // number of columns in array
    /* CS360: Write declaration for private data member ptr, a pointer to a
   parameterized dynamically allocated array */
}; // end class Table
// default constructor
template < class   >
Table<   >::Table( int r, int c ) {
    rows = ( r > 0 ? r : 10 );
    columns = ( c > 0 ? c : 10 );
    /* CS360: Write code to allocate dynamically an array with rows *
       columns elements of type T */
    for ( int i = 0; i < rows * columns; i++ )
        ptr[ i ] = 0; // initialize array
} // end class Table constructor
// copy constructor
template < class  >
Table<  >::Table(
        const Table<  > &init ) {
    rows = init.rows;
    columns = init.columns;
    ptr = new something[ rows * columns ];
    for ( int i = 0; i < rows * columns; i++ )
        ptr[ i ] = init.ptr[ i ];
} // end class Table constructor
// destructor
template < class  >
Table< >::~Table() {
    delete [] ptr;
} // end class Table destructor
// template function operator= definition
template < class  >
const Table<   > &Table<   >::operator=( const Table<   > &right ) {
    if ( &right != this ) {

        if ( rows * columns != right.rows * right.columns ) {
            delete [] ptr;
            rows = right.rows;
            columns = right.columns;
            ptr = new something[ rows * columns ];
        } // end if
        for ( int i = 0; i < rows * columns; i++ )
            ptr[ i ] = right.ptr[ i ];
    } // end if
    return *this;
} // end function operator=
// template function for subscript operator() definition
const ::operator()( int s1, int s2 ) const
{
if ( !( 0 <= s1 && s1 < rows ) )
s1 = 0;
if ( !( 0 <= s2 && s2 < columns ) )
s2 = 0;
return ptr[ columns * s1 + s2  ]; // rvalue
} // end function operator()
/* CS360: Write definition for overloaded subscript operator() for
    non-const Tables.  Hint see declaration in class above*/
/* CS360: Write definition for overloaded operator== */
// template function inputValues definition
::inputValues() {
for ( int i = 0; i < rows * columns; i++ )
cin >> ptr[ i ];
} // end function inputValues
// template function print definition
::print() const {
for ( int i = 0; i < rows * columns; i++ ) {
cout << setw( 6 ) << ptr[ i ];
if ( ( i + 1 ) % columns == 0 )
cout << endl;
} // end for
if ( i % columns != 0 )
cout << endl;
} // end function print
#endif // TABLE_H
/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/