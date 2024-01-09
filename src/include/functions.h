#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    struct frac {
        int64_t numerator;
        int64_t denominator;
    };

    bool is_curious_fraq(func::frac f);
    void reduce_frac(func::frac &f);
    int64_t get_answer(); 
}

#endif