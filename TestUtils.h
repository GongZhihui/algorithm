#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <iostream>

#define ALGORITHM_TEST_CASE(FUNC) void FUNC()
// FLAG if FLAG is true， then execute FUNC()
#define ALGORITHM_EXECUTE_CASE(FUNC, FLAG) \
    if(FLAG)\
    {\
        std::cout<< "["#FUNC << "] === start" << std::endl; \
        FUNC(); \
        std::cout<< "[" <<#FUNC << "] === end"<<std::endl;\
        std::cout<< "" << std::endl;\
    }\

#endif //!TEST_UTILS_H