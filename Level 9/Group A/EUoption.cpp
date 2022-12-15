#include "EUoption.h"

#include <utility>
using namespace boost::math;

// constructors and destructor
EUoption::EUoption() : K(0), T(0), r(0), sig(0), type('C'), b(0) {} // default constructor
// Construct from matrix
EUoption::EUoption(std::vector<std::vector<double>> parameter_matrix, char &type)
    : type(type), parameter_matrix(std::move(parameter_matrix)) {}

EUoption::EUoption(double r, double sig, double K, double T, double b, double S, char type)
    : K(K), T(T), r(r), sig(sig), type(type), b(b), S(S) {} // constructor with parameters

EUoption::EUoption(double &K1, double &T1, double &r1, double &sig1, char &type1)
    : K(K1), T(T1), r(r1), sig(sig1), type(type1), b(r1) {} // constructor with parameters

EUoption::EUoption(const EUoption &source)
    : K(source.K), T(source.T), r(source.r), sig(source.sig), type(source.type), b(source.b), S(source.S),
      price(source.price), delta(source.delta), gamma(source.gamma) {} // copy constructor

EUoption::~EUoption() = default; // destructor

// price function
double EUoption::Price(const double &S_) { // calculate option price
    S = S_;
    // declare parameters
    double p, d1, d2; // p, parameter d1, parameter d2,cost of carry
    boost::math::normal_distribution<> N; // standard normal distribution

    // calculate parameters
    d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * sqrt(T));
    d2 = d1 - sig * sqrt(T);

    // calculate p according to different type
    if (type == 'C') {
        p = S * exp((b - r) * T) * cdf(N, d1) - K * exp(-r * T) * cdf(N, d2);
    } else {
        p = K * exp(-r * T) * cdf(N, -d2) - S * exp((b - r) * T) * cdf(N, -d1);
    }
    price = p;
    return price;
}

// modifiers
void EUoption::ModelParameter(const double &para) { // modify b for different model
    b = para;
}
void EUoption::Type(const char &Type) { // modify type
    type = Type;
}

// getters
double EUoption::ModelParameter() const { // see model used
    return b;
}
char EUoption::Type() const { // see type
    return type;
}

// sensitivities
double EUoption::Delta(const double &S_) { // delta
    // necessary parameters
    boost::math::normal_distribution<> N(0.0, 1.0);

    if (S_ > 0) { // if the asset price is configured
        S = S_;
        // calculate parameter
        double d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * sqrt(T));

        // calculate delta price according to different type
        if (type == 'C') {
            delta = exp((b - r) * T) * cdf(N, d1);
        } else { // put
            delta = -exp((b - r) * T) * cdf(N, -d1);
        }
        return delta;
    } else {
        if (type == 'C') {
            double tmp = sig * sqrt(T);
            double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
            delta = exp((b - r) * T) * cdf(N, d1);
            return delta;
        } else {
            double tmp = sig * sqrt(T);
            double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
            delta = exp((b - r) * T) * (cdf(N, d1) - 1.0);
            return delta;
        }
    }
}
double EUoption::Gamma(const double &S_) // gamma
{
    // update the current asset price
    boost::math::normal_distribution<> N(0.0, 1.0);

    if (S_ > 0) { // calculate parameters
        S = S_;
        double d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * sqrt(T));
        gamma = (pdf(N, d1) * exp((b - r) * T)) / (S * sig * sqrt(T));

        return gamma;
    } else {
        double tmp = sig * sqrt(T);
        double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
        double A = 1.0 / sqrt(2.0 * 3.1415);
        gamma = A * exp(-d1 * d1 * 0.5) * exp((b - r) * T) / (S * sig * sqrt(T));
        return gamma;
    }
}
double EUoption::ApprxDelta(const double &S_, const double &h) { // approximate delta
    auto s = S_;
    auto res = (Price(s + h) - Price(s - h)) / (2 * h);
    S = s;
    return res;
}
double EUoption::ApprxGamma(const double &S_, const double &h) { // approximate gamma
    auto s = S_;
    auto res = (Price(s + h) - 2 * Price(s) + Price(s - h)) / (h * h);
    S = s;
    return res;
}

// operator
EUoption &EUoption::operator=(const EUoption &source) // assignment operator
{
    if (&source != this) // handle self-assignment
    {
        // assign corresponding parameters
        b = source.b;
        type = source.type;
        K = source.K;
        T = source.T;
        r = source.r;
        sig = source.sig;
    }
    return *this;
}

// friend
double ParityPrice(const double &S, EUoption &source) // calculate price according to put-call parity
{
    if (source.type == 'C') { // original type=call
        return (source.Price(S) + source.K * exp(-source.r * source.T) - S); // return parity pull price
    } else // original type=put
    {
        return (source.Price(S) + S - source.K * exp(-source.r * source.T)); // return parity call price
    }
}

void EUoption::showMatrixPriceResult() {
    std::cout << "  C/P |   S   |   K   |   T   |  sig  |   r   |   b   |   price      |    Delta     |   Gamma \n";
    for (int i = 0; i < parameter_matrix.size(); i++) {
        std::cout << std::setw(4) << type << "  |" << std::setw(5) << parameter_matrix[i][5] << "  |" << std::setw(5)
                  << parameter_matrix[i][2] << "  |" << std::setw(5) << parameter_matrix[i][3] << "  |" << std::setw(5)
                  << parameter_matrix[i][1] << "  |" << std::setw(5) << parameter_matrix[i][0] << "  |" << std::setw(5)
                  << parameter_matrix[i][4] << "  |" << std::setw(12) << price_vector[i] << "  |" << std::setw(12)
                  << delta_vector[i] << "  |" << std::setw(12) << gamma_vector[i] << "\n";
    }
}

std::vector<double> EUoption::PriceWithMatrix() {
    price_vector = {};
    for (std::vector<double> row : parameter_matrix) {
        EUoption option(row[0], row[1], row[2], row[3], row[4], row[5], type);
        price_vector.push_back(option.Price(option.S));
    }
    return price_vector;
}

void EUoption::toggle() {
    if (type == 'C') {
        type = 'P';
    } else {
        type = 'C';
    }
}

std::vector<double> EUoption::CalculateGreeksMatrix(const char &greek, double h) {
    if (greek == 'D') {
        delta_vector = DeltaMatrix(h);
        return delta_vector;
    } else if (greek == 'G') {
        gamma_vector = GammaMatrix(h);
        return gamma_vector;
    }
    return std::vector<double>(parameter_matrix.size(), 0);
}

std::vector<double> EUoption::GammaMatrix(double h) {
    gamma_vector = {};
    for (auto row : parameter_matrix) {
        EUoption option(row[0], row[1], row[2], row[3], row[4], row[5], type);
        if (h == 0) {
            gamma_vector.push_back(option.Gamma(h));
        } else {
            gamma_vector.push_back(option.ApprxGamma(option.S, h));
        }
    }
    return gamma_vector;
}
std::vector<double> EUoption::DeltaMatrix(double h) {
    delta_vector = {};
    for (auto row : parameter_matrix) {
        EUoption option(row[0], row[1], row[2], row[3], row[4], row[5], type);
        if (h == 0) {
            delta_vector.push_back(option.Delta(h));
        } else {
            delta_vector.push_back(option.ApprxDelta(option.S, h));
        }
    }
    return delta_vector;
}
// Show single option price result
void EUoption::ShowPriceResult() {
    std::cout << "  C/P |   S   |   K   |   T   |  sig  |   r   |   b   |  price  \n";
    std::cout << std::setw(4) << type << "  |" << std::setw(5) << S << "  |" << std::setw(5) << K << "  |"
              << std::setw(5) << T << "  |" << std::setw(5) << sig << "  |" << std::setw(5) << r << "  |"
              << std::setw(5) << b << "  |" << std::setw(8) << Price(S) << "\n";
}

// Print a table of option prices
void EUoption::ShowMatrixPriceResult() {
    std::cout << "  C/P |   S   |   K   |   T   |  sig  |   r   |   b   |   price      |    Delta     |   Gamma \n";
    for (int i = 0; i < parameter_matrix.size(); i++) {
        std::cout << std::setw(4) << type << "  |" << std::setw(5) << parameter_matrix[i][5] << "  |" << std::setw(5)
                  << parameter_matrix[i][2] << "  |" << std::setw(5) << parameter_matrix[i][3] << "  |" << std::setw(5)
                  << parameter_matrix[i][1] << "  |" << std::setw(5) << parameter_matrix[i][0] << "  |" << std::setw(5)
                  << parameter_matrix[i][4] << "  |" << std::setw(12) << price_vector[i] << "  |" << std::setw(12)
                  << delta_vector[i] << "  |" << std::setw(12) << gamma_vector[i] << "\n";
    }
}