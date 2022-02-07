#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

// Set LEAF_SIZE to 1 if you want to the pure strassen algorithm
int leafsize=2;

using namespace std;

void ikjalgorithm(vector<vector<long long int>> mat1,
                                   vector<vector<long long int>> mat2,
                                   vector<vector<long long int>> &mat3, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void sum(vector<vector<long long int>> &mat1,
         vector<vector<long long int>> &mat2,
         vector<vector<long long int>> &mat3, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtract(vector<vector<long long int>> &mat1,
              vector<vector<long long int>> &mat2,
              vector<vector<long long int>> &mat3, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void strassenR(vector<vector<long long int>> &mat1,
              vector<vector<long long int>> &mat2,
              vector<vector<long long int>> &mat3, int tam) {
    if (tam <= leafsize) {
        ikjalgorithm(mat1, mat2, mat3, tam);
        return;
    }

    // other cases are treated here:
    else {
        int newTam = tam/2;
        vector<long long int> inner (newTam);
        vector<vector<long long int>>
            a11(newTam,inner), a12(newTam,inner), a21(newTam,inner), a22(newTam,inner),
            b11(newTam,inner), b12(newTam,inner), b21(newTam,inner), b22(newTam,inner),
              c11(newTam,inner), c12(newTam,inner), c21(newTam,inner), c22(newTam,inner),
            p1(newTam,inner), p2(newTam,inner), p3(newTam,inner), p4(newTam,inner),
            p5(newTam,inner), p6(newTam,inner), p7(newTam,inner),
            aResult(newTam,inner), bResult(newTam,inner);

        int i, j;

        //dividing the matrices in 4 sub-matrices:
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11[i][j] = mat1[i][j];
                a12[i][j] = mat1[i][j + newTam];
                a21[i][j] = mat1[i + newTam][j];
                a22[i][j] = mat1[i + newTam][j + newTam];

                b11[i][j] = mat2[i][j];
                b12[i][j] = mat2[i][j + newTam];
                b21[i][j] = mat2[i + newTam][j];
                b22[i][j] = mat2[i + newTam][j + newTam];
            }
        }

        // Calculating p1 to p7:

        sum(a11, a22, aResult, newTam); // a11 + a22
        sum(b11, b22, bResult, newTam); // b11 + b22
        strassenR(aResult, bResult, p1, newTam); // p1 = (a11+a22) * (b11+b22)

        sum(a21, a22, aResult, newTam); // a21 + a22
        strassenR(aResult, b11, p2, newTam); // p2 = (a21+a22) * (b11)

        subtract(b12, b22, bResult, newTam); // b12 - b22
        strassenR(a11, bResult, p3, newTam); // p3 = (a11) * (b12 - b22)

        subtract(b21, b11, bResult, newTam); // b21 - b11
        strassenR(a22, bResult, p4, newTam); // p4 = (a22) * (b21 - b11)

        sum(a11, a12, aResult, newTam); // a11 + a12
        strassenR(aResult, b22, p5, newTam); // p5 = (a11+a12) * (b22)

        subtract(a21, a11, aResult, newTam); // a21 - a11
        sum(b11, b12, bResult, newTam); // b11 + b12
        strassenR(aResult, bResult, p6, newTam); // p6 = (a21-a11) * (b11+b12)

        subtract(a12, a22, aResult, newTam); // a12 - a22
        sum(b21, b22, bResult, newTam); // b21 + b22
        strassenR(aResult, bResult, p7, newTam); // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 and c22:

        sum(p3, p5, c12, newTam); // c12 = p3 + p5
        sum(p2, p4, c21, newTam); // c21 = p2 + p4

        sum(p1, p4, aResult, newTam); // p1 + p4
        sum(aResult, p7, bResult, newTam); // p1 + p4 + p7
        subtract(bResult, p5, c11, newTam); // c11 = p1 + p4 - p5 + p7

        sum(p1, p3, aResult, newTam); // p1 + p3
        sum(aResult, p6, bResult, newTam); // p1 + p3 + p6
        subtract(bResult, p2, c22, newTam); // c22 = p1 + p3 - p2 + p6

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                mat3[i][j] = c11[i][j];
                mat3[i][j + newTam] = c12[i][j];
                mat3[i + newTam][j] = c21[i][j];
                mat3[i + newTam][j + newTam] = c22[i][j];
            }
        }
    }
}

long long int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}

void strassen(vector<vector<long long int>> &mat1,
              vector<vector<long long int>> &mat2,
              vector<vector<long long int>> &mat3, int n) {
    //unsigned int n = tam;
    long long int m = nextPowerOfTwo(n);
    vector<long long int> inner(m);
    vector<vector<long long int>> APrep(m, inner), BPrep(m, inner), CPrep(m, inner);

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            APrep[i][j] = mat1[i][j];
            BPrep[i][j] = mat2[i][j];
        }
    }

    strassenR(APrep, BPrep, CPrep, m);
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mat3[i][j] = CPrep[i][j];
        }
    }
}




void printMatrix(vector<vector<long long int>> matrix, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
void read_matrix(vector<vector<long long int>>&mat,int n)
{
    int i,j,ele,x;
    for(i=0;i<n;i++)
    {
        vector<long long int> row;
        for(j=0;j<n;j++)
        {
            x=std::rand();
            x=x%400;
            row.push_back(x);
        }
        mat.push_back(row);
    }
}
int main () {
    

    vector<vector<long long int>> mat1,mat2;

    for(int i=1024; i<1025; i=i*2)
    {
    read_matrix(mat1,i);
    read_matrix(mat2,i);
    vector<vector<long long int>> mat3(i, vector<long long int>(i,0));
    std::srand(static_cast<int>(std::time(nullptr)));
    clock_t tStart=clock();

    strassen(mat1, mat2, mat3, i);

    double time=(double)(clock()-tStart)/CLOCKS_PER_SEC;
    cout<<"mat size: "<<i<<" - mat time"<<time<<"\n";
    }
    //printMatrix(mat3, n);
    return 0;
}
