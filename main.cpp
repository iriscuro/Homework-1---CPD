#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <random>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
//**************************************
//Generar numeros aleatorios
//
int numA(){
  random_device rd;  //Will be used to obtain a seed for the random number engine
  mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  uniform_int_distribution<> dis(0, 100);
  return dis(gen);
}
//**************************************
//Version clasica
//version 1: con tres bucles anidados
void MMv1(vector< vector<int> > A, int t1, int t2, vector< vector<int> > B, int t3, int t4, vector< vector<int> > &R){
  if(t2 == t3){
    for(int r=0; r<t1; r++)
      for(int c=0; c<t4; c++){
        // Multiply the row of A by the column of B to get the row, column of product
        for(int k=0; k<t3; k++)
          R[r][k] += A[r][c] * B[c][k];
      } 
  }
}

//*************************************
//version por bloques
//version 2: 6 bloques anidados


void MultiplyB(int n, vector< vector<int> > A, vector< vector<int> > B, vector< vector<int> > &R)
{
    int bi, bj, bk;
    bi = bj = bk = 0;
    int i, j, k;
    i = j = k =0;
    int bSize= 10; 
    
    for(bi=0; bi<n; bi+= bSize)
        for(bj=0; bj<n; bj+= bSize)
            for(bk=0; bk<n; bk+= bSize)
                for(i=0; i<bSize; i++)
                    for(j=0; j<bSize; j++)
                        for(k=0; k<bSize; k++)
                            R[bi+i][bj+j] += A[bi+i][bk+k]*B[bk+k][bj+j];               
}



// ***********************************
//Imprimir matrices
///IMPRIMIR NXM
template <class T>
void Print_NN(vector< vector<T> > v,int size1, int size2){
  for(int y=0; y<size1 ; y++){
        for(int x=0; x<size2 ; x++){
            cout << v[y][x]<<" ";
        }
        cout<<endl;
    }
  cout<<endl;
}

int main() {

  int pruebas[10] ={50,100,500,1000,1500};//dimensión de las matrices
  //cout << "Multiplicacion MxN"<<endl;
  //cout << "num ale: "<<numA() <<endl;///yes
  /*
  int a=10;
  int b=25;
  int c=25;
  int d=30;
  int e=a;
  int f=d;
  */
  int a , b, c, d, e, f;
  a=  b= c= d= e= f = pruebas[2];
  //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
  //int A[a][b], B[c][d],C[e][f];
  vector<vector<int> > A(a, vector<int> (b));
  vector<vector<int> > B(c, vector<int> (d));
  vector<vector<int> > C(e, vector<int> (f));
  vector<vector<int> > C2(e, vector<int> (f));
  
  //FILL MATRICES
  //Matriz As
  for(int i=0;i<a; i++)
    for(int j=0;j<b; j++){
      A[i][j] = numA(); 
    }
  //Matriz B
  for(int i=0;i<c; i++)
    for(int j=0;j<d; j++){
      B[i][j] = numA(); 
    }
  //cout<< "\nImpresion"<<endl;
  //Print_NN(A,a,b);
  //Print_NN(B,c,d);
  
  //cout<<"... end ..."<<endl;

  
  //MULTIPLY TO MATRIXES
  //cout<<"\nMultiplicando V1"<<endl;
  //MMv1(A,a,b, B, c, d, C);

  //cout<<"\nMultiplicando V2"<<endl;
  MultiplyB(a, A, B, C2);
  
  //PRINT RESULT
  //cout<< "\nImpresion"<<endl;
  //Print_NN(C,e,f);
  //Print_NN(C2,e,f);
  
  return 0;
}
