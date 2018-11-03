#include <iostream>
#include <thread>
#include <iomanip>

using namespace std;

void multiplicar(int f , int m[][3], int m2[][3], int m3[][3], int c){
    int sum = 0;
    for(int j = 0; j < c; j++){
        for(int i = 0; i < c; i++){
            sum+=m[f][i]*m2[i][j];
        }
        m3[f][j] = sum;
        sum = 0;
    }
}
void print(int m[][3], int f, int c){

    for(int i = 0; i < f; i ++){
        for(int j = 0; j < c; j++){
            cout<<setw(4)<< m[i][j] ;
        }
        cout<<'\n';
    }
}
int main() {

    int f = 3,c = 3;
    int matrix[3][3];
    int matrix2[3][3];
    int mult[3][3];
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            matrix[i][j] = f*i+j;
            matrix2[i][j] = f*i+j;
            mult[i][j] = 0;
        }
    }

    thread threads[f];
    for(int i  = 0;  i < f ; i++)
        threads[i] = thread(multiplicar, i ,matrix ,matrix2 ,mult ,c);
    for(int i = 0; i < f; i++)
        threads[i].join();

    print(matrix,f,c);
    print(matrix2,f,c);
    print(mult,f,c);

    return 0;
}