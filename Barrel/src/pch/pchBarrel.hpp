#ifndef E0B05701_1CE6_4C6D_A363_FE30540EBD41
#define E0B05701_1CE6_4C6D_A363_FE30540EBD41

/* Functional */
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

/* Data types */
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* Logging */
#include "../barrel/log/Log.hpp"






/* MACROS for ASSERTIONS */
#define BR_ENABLE_ASSERTS = 1   //Turn assertions on

#ifdef BR_ENABLE_ASSERTS
    #define BR_ASSERT(x,...) { if(!(x)) { BR_ERROR("Assertion Failed: {0}",__VA_ARGS__);}}
    #define BR_CORE_ASSERT(x,...) { if(!(x)) { BR_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);}}
#else
    #define BR_ASSERT(x,...)
    #define BR_CORE_ASSERT(x,...)
#endif




#endif /* E0B05701_1CE6_4C6D_A363_FE30540EBD41 */
