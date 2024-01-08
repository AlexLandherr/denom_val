#include "include/functions.h"
#include <iostream>

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe
that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value,
and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

int main() {
    /* func::frac t = {.numerator = 49, .denominator = 98};
    std::cout << "Is " << t.numerator << "/" << t.denominator << " a curious fraction?: " << std::boolalpha << func::is_curious_fraq(t) << '\n';
    func::reduce_frac(t);
    std::cout << "Numerator: " << t.numerator << " Denominator: " << t.denominator << '\n'; */
    std::cout << "The answer: " << func::get_answer() << '\n';

    return 0;
}