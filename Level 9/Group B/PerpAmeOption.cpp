#include "PerpAmeOption.h"

// The function for getting Callprice for PerpAmeOption
double PerpAmeOption::CallPrice(const double &S_) {
    S = S_;
    // First to declare the price and temp vars
    double tmp1, tmp2, frac;

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
double PerpAmeOption::PutPrice(const double &S_) {
    S = S_;
    // First to declare the price and temp vars
    double tmp1, tmp2, frac;

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
PerpAmeOption::~PerpAmeOption() = default; // destructor

// price function
double PerpAmeOption::Price(const double &S_) {
    S = S_;
    if (type == 'C') { // perpetual call
        return CallPrice(S);
    } else { // perpetual put
        return PutPrice(S);
    }
}

// modifiers
void PerpAmeOption::Type(const char &Type) { type = Type; } // modify type

// getters
char PerpAmeOption::Type() const { return type; } // get the type

// operator
PerpAmeOption &PerpAmeOption::operator=(const PerpAmeOption &source) { // assignment operator
    // handle self-assignment
    if (&source != this) {
        // assign corresponding data members
        b = source.b;
        K = source.K;
        r = source.r;
        sig = source.sig;
        type = source.type;
    }
    return *this;
}

void PerpAmeOption::toggle() {
    if (type == 'C') {
        type = 'P';
    } else {
        type = 'C';
    }
}

PerpAmeOption::PerpAmeOption(double r, double sig, double K, double b, double S, char &type)
    : r(r), sig(sig), K(K), b(b), S(S), type(type) {}

PerpAmeOption::PerpAmeOption(std::vector<std::vector<double>> parameter_matrix, char &type)
    : parameter_matrix(std::move(parameter_matrix)), type(type) {}

void PerpAmeOption::ShowPriceResult() {
    std::cout << "  C/P |   S   |   K   |  sig  |   r   |   b   |  price  \n";
    std::cout << std::setw(4) << type << "  |" << std::setw(5) << S << "  |" << std::setw(5) << K << "  |"
              << std::setw(5) << sig << "  |" << std::setw(5) << r << "  |" << std::setw(5) << b << "  |"
              << std::setw(8) << price << "\n";
}

void PerpAmeOption::ShowMatrixPriceResult() {
    std::cout << "  C/P |   S   |   K   |  r  |   sig   |   b   |  price  \n";
    for (int i = 0; i < parameter_matrix.size(); i++) {
        std::cout << std::setw(4) << type << "  |" << std::setw(5) << parameter_matrix[i][4] << "  |" << std::setw(5)
                  << parameter_matrix[i][2] << "  |" << std::setw(5) << parameter_matrix[i][3] << "  |" << std::setw(5)
                  << parameter_matrix[i][1] << "  |" << std::setw(5) << parameter_matrix[i][0] << "  |" << std::setw(8)
                  << price_vector[i] << "\n";
    }
}

std::vector<double> PerpAmeOption::PriceWithMatrix() {
    price_vector = {};
    for (auto row : parameter_matrix) {
        PerpAmeOption option(row[0], row[1], row[2], row[3], row[4], type);
        price_vector.push_back(option.Price(option.S));
    }
    return price_vector;
}
