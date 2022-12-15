#include "PerpAmeOption.h"

// The function for getting Callprice for PerpAmeOption
double PerpAmeOption::CallPrice(const double &S) {
    // First to declare the price and temp vars
    double price, tmp1, tmp2, frac;

    // calculate parameters
    tmp1 = 0.5 - (b / (sig * sig));
    tmp2 = sqrt((-tmp1) * (-tmp1) + ((2 * r) / (sig * sig)));

    double y1 = tmp1 + tmp2;
    if (y1 == 1) { // final case
        return S;
    } else {
        frac = ((y1 - 1) / y1) * (S / K);
        price = (K / (y1 - 1)) * pow(frac, y1);
        return price;
    }
}
// The function for getting Putprice for PerpAmeOption
double PerpAmeOption::PutPrice(const double &S) {
    // First to declare the price and temp vars
    double price, tmp1, tmp2, frac;

    // calculate parameters
    tmp1 = 0.5 - (b / (sig * sig));
    tmp2 = sqrt((-tmp1) * (-tmp1) + ((2 * r) / (sig * sig)));

    double y2 = tmp1 - tmp2;
    if (y2 == 1) { // Special Case
        return S;
    } else {
        frac = ((y2 - 1) / y2) * (S / K);
        price = (K / (1 - y2)) * pow(frac, y2);
        return price;
    }
}

// constructors and destructor
PerpAmeOption::PerpAmeOption() : b(0), K(0), r(0), sig(0), type('C') {} // default constructor
PerpAmeOption::PerpAmeOption(double &b1, double &K1, double &r1, double &sig1, char &type1)
    : b(b1), K(K1), r(r1), sig(sig1), type(type1) {} // constructor with parameters
PerpAmeOption::PerpAmeOption(const PerpAmeOption &source)
    : b(source.b), K(source.K), r(source.r), sig(source.sig), type(source.type) {} // copy constructor
PerpAmeOption::~PerpAmeOption() {} // destructor

// price function
double PerpAmeOption::Price(const double &S) {
    if (type == 67) // perpetual call
    {
        return CallPrice(S);
    } else // perpetual put
    {
        return PutPrice(S);
    }
}

// modifiers
void PerpAmeOption::Type(const char &Type) // modify type
{
    type = Type;
}

// getters
char PerpAmeOption::Type() // see type
{
    return type;
}

// operator
PerpAmeOption &PerpAmeOption::operator=(const PerpAmeOption &source) // assignment operator
{
    if (&source != this) // handle self-assignment
    {
        // assign corresponding data members
        b = source.b;
        K = source.K;
        r = source.r;
        sig = source.sig;
        type = source.type;
    }
    return *this;
}