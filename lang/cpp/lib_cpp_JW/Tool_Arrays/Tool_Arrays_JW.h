/* 
 * File:   Tool_Arrays_JW.h
 * Author: johannesw
 * 
 * Tools for C-style Arrays.
 * Maybe Useful when using MPI or other libraries that require arrays
 * as contiguous blocks of memory. 
 * Otherwise always prefere STL containers (and sometimes even then)!!!
 * 
 * 
 * DEVNOTES
 * --------
 * - using a namespace X here instead of a class. The functions in that 
 *   namespace behave the same way as if X was a class and the functions 
 *   were static class methods: X::foo().
 *
 * Created on 26. Juli 2018, 21:37
 */

#ifndef TOOL_ARRAYS_JW_H
#define TOOL_ARRAYS_JW_H

namespace Tool_Arrays_JW {

    template <class T>
    T **array2D_contiguous_cStyle_create(int M, int N, bool rowWise = true);

    template <class T>
    void array2D_contiguous_cStyle_delete(T** arr);

    template <class T>
    T** array2D_contiguous_cppStyle_create(int M, int N);

    template <class T>
    void array2D_contiguous_cppStyle_delete(T** arr, int M, int N);

    template <class T>
    T ***array3D_noncont_create(int L, int M, int N);

    template <class T>
    void array3D_noncont_delete(T*** arr, int L, int M, int N);

    template <class T>
    void array2D_fillSequentially(T ** arr, int M, int N, T increment);

    template <class T>
    std::string array2D_toString(std::string arrname, T** arr, int M, int N, int mype, int otherpe);

};
#include "Tool_Arrays_JW_impl.h"


#endif /* TOOL_ARRAYS_JW_H */
