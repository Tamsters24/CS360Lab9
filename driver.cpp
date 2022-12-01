// Chapter 11 of C++ How to Program
// Driver for class Table

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

#include <new>
#include <ctime>
#include "table.h"

int main() {
   srand( time( 0 ) ); // seed random function

   /* CS360:  Write code to create a Table of ints of size ( 4, 7 ); 
      name the Table "a" */

   /* CS360:  Write code to create a Table of chars of size ( 5, 2 ); 
      name the Table "b" */

   cout << "Uninitialized array \"a\" is: \n";
   a.print(); 
   
   cout << "Uninitialized array \"b\" is: \n";
   b.print(); // output null characters

   // initialize array "a" with random values (0-100)
   for ( int i = 0; i < 4; i++ )
      for ( int j = 0; j < 7; j++ )
         a( i, j ) = rand() % 101;
   
   // initialize array "b" with 'g'
   for ( i = 0; i < 5; i++ )
      for ( int j = 0; j < 2; j++ )
         b( i, j ) = 'g';

   cout << "\nInitialized array \"a\" is now:\n";
   a.print();
   
   cout << "Initialized array \"b\" is now: \n"; 
   b.print();

   cout << "\nEnter values for b (10 of them): \n";
   b.inputValues();
   cout << endl;
   b.print();
   cout << endl;

   // retrieve array element using overloaded operator() CS360: write code to access a(2,1);
   cout << "The element (2, 1) of array \"a\" is: ";


   /* CS360: Write code that accesses and prints element 2,1 of array b */


   // change element of array using overloaded operator()
   a( 2, 1 ) = -1;
   cout << "Changed element (2, 1) to -1: \n"; 
   a.print();


    /* code to test operator==*/
    Table<int> c(0,0);
    c = a;
    c(3,1) = 4;//CS360: to test operator==, comment out this line and the arrays should be equal
    cout << "array c: " << endl;
    c.print();

    if(a == c)
        cout << "arrays a and c were equal" << endl;
    else
        cout << "arrays a and c were not equal" << endl;


    /*CS360 Challenge: Note that this part of the lab is not required.

            Do this last and only if you get everything else working.  
            Write code to dynamically allocate a Table of integers using a pointer.
            Then fill the array with random numbers.
            Then print the array.
            Then free the memory when done.*/


   return 0;

} // end main

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