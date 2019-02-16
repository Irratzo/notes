/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Test_array2D_contiguous_create.h
 * Author: johannes
 *
 * Created on Aug 1, 2018, 3:12:00 PM
 */

#ifndef TEST_ARRAY2D_CONTIGUOUS_CREATE_H
#define TEST_ARRAY2D_CONTIGUOUS_CREATE_H

#include <cppunit/extensions/HelperMacros.h>

class Test_array2D_contiguous_create : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Test_array2D_contiguous_create);

    CPPUNIT_TEST(testArray2D_contiguous_cStyle_create);

    CPPUNIT_TEST_SUITE_END();

public:
    Test_array2D_contiguous_create();
    virtual ~Test_array2D_contiguous_create();
    void setUp();
    void tearDown();

private:
    void testArray2D_contiguous_cStyle_create();

};

#endif /* TEST_ARRAY2D_CONTIGUOUS_CREATE_H */

