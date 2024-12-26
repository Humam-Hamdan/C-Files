#include <stdio.h>


//constexpr int N = 2; // Matrix Groesse

enum { N = 2 };

typedef double Matrix[N][N];

/*
Matrix N mal N lesen
read (double a[N][N])
read (double a[][N])
read (double (*a)[N]    pointer at double vector lenght N
*/

void read(Matrix a){
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            scanf("%lf", &a[i][j]);
        }
    }
}

// NN Matrix ausgeben

void print(const Matrix a){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("  %f", a[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

// Matrix mal
void matmul(const Matrix a, const Matrix b, Matrix c){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // Rechne!
            double summe=0.0;
            for(int k=0; k<N; k++){
                summe += a[i][k] * b[k][j];
            }
            c[i][j]=summe;
        }
    }
}

int main(){
    Matrix a, b, c;

    printf("%d x %d Matrix a eingeben: ",N,N);
    read(a);
    printf("a= \n");
    print(a);

    printf("%d x %d Matrix b eingeben: ",N,N);
    read(b);
    printf("b= \n");
    print(b);

    matmul(a, b, c);
    printf("c = a · b = \n");
    print(c);

}



