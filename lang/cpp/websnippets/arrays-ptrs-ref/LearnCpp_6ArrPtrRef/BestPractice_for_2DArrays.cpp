/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * Sources:
 * https://stackoverflow.com/questions/12841170/how-to-define-a-2d-array-in-c-and-stl-without-memory-manipulation
 */

#include "learncpp_6arr-ptr-ref.h"

void
bestPractice_2DArrayDeclaration() {

    /*static, decl&init, no resizing needed, C++11 ========*/
    array<array<int, 3>, 2> arr1{
        {
            {{1, 2, 3}},
            {{4, 5, 6}}
        }};


    const int ROW = 2;
    const int COL = 3;

    /* static declaration, no resizing needed =====*/
    /* no STL container, better use version below*/
    int arr2[ROW][COL];
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            arr2[i][j] = i * COL + j + 1;


    /* BEST METHOD ========================================*/
    /* dynMem, declaration, resizing optional =============*/
    /* same, without resizing: use array instead of vector*/
    ARRAY_2D_RESIZABLE arr3;
    vector<int> rowvector;
    for (int i = 0; i < ROW; i++) {
        rowvector.clear();
        for (int j = 0; j < COL; j++)
            rowvector.push_back(i * COL + j + 1);
        arr3.push_back(rowvector);
    }

    helper_print2DArray1(arr1);
    helper_print2DArray2(arr2, 2, 3);
    helper_print2DArray3(arr3);

    /*
     * Output: 
     * Print array<array<int,3>,2>:
  1 2 3
  4 5 6

  Print int[2][3]:
  1 2 3
  4 5 6

  Print vector<vector<int> >:
  But first check typeid: St6vectorIS_IiSaIiEESaIS1_EE
  1 2 3
  4 5 6

     */

}

void helper_print2DArray1(const array<array<int, 3>, 2> &arr) {
    cout << "Print array<array<int,3>,2>:" << endl;
    for (auto row : arr) {
        for (auto el : row) {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/* Note the correct syntax for ref2ConstArray here!!!*/
void helper_print2DArray2(const int (&arr)[2][3], int rows, int cols) {
    cout << "Print int[2][3]:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void helper_print2DArray3(const vector<vector<int> >& arr) {
    cout << "Print vector<vector<int> >:" << endl;
    cout << "But first check typeid: " << typeid (arr).name() << endl;
    for (auto row : arr) {
        for (auto el : row) {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}