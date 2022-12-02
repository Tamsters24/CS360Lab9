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
template <class Lab9> class Table {
public:
    explicit Table(int = 10, int = 10); // "explicit" recommended by IDE
    Table(const Table<Lab9> &init);
    ~Table();

    Lab9 &operator()(int, int);
    const Lab9 &operator()(int, int) const;
    const Table<Lab9> &operator=(const Table<Lab9> &);
    bool operator==(const Table<Lab9> &) const;
    bool operator!=(const Table<Lab9> &) const;

    void inputValues();
    void print() const;

private:
    int rows;             // number of rows in array
    int columns;          // number of columns in array
    /* CS360: Write declaration for private data member ptr, a pointer to a
     * parameterized dynamically allocated array */
    Lab9 *ptr;
}; // end class Table

// default constructor
template <class Lab9>
Table<Lab9>::Table(int r, int c) {
    rows = (r > 0 ? r : 10);
    columns = (c > 0 ? c : 10);

    /* CS360: Write code to allocate dynamically an array with rows *
       columns elements of type T */
    int rxc = rows * columns;
    ptr = new Lab9[rxc];

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = 0; // initialize array
} // end class Table constructor

// copy constructor
template <class Lab9>
Table<Lab9>::Table(const Table<Lab9> &init) {
    rows = init.rows;
    columns = init.columns;
    ptr = new Lab9[rows * columns];
    for (int j = 0; j < rows * columns; j++)
        ptr[j] = init.ptr[j];
} // end class Table constructor

// destructor
template <class Lab9>
Table<Lab9>::~Table() {
    delete [] ptr;
} // end class Table destructor

/* CS360: Write definition for overloaded subscript operator() for
 * non-const Tables. Hint see declaration in class above */
template <class Lab9>
Lab9 &Table<Lab9>::operator()(int s1, int s2) {
    if (!(0 <= s1 && s1 < rows))
        s1 = 0;
    if (!(0 <= s2 && s2 < columns))
        s2 = 0;
    return ptr[columns * s1 + s2]; // rvalue
} // end function operator()

// template function for subscript operator() definition
template <class Lab9>
const Lab9 &Table<Lab9>::operator()(int s1, int s2) const {
    if (!(0 <= s1 && s1 < rows))
        s1 = 0;
    if (!(0 <= s2 && s2 < columns))
        s2 = 0;
    return ptr[columns * s1 + s2]; // rvalue
}

// template function operator= definition
template <class Lab9>
const Table<Lab9> &Table<Lab9>::operator=(const Table<Lab9> &right) {
    if (&right != this) {
        if (rows * columns != right.rows * right.columns) {
            delete [] ptr;
            rows = right.rows;
            columns = right.columns;
            ptr = new Lab9[rows * columns];
        } // end if
        for (int k = 0; k < rows * columns; k++)
            ptr[k] = right.ptr[k];
    } // end if
    return *this;
} // end function operator=

/* CS360: Write definition for overloaded operator== */
template <class Lab9>
bool Table<Lab9>::operator==(const Table<Lab9> &right) const {
    bool coordinate = true;
    for (int k = 0; k < rows * columns; k++) {
        if (ptr[k] == right.ptr[k]) {
            // do nothing
        } else {
            coordinate = false;
        }
    }
    return coordinate;
}

// determine if two arrays are not equal and
// return true, otherwise return false (uses operator==)
template <class Lab9>
bool Table<Lab9>::operator!=(const Table<Lab9> &right) const {
    return *this != right;
}

// template function inputValues definition
template <class Lab9>
void Table<Lab9>::inputValues() {
    for (int l = 0; l < rows * columns; l++)
        cin >> ptr[l];
} // end function inputValues

// template function print definition
template <class Lab9>
void Table<Lab9>::print() const {
    for (int m = 0; m < rows * columns; m++) {
        cout << setw(6) << ptr[m];
        if ((m + 1) % columns == 0)
            cout << endl;
    } // end for
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