// include necessary file
#include "EUoption.h"
#include "OptionElements.h"

// declarationf for the main function
int main() {
    // using namespace Batch1;
    // using namespace Batch2;
    // using namespace Batch3;
    // using namespace Batch4;
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
        // For outputing the Clal
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD; // create an object of struct OptionData
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
        // For outputing the Clal
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD; // create an object of struct OptionData
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
        // For outputing the Clal
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD; // create an object of struct OptionData
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
        // For outputing the Clal
        std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

        // put-call parity test, all 4 batches passed
        std::cout << "Call-parity for put: " << ParityPrice(S, EUcall)
                  << ", Put-parity for call: " << ParityPrice(S, EUput) << "\n";
        std::cout << "\n"; // print a new line

        // struct version of each function
        std::cout << "Struct Test:\n";
        OptionData OptD; // create an object of struct OptionData
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

        std::cout << "A1 c) using batch 4\n";
        // partd declare the neccessary containers of conditions
        std::vector<double> StockP = CutVec(10, 1, 50); // call Cut()
        std::vector<double> ExpTime = CutVec(0.25, 0.25, 50); // Call Cut()
        std::vector<double> Volatility = CutVec(0.01, 0.001, 50); // Call Cut()

        // containers of results
        std::vector<double> Output1;
        Output1.reserve(50); // reserve places for elements
        std::vector<double> Output2;
        Output2.reserve(50); // reserve places for elements

        // calculate option price for different stock prices (other parameters in batches remain the same as before)
        std::cout << "Option price for different stock price:\n";
        for (int i = 0; i != 50; i++) {
            Output1.push_back(BSCallPrice(OptD, StockP[i])); // calculate call price
            Output2.push_back(BSPutPrice(OptD, StockP[i])); // calculate put price
            std::cout << "Stock Price: " << StockP[i] << ", Call Price: " << Output1[i] << ", Put Price:" << Output2[i]
                      << "\n"; // print the results
        }
        Output1.clear();
        Output2.clear();
        std::cout << "\n";

        // calculate option price for different time to maturity (other parameters in batches remain the same as before)
        std::cout << "Option price for different time to maturity:\n";
        for (int i = 0; i != 50; i++) {
            OptD.T = ExpTime[i];
            Output1.push_back(BSCallPrice(OptD, S)); // calculate call price
            Output2.push_back(BSPutPrice(OptD, S)); // calculate put price
            std::cout << "ExpTime to Maturity: " << ExpTime[i] << ", Call Price: " << Output1[i]
                      << ", Put Price:" << Output2[i] << "\n"; // print the results
        }
        Output1.clear();
        Output2.clear();
        std::cout << "\n";

        // calculate option price for different volatility with other param not changed
        std::cout << "Option price for different stock price volatility:\n";
        for (int i = 0; i != 50; i++) {
            OptD.sig = Volatility[i];
            Output1.push_back(BSCallPrice(OptD, S)); // calculate call price
            Output2.push_back(BSPutPrice(OptD, S)); // calculate put price
            std::cout << "Volatility: " << Volatility[i] << ", Call Price: " << Output1[i]
                      << ", Put Price:" << Output2[i] << "\n"; // print the results
        }
        Output1.clear();
        Output2.clear();
        std::cout << "\n";
    }

    std::cout << "A1 d)\n";

    // partd declare the neccessary containers of conditions change more variables
    std::vector<double> rate_array = CutVec(0.02, 0.08, 0.02); // call Cut()
    std::vector<double> maturity_array = CutVec(0.25, 2, 0.25); // Call Cut()
    std::vector<double> volatility_array = CutVec(0.1, 0.5, 0.05); // Call Cut()
    std::vector<double> strike_price_array = CutVec(50, 100, 10); // Call Cut()
    std::vector<double> asset_price_array = CutVec(50, 60, 1); // Call Cut()

    // containers of results
    std::vector<std::vector<double>> parameter_matrix;
    int num = 20;
    parameter_matrix.reserve(num); // reserve places for elements
    double rate = 0.0;
    // generate the random result from vector
    for (int i = 0; i < num; i++) {
        rate = rate_array[rand() % rate_array.size()];
        parameter_matrix[i].push_back(rate);
        parameter_matrix[i].push_back(volatility_array[rand() % volatility_array.size()]);
        parameter_matrix[i].push_back(strike_price_array[rand() % 4]);
        parameter_matrix[i].push_back(maturity_array[rand() % 4]);
        parameter_matrix[i].push_back(rate);
        parameter_matrix[i].push_back(asset_price_array[rand() % 4]);
    };
    EUoption option_matrix();
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
    std::vector<double> Proto; // declare the std::vector to be returned
    Proto.reserve(size); // reserve places for elements
    for (int i = 0; i != size; i++) // initialize elements according to requirement
    {
        Proto.push_back(start + h * i);
    }
    return Proto;
}