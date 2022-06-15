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

    SmartPointer(const SmartPointer& that) = delete;

    SmartPointer(SmartPointer&& that) {
        PrintFunctionSignature();
        m_ptr = that.m_ptr;
        that.m_ptr = nullptr;
    }

    ~SmartPointer() {
        PrintFunctionSignature();
        if (m_ptr)
        {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    SmartPointer& operator = (T*&& ptr) {
        PrintFunctionSignature();
        m_ptr = ptr;
        return *this;
    }

    SmartPointer& operator = (const SmartPointer& that) = delete;

    SmartPointer& operator = (SmartPointer&& that) {
        PrintFunctionSignature();
        m_ptr = that.m_ptr;
        that.m_ptr = nullptr;
        return *this;
    }

    T operator *() {
        return *m_ptr;
    }

    T* operator ->() {
        return m_ptr;
    }

};