// include necessary file
#include "EUoption.h"
#include "OptionElements.h"

// declarationf for the main function
int main() {
    char call_type = 'C';
    char put_type = 'P'; // set type parameters

    // Group A - Exact Solutions of One-Factor Plain Option
    // a) & b) check 4 batches with BS formula, Put Call parity price
    std::cout << "A1 a) & b)";
    {
        std::cout << "Batch 1\n";
        using namespace Batch1;
        EUoption EUcall(K, T, r, sig, call_type);
        EUoption EUput(K, T, r, sig, put_type);
        // For outputting the Call Price
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD{}; // create an object of struct OptionData
        OptD.K = K;
        OptD.T = T;
        OptD.r = r;
        OptD.sig = sig; // initialize each member data with data in the batch

        double C1 = BSCallPrice(OptD, S); // calculate with struct version
        double P1 = BSPutPrice(OptD, S); // calculate with struct version
        std::cout << "Call-option price: " << C1 << ",Put-option price: " << P1 << "\n"; // print the result
        std::cout << "\n"; // print a new line

        std::cout << "Put-Call Parity Check, struct version:\n";
        PCParity(OptD, S, C1, call_type); // test struct version
        PCParity(OptD, S, P1, put_type); // test struct version
        std::cout << "\n"; // print a new line
    }
    {
        std::cout << "Batch 2\n";
        using namespace Batch2;
        EUoption EUcall(K, T, r, sig, call_type);
        EUoption EUput(K, T, r, sig, put_type);
        // For outputting the Call Price
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD{}; // create an object of struct OptionData
        OptD.K = K;
        OptD.T = T;
        OptD.r = r;
        OptD.sig = sig; // initialize each member data with data in the batch

        double C1 = BSCallPrice(OptD, S); // calculate with struct version
        double P1 = BSPutPrice(OptD, S); // calculate with struct version
        std::cout << "Call-option price: " << C1 << ",Put-option price: " << P1 << "\n"; // print the result
        std::cout << "\n"; // print a new line

        std::cout << "Put-Call Parity Check, struct version:\n";
        PCParity(OptD, S, C1, call_type); // test struct version
        PCParity(OptD, S, P1, put_type); // test struct version
        std::cout << "\n"; // print a new line
    }
    {
        std::cout << "Batch 3\n";
        using namespace Batch3;
        EUoption EUcall(K, T, r, sig, call_type);
        EUoption EUput(K, T, r, sig, put_type);
        // For outputting the Call Price
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD{}; // create an object of struct OptionData
        OptD.K = K;
        OptD.T = T;
        OptD.r = r;
        OptD.sig = sig; // initialize each member data with data in the batch

        double C1 = BSCallPrice(OptD, S); // calculate with struct version
        double P1 = BSPutPrice(OptD, S); // calculate with struct version
        std::cout << "Call-option price: " << C1 << ",Put-option price: " << P1 << "\n"; // print the result
        std::cout << "\n"; // print a new line

        std::cout << "Put-Call Parity Check, struct version:\n";
        PCParity(OptD, S, C1, call_type); // test struct version
        PCParity(OptD, S, P1, put_type); // test struct version
        std::cout << "\n"; // print a new line
    }
    {
        std::cout << "Batch 4\n";
        using namespace Batch4;
        EUoption EUcall(K, T, r, sig, call_type);
        EUoption EUput(K, T, r, sig, put_type);
        // For outputting the Call Price
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD{}; // create an object of struct OptionData
        OptD.K = K;
        OptD.T = T;
        OptD.r = r;
        OptD.sig = sig; // initialize each member data with data in the batch

        double C1 = BSCallPrice(OptD, S); // calculate with struct version
        double P1 = BSPutPrice(OptD, S); // calculate with struct version
        std::cout << "Call-option price: " << C1 << ",Put-option price: " << P1 << "\n"; // print the result
        std::cout << "\n"; // print a new line

        std::cout << "Put-Call Parity Check, struct version:\n";
        PCParity(OptD, S, C1, call_type); // test struct version
        PCParity(OptD, S, P1, put_type); // test struct version
        std::cout << "\n"; // print a new line
    }

    std::cout << "A1 c)\n";
    OptionData OptD{}; // create an object of struct OptionData
    OptD.K = Batch1::K;
    OptD.T = Batch1::T;
    OptD.r = Batch1::r;
    OptD.sig = Batch1::sig; // initialize each member data with data in the batch
    std::vector<double> asset_price = CutVec(10, 50, 1); // call Cut()
    std::vector<double> call_price;
    call_price.reserve(50); // reserve places for elements
    std::vector<double> put_price;
    put_price.reserve(50); // reserve places for elements
    std::cout << "S |       Put  |      Call\n";
    for (int i = 0; i != 40; i++) {
        call_price.push_back(BSCallPrice(OptD, asset_price[i])); // calculate call price
        put_price.push_back(BSPutPrice(OptD, asset_price[i])); // calculate put price
        std::cout << asset_price[i] << "|" << std::setw(12) << put_price[i] << "|  " << std::setw(12) << call_price[i]
                  << "\n"; // print the results
    }
    call_price.clear();
    put_price.clear();
    std::cout << "\n";

    std::cout << "A1 d)\n";

    // partd declare the neccessary containers of conditions change more variables
    auto rate_array = CutVec(0.02, 0.08, 0.02); // Creates Array Using CutVec
    auto maturity_array = CutVec(0.25, 2, 0.25); // Creates Array Using CutVec
    auto volatility_array = CutVec(0.1, 0.5, 0.05); // Creates Array Using CutVec
    auto strike_price_array = CutVec(50, 100, 10); // Creates Array Using CutVec
    auto asset_price_array = CutVec(50, 60, 1); // Creates Array Using CutVec

    // containers of results
    std::vector<std::vector<double>> parameter_matrix;
    std::vector<double> parameter_vector;
    int matrix_num = 20;
    int vector_num = 6;
    parameter_matrix.reserve(matrix_num); // reserve places for elements
    parameter_vector.reserve(vector_num); // reserve places for elements
    double rate = 0.0;
    // generate the random 1result from vector
    for (int i = 0; i < matrix_num; i++) {
        rate = rate_array[std::rand() % rate_array.size()];
        parameter_vector.push_back(rate);
        parameter_vector.push_back(volatility_array[std::rand() % volatility_array.size()]);
        parameter_vector.push_back(strike_price_array[std::rand() % 4]);
        parameter_vector.push_back(maturity_array[std::rand() % 4]);
        parameter_vector.push_back(rate);
        parameter_vector.push_back(asset_price_array[std::rand() % 4]);
        parameter_matrix.push_back(parameter_vector);
        parameter_vector.clear();
    };
    EUoption option_matrix(parameter_matrix, call_type); // create an object of EUoption
    option_matrix.PriceWithMatrix(); // print the result
    option_matrix.CalculateGreeksMatrix('D', 0);
    option_matrix.CalculateGreeksMatrix('G', 0);
    option_matrix.ShowMatrixPriceResult();
    std::cout << "\n"; // print a new line
    option_matrix.toggle(); // switch to put option
    option_matrix.PriceWithMatrix();
    option_matrix.CalculateGreeksMatrix('D', 0);
    option_matrix.CalculateGreeksMatrix('G', 0);
    option_matrix.ShowMatrixPriceResult();

    // A2
    // a) call and put future option greeks
    std::cout << "\nA2 a) \n";
    EUoption option(0.1, 0.36, 100.0, 0.5, 0.0, 105.0, 'C');
    std::cout << "Call option Delta: " << option.Delta(0) << " and Gamma:" << option.Gamma(0) << "\n";
    option.toggle(); // switch to put option
    std::cout << "Put option Delta: " << option.Delta(0) << " and Gamma:" << option.Gamma(0) << "\n";

    // test with difference h size to find optimal value
    asset_price_array = CutVec(10, 50, 1);

    std::vector<double> difference_array = {1, 0.1, 0.01, 0.001, 0.0001};

    std::cout << "\nA2 b) Delta with different h\n";
    std::cout << "  Analytical |   h = 1     |   h = 0.1   |   h = 0.01  |  h = 0.001  | h = 0.0001    \n";
    for (auto i : asset_price_array) {
        // Set option exercise price as K = 25
        EUoption call_option(0.1, 0.36, i, 0.5, 0, 25, 'C');
        std::cout << std::setw(12) << call_option.Delta(0) << " | ";
        for (double h : difference_array) {
            std::cout << std::setw(12) << call_option.ApprxDelta(25, h) << "| ";
        }
        std::cout << "\n";
    }

    std::cout << "\nA2 b) Gamma with different h\n";
    std::cout << "  Analytical |   h = 1     |   h = 0.1   |   h = 0.01  |  h = 0.001  | h = 0.0001 \n";
    for (auto i : asset_price_array) {
        // Set option exercise price as K = 25
        EUoption call_option(0.1, 0.36, i, 0.5, 0, 25, 'C');
        std::cout << std::setw(12) << call_option.Gamma(0) << " | ";
        for (double h : difference_array) {
            std::cout << std::setw(12) << call_option.ApprxGamma(25, h) << "| ";
        }
        std::cout << "\n";
    }

    std::cout << "\nA2 c) Delta with different h\n";
    std::vector<std::vector<double>> parameter_matrix2;
    parameter_matrix2.reserve(matrix_num);

    for (auto i : asset_price_array) {
        parameter_matrix2.push_back({0.1, 0.36, i, 0.5, 0, 25});
    }
    EUoption option_matrix2(parameter_matrix2, call_type); // create an object of EUoption
    option_matrix2.PriceWithMatrix(); // print the result
    option_matrix2.CalculateGreeksMatrix('D', 0);
    option_matrix2.CalculateGreeksMatrix('G', 0);
    option_matrix2.ShowMatrixPriceResult();
    std::cout << "\n"; // print a new line

    // d) Use h = 0.0001, calculate Greeks matrix again
    std::cout << "\n A2 d) Use finite difference calculate again\n";
    double h = 0.0001;
    option_matrix.PriceWithMatrix();
    option_matrix.CalculateGreeksMatrix('D', h);
    option_matrix.CalculateGreeksMatrix('G', h);
    option_matrix.ShowMatrixPriceResult();
    option_matrix.toggle(); // switch to put option
    option_matrix.PriceWithMatrix();
    option_matrix.CalculateGreeksMatrix('D', h);
    option_matrix.CalculateGreeksMatrix('G', h);
    option_matrix.ShowMatrixPriceResult();

    return 0;
}

// global functions function body
// call-option struct version
double BSCallPrice(const OptionData &OptD, const double &S) {
    // declare parameters
    double C, d1, d2, b; // price, parameter d1, parameter d2,cost of carry
    boost::math::normal_distribution<> N(0.0, 1.0); // standard normal distribution

    // calculate parameters
    b = OptD.r; // In Black-Scholes model
    d1 = (log(S / OptD.K) + (b + (OptD.sig * OptD.sig / 2)) * OptD.T) / (OptD.sig * sqrt(OptD.T));
    d2 = d1 - OptD.sig * sqrt(OptD.T);

    // calculate option price
    C = S * exp((b - OptD.r) * OptD.T) * cdf(N, d1) - OptD.K * exp(-OptD.r * OptD.T) * cdf(N, d2);

    return C;
}

// put-option struct version
double BSPutPrice(const OptionData &OptD, const double &S) {
    // declare parameters
    double P, d1, d2, b; // price, parameter d1, parameter d2,cost of carry
    boost::math::normal_distribution<> N(0.0, 1.0); // standard normal distribution

    // calculate parameters
    b = OptD.r; // In Black-Scholes model
    d1 = (log(S / OptD.K) + (b + (OptD.sig * OptD.sig / 2)) * OptD.T) / (OptD.sig * sqrt(OptD.T));
    d2 = d1 - OptD.sig * sqrt(OptD.T);

    // calculate option price
    P = OptD.K * exp(-OptD.r * OptD.T) * cdf(N, -d2) - S * exp((b - OptD.r) * OptD.T) * cdf(N, -d1);

    return P; // call plain version
}

// put-call parity struct version
double PCParity(const OptionData &OptD, const double &S, const double &price, const char &type) {
    double parityP;
    if (type == 'C') // if the input is a call-option price
    {
        parityP = price + OptD.K * exp(-OptD.r * OptD.T) - S;
    } else // if the input is a put-option price
    {
        parityP = price + S - OptD.K * exp(-OptD.r * OptD.T);
    }

    // print the result
    std::cout << "Original option type: " << type << "\n"; // benchmark type
    std::cout << "Price according to Put-Call Parity: " << parityP << "\n"; // result

    return parityP;
}

// produces a mesh array of doubles separated by a mesh size h
std::vector<double> CutVec(const double &start, const double &h, const double &size) {
    std::vector<double> mesh_array;
    double value = start;
    while (value <= h) {
        mesh_array.push_back(value);
        value += size;
    }
    return mesh_array;
}