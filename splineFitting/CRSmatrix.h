/*
 *  CRSmatrix.h
 *  SplineFitting
 *  This file contains CRS matrix functions and Jacobi method
 *
 *  Created by Yazhi Fan (yf92) and Yijia Chen (yc2366) on 5/10/18.
 *  Copyright © 2018 Yazhi and Yijia. All rights reserved.
 *
 */

#ifndef SPLINEFITTING_CRSMATRIX_H
#define SPLINEFITTING_CRSMATRIX_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------------------------

/* sparse matrix structure using row-compressed storage
        Contents:
                value: sparse matrix values
                collnd: column index associated with each matrix value
                rowPtr: keeps count of the number of values in each row and the number of rows
                rowNum: number of rows
                colNum: number of columns
*/
struct CRSmatrix {
    vector<double> value;
    vector<int> rowPtr;
    vector<int> colInd;
    int rowNum;
    int colNum;

    //CRSmatrix constructor with value, row point, and column index vectors
    CRSmatrix(vector<double> v, vector<int> r, vector<int> c);

    //CRSmatrix constructor with row number of column number
    CRSmatrix(int r, int c);

    //CRSmatrix constructor with local file paths containing the data
    CRSmatrix(string valueAddress, string rowPtrAddress, string colIndAddress);

    //return matrix value at [i][j]
    double retrieveElement (int i, int j);

    //insert value x at position [i][j]
    void changeValue (double x, int i, int j);

    //multiply matrix with a vector x and return the product
    vector<double> productAx(vector<double> x);

    //delete value at position [i][j]
    void deleteValue(int i, int j);

    //print CRSmatrix
    void printA();
} ;

// ----------------------------------------------------------------------------------------

/* helper function that finds the vector norm
        Parameters:
                x: any vector
        Return:
                ||x||2
*/
double vectorNorm(vector<double> x);

// ----------------------------------------------------------------------------------------

/* Jacobi CRS matrix solver for Ax = b
        Parameters:
                A: a CRS matrix
                b: a vector
        Return:
                the solution to Ax = b
*/
vector<double> Jacobi(CRSmatrix A, vector<double> b);

#endif //SPLINEFITTING_CRSMATRIX_H