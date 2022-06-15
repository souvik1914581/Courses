#pragma once
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>





template <typename T>
class SmartPointer
{
    T* m_ptr;
public:
    SmartPointer() = default;
    SmartPointer(T* ptr) {
        PrintFunctionSignature();
        m_ptr = ptr;
    }

    ~SmartPointer() {
        PrintFunctionSignature();
        delete m_ptr;
    }

    T operator *() {
        return *m_ptr;
    }

    T* operator ->() {
        return m_ptr;
    }

};