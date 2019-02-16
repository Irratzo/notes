/* 
 * File:   Tool_Arrays_JW_impl.h
 * Author: johannesw
 * 
 * Implementation for Tool_Arrays_JW.h
 *
 * Created on 26. Juli 2018, 23:32
 */

#ifndef TOOL_ARRAYS_JW_IMPL_H
#define TOOL_ARRAYS_JW_IMPL_H

#include <stdlib.h> //malloc
#include <sstream> //ostringstream

namespace Tool_Arrays_JW {

    /**
     * 
     * Allocate a contiguous 2D array. C-style using malloc.
     * Use this if you want to MPI Send&Recv 2D array in larger chunks than size 1.
     * (e.g. size = rows*cols for sending the whole array)
     * Sources: 
     * - https://stackoverflow.com/a/5901671/8116031
     * - https://gsamaras.wordpress.com/code/2d-dynamic-array-in-continuous-memory-locations-c/
     * 
     * The sending and receiving is then done like this:
     * MPI_Send(&(array[0][0]), M*N, ...);
     * 
     * @param M
     * @param N
     * bool rowWise (or column-wise, logically equivalent, has default true)
     * @return 
     */
    template <class T>
    T** array2D_contiguous_cStyle_create(int M, int N, bool rowWise) {
        T *data = (T *) malloc(M * N * sizeof (T)); //allocate data
        T **array;

        if (rowWise) {
            //first option: row-wise
            array = (T **) malloc(M * sizeof (T*)); //allocate pointers
            for (int i = 0; i < M; i++)
                array[i] = &(data[N * i]); //== data + i*(rows)

        } else {
            //second option: column-wise (equivalent)
            array = (T **) malloc(N * sizeof (T*)); /* Allocating pointers */
            for (int i = 0; i < N; i++)
                array[i] = data + i * (M);
        }

        return array;
    }

    template <class T>
    void array2D_contiguous_cStyle_delete(T** arr) {
        free(arr[0]);
        free(arr);
    }

    /**
     * 
     * Allocate a contiguous 2D array. C-style using malloc.
     * Use this if you want to MPI Send&Recv 2D array in larger chunks than size 1.
     * (e.g. size = rows*cols for sending the whole array)
     * Sources: 
     * - Karniadakis Scientific Programing in C++ and MPI, 2003:
     *   - 5.1.4 Dynamic Allocation of Multidimensional Arrays in Contiguous Blocks
     * 
     * The sending and receiving is then done like this:
     * MPI_Send(&(array[0][0]), M*N, ...);
     * 
     * @param M
     * @param N
     * bool rowWise (or column-wise, logically equivalent, has default true)
     * @return 
     */
    template <class T>
    T** array2D_contiguous_cppStyle_create(int M, int N) {

        T ** arr;
        arr = new T*[M]; //allocate double* indexing array
        arr[0] = new T[M * N]; //allocate storage as a
        //contiguous block
        for (int i = 1; i < M; i++)
            arr[i] = arr[0] + i * N;
        return arr;
    }

    template <class T>
    void array2D_contiguous_cppStyle_delete(T** arr) {
        //since the memblock MxN is contiguous, we don't have
        //to first delete M subarrays arr[i].
        delete [] arr; //delete 1st dim
    }

    template <class T>
    T*** array3D_noncont_create(int L, int M, int N) {
        T *** arr;
        arr = new T** [L]; //init 1st dim
        for (int i = 0; i < L; i++) {
            arr[i] = new T* [M]; //init 2nd dim
            for (int j = 0; j < M; j++) {
                arr[i][j] = new T[N](); //init 3rd dim, elmts to 0
            }
        }
        return arr;
    }

    template <class T>
    void array3D_noncont_delete(T*** arr, int L, int M, int N) {

        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < M; ++j) {
                delete [] arr[i][j]; //delete 3rd dim
            }
            delete [] arr[i]; //delete 2nd dim
        }
        delete [] arr; //delete 1st dim
    }

    template <class T>
    void array2D_fillSequentially(T ** arr, int M, int N, T increment) {

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = ((T) (i * N + j)) + increment; //fill with linseq
            }
        }
    }

    template <class T>
    std::string array2D_toString(std::string arrname, T** arr, int M, int N, int mype, int otherpe) {
        std::ostringstream oss("");
        oss << "RECV: Proc " << otherpe << "-->" << mype << ": into array " << arrname << ":\n";
        //    oss << "Arr " << arrname << " on pro " << mype << " recved from proc" << otherpe << ":" << std::endl;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                oss << arr[i][j] << ", ";
            }
            oss << std::endl;
        }
        return oss.str();
    }
}

#endif /* TOOL_ARRAYS_JW_IMPL_H */

