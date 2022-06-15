#pragma once
#include <iostream>
#define _PRINT_FUNC_SIGN_
#ifdef _PRINT_FUNC_SIGN_
#ifdef _WIN32
#define PrintFunctionSignature()\
    std::cout<<__FUNCSIG__<<std::endl;
#else
#define PrintFunctionSignature()    \
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
#endif
#endif
