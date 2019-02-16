/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Test_array2D_contiguous_create.cpp
 * Author: johannes
 *
 * Created on Aug 1, 2018, 3:12:00 PM
 */

#include "Test_array2D_contiguous_create.h"
#include "../Tool_Arrays_JW_impl.h"
//using namespace Tool_Arrays_JW;


CPPUNIT_TEST_SUITE_REGISTRATION(Test_array2D_contiguous_create);

Test_array2D_contiguous_create::Test_array2D_contiguous_create() { }

Test_array2D_contiguous_create::~Test_array2D_contiguous_create() { }

void Test_array2D_contiguous_create::setUp() { }

void Test_array2D_contiguous_create::tearDown() { }

void Test_array2D_contiguous_create::testArray2D_contiguous_cStyle_create() {
    int M = 2;
    int N = 2;
    bool rowWise;
    double** result = Tool_Arrays_JW::array2D_contiguous_cStyle_create<double>(M, N, rowWise);
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (result[i][j] == 0.0)
                count++;
        }
    }
    if (count == M * N) {
        CPPUNIT_ASSERT(true);
    }
}

