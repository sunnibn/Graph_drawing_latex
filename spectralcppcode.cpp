#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <iostream>
#include <stdlib.h>

#include <typeinfo>

using Eigen::MatrixXf;

int main(int argc, char *argv[])
{
    int idx = 1;
    int n;
    n = atoi(argv[idx]);

    MatrixXf l(n,n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            idx += 1;
            l(i,j) = atoi(argv[idx]);
        }
    }

    idx += 1;
    n = atoi(argv[idx]);

    MatrixXf d(n,n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            idx += 1;
            d(i,j) = atoi(argv[idx]);
        }
    }

    Eigen::GeneralizedSelfAdjointEigenSolver<MatrixXf> ges;
    ges.compute(l,d);
    
    std::cout << ges.eigenvectors() << std::endl;

    return 0;
}