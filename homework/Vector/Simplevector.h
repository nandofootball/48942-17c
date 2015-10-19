/* 
 * File:   Simplevector.h
 * Author: rcc
 *
 * Created on October 19, 2015, 3:34 PM
 */

#ifndef SIMPLEVECTOR_H
#define	SIMPLEVECTOR_H
#include <iostream>
#include <new>
#include <cstdlib>   // Needed for the exit function
using namespace std;
template <class T>
class SimpleVector{
    private:
        T *aptr;
        int arraySize;
        int actualSize;
        void memError ();
        void subError ();
    
    public:
        SimpleVector()
        { aptr = 0; arraySize = 0;}
        SimpleVector (int);
        //push function increase array size 1
        void push ( T );
        void pull();
        
        SimpleVector (const SimpleVector &);
        ~SimpleVector ();
        int size() const
        { return arraySize; }
        T getElementAt (int position);
        T &operator[](const int &);
        int size();
        
        
};

template <class T> 
SimpleVector<T>::SimpleVector(int s) { 
   arraySize = s;
   actualSize = s;
   // Allocate memory for the array. 
   try  {
      if(s>0) 
          aptr = new T [s];
      else
          aptr = 0;
   } 
   catch (bad_alloc) 
   { 
      memError(); 
   } 


   // Initialize the array. 
   for (int count = 0; count < arraySize; count++) {
      *(aptr + count) = 0;
   }
} 

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (actualSize > 0)
      delete [] aptr;
}

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVector<T>::push( T item ) {
    if(arraySize+1<=actualSize){
        cout<<"only add\n";
        aptr[arraySize]=item;
        arraySize++;
    }
    else{
        if(actualSize==0){
            cout<<"actual==0 double\n";
            arraySize=actualSize=1;
            aptr = new T[actualSize*2];
            aptr[0]=item;
            actualSize=2;
        }
        else{
            cout<<"actual!=0, double\n";
            actualSize*=2;
            T *temp = new T[actualSize];
            for(int i=0;i<arraySize;i++){
                temp[i]=aptr[i];
            }
            temp[arraySize]=item;
            delete []aptr;
            aptr=temp;
            arraySize++;
        }
    }
//    T *newPtr = new T[arraySize+1];
//    for( int i = 0; i < arraySize; i++ ){
//        newPtr[i] = aptr[i];
//    }
//    
//    newPtr[arraySize] = item;
//    arraySize++;
//   
//    aptr = newPtr;
}

template <class T>
void SimpleVector<T>::pull() {
     if (arraySize >0)arraySize--;
     else{
         cout<<" ";
     }
}

template <class T>
int SimpleVector<T>::size() {
    return arraySize;
}


#endif	/* SIMPLEVECTOR_H */

