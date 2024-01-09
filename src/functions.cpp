#include "include/functions.h"
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdint>
#include <cstdlib>

namespace func {
    bool is_curious_fraq(func::frac f) {
        std::string numerator = std::to_string(f.numerator);
        std::string denominator = std::to_string(f.denominator);
        bool shares_digit = false;
        char common_char = ' ';
        bool result = false;

        //Does numerator and denominator share a digit?.
        for (int i = 0; i < static_cast<int>(numerator.length()); i++) {
            char test_char = numerator[i];
            if (denominator.find(test_char) != std::string::npos) {
                shares_digit = true;
                common_char = test_char;
            }
        }

        if (shares_digit) {
            numerator.erase(std::find(numerator.begin(), numerator.end(), common_char));
            denominator.erase(std::find(denominator.begin(), denominator.end(), common_char));

            double cancelled_frac = std::stod(numerator) / std::stod(denominator);
            double original_frac = static_cast<double>(f.numerator) / static_cast<double>(f.denominator);

            result = (cancelled_frac == original_frac);
        } else {
            result = false;
        }

        return result;
    }

    void reduce_frac(func::frac &f) {
        int64_t gcd_res = std::gcd(f.numerator, f.denominator);
        int64_t temp_numerator = f.numerator / gcd_res; //Arithmetic exception.
        int64_t temp_denominator = f.denominator / gcd_res;
        f = {.numerator = temp_numerator, .denominator = temp_denominator};
    }

    int64_t get_answer() {
        std::vector<func::frac> fracs;

        //Find the candidate fractions.
        for (int64_t a = 11; a <= 98; a++) {
            if (a % 10 != 0) {
                for (int64_t b = 12; b <= 99; b++) {
                    if (a < b) {
                        if (b % 10 != 0) {
                            func::frac f = {.numerator = a, .denominator = b};
                            if (is_curious_fraq(f)) {
                                fracs.push_back(f);
                            }
                        }
                    }
                }
            }
        }

        //Multiply candidate fractions together.
        int64_t numerator_product = 1;
        int64_t denominator_product = 1;

        for (func::frac f : fracs) {
            numerator_product = numerator_product * f.numerator;
            denominator_product = denominator_product * f.denominator;
        }

        //Declare and initialize product fraction struct.
        func::frac product_fraq = {.numerator = numerator_product, .denominator = denominator_product};

        //Reducing product fraction and returning denominator.
        reduce_frac(product_fraq);

        return product_fraq.denominator;
    }
}