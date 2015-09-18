/* 
 * File:   Triangularmatrix.h
 * Author: rcc
 *
 * Created on September 16, 2015, 2:50 PM
 */

#ifndef TRIANGULARMATRIX_H
#define	TRIANGULARMATRIX_H

using namespace std;

template <class T>
class Triangularmatrix{
    
    private:
    T** matrix; 
    T* colarray;
    int nCols;
    
    public:
        int getmax();
        T *filAray(int);
        T **filAray(T*,int);
        void prntAry(T**,T*,int);
        void prntAry(T*,int);
        Triangularmatrix( int );
        ~Triangularmatrix();
};

template <class T>
Triangularmatrix<T> ::  Triangularmatrix( int n){
    nCols=n;
    filAray(nCols); 
    filAray(colarray,nCols); prntAry(matrix, colarray, nCols);

}

template <class T>
Triangularmatrix<T> :: ~Triangularmatrix(){
  delete []colarray;
    for(int i=0;i<nCols;i++){
        delete []matrix[i];
    }
     delete []matrix;
      
    
}

template <class T>
T* Triangularmatrix<T> :: filAray(int n) {
    T *array=new T[n];
    for(int i=0;i<n;i++){
        //array[i]=rand()%10+1;
        array[i]=i+1;
    }
    colarray=array;
}

template <class T>
T ** Triangularmatrix<T> :: filAray(T *cols ,int nCols) {
    //Allocate Memory
    T **array=new T*[nCols];
    for(int i=0;i<nCols;i++){ 
         array[i]=new int[cols[i]]; 
     } 
     //Fill the allocated memory 
     for(int row=0;row<nCols;row++){ 
        for(int col=0;col<cols[row];col++){ 
            array[row][col]=rand()%90+10; 
        }  
    }
    matrix=array;
}
template <class T>
int Triangularmatrix<T> :: getmax() {
    
}
template <class T>
void Triangularmatrix<T> :: prntAry(T **array,T *cols,int nCols){
    cout<<std::endl;
    //Print the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<cols[row];col++){
            std::cout<<array[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
template <class T>
void Triangularmatrix<T> :: prntAry(T *array,int n){
    std::cout<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<< std::endl;
}




    

#endif	/* TRIANGULARMATRIX_H */

