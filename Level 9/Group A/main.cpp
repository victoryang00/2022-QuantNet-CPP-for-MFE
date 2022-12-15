// include necessary file
#include "EUoption.h"
#include "OptionElements.h"

// declarationf for the main function
int main() {
    using namespace Batch1; // The result is call:2,13337, put: 5.84628
    // using namespace Batch2; // The result is call:7.96557, put:7.96557
    // using namespace Batch3; // The result is call:0.204058, put:4.07326
    // using namespace Batch4; // The result is call:92.1757, put:1.2475

    char call_type = 'C';
    char put_type = 'P'; // set type parameters
    EUoption EUcall(K, T, r, sig, call_type);
    EUoption EUput(K, T, r, sig, put_type);
    // For outputing the Clal
    std::cout << "Call-option price: " << EUcall.Price(S) << ",Put-option price: " << EUput.Price(S) << "\n";

    // put-call parity test, all 4 batches passed
    std::cout << "Call-parity for put: " << ParityPrice(S, EUcall) << ", Put-parity for call: " << ParityPrice(S, EUput)
              << "\n";
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

    // partd declare the neccessary containers of conditions
    std::vector<double> StockP = CutVec(10, 1, 50); // call Cut()
    std::vector<double> ExpTime = CutVec(0.25, 0.25, 50); // Call Cut
    std::vector<double> Volatility = CutVec(0.01, 0.001, 50); // Call Cut

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
        std::cout << "ExpTime to Maturity: " << ExpTime[i] << ", Call Price: " << Output1[i] << ", Put Price:" << Output2[i]
                  << "\n"; // print the results
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
        std::cout << "Volatility: " << Volatility[i] << ", Call Price: " << Output1[i] << ", Put Price:" << Output2[i]
                  << "\n"; // print the results
    }
    Output1.clear();
    Output2.clear();
    std::cout << "\n";

    // delta
    K = 100;
    S = 105;
    T = 0.5;
    r = 0.1;
    sig = 0.36;
    double b = 0; // required data
    std::vector<double> H = CutVec(0.1, 0.05, 10); // step length used in approximation

    EUoption EUcall1(K, T, r, sig, call_type);
    EUcall1.ModelParameter(b);
    EUoption EUput1(K, T, r, sig, put_type);
    EUput1.ModelParameter(b);

    std::cout << "delta call: " << EUcall1.Delta(S) << ", delta put: " << EUput1.Delta(S)
              << "\n"; // results: call:0.594629, put:-0.356601
    std::cout << "gamma: " << EUcall1.Gamma(S) << "\n";
    std::cout << "\n";

    std::cout << "Approximated version:\n";
    for (int i = 0; i != 10; i++) {
        std::cout << "Step length: " << H[i] << "\n";
        std::cout << "delta call: " << EUcall1.ApprxDelta(S, H[i]) << ", delta put: " << EUput1.ApprxDelta(S, H[i])
                  << ", gamma: " << EUcall1.ApprxGamma(S, H[i]) << "\n";
    }
    std::cout << "\n";

    // series delta test
    for (int i = 0; i != 50; i++) {
        Output1.push_back(EUcall1.Delta(StockP[i]));
        Output2.push_back(EUput1.Delta(StockP[i]));
        std::cout << "Stock Price: " << StockP[i] << ", delta call: " << Output1[i] << ", delta put: " << Output2[i]
                  << "\n";
    }
    Output1.clear();
    Output2.clear();
    std::cout << "\n";

    // approximate deltas
    std::cout << "Approximate deltas:\n";
    double h = 0.5;
    for (int i = 0; i != 50; i++) {
        Output1.push_back(EUcall1.ApprxDelta(StockP[i], h));
        Output2.push_back(EUput1.ApprxDelta(StockP[i], h));
        std::cout << "Stock Price: " << StockP[i] << ", Approx delta call: " << Output1[i]
                  << ", Approx delta put: " << Output2[i] << "\n";
    }
    Output1.clear();
    Output2.clear();
    std::cout << "\n";
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
std::vector<double> CutVec(const double &start, const double &h, const int &size) {
    std::vector<double> Proto; // declare the std::vector to be returned
    Proto.reserve(size); // reserve places for elements
    for (int i = 0; i != size; i++) // initialize elements according to requirement
    {
        Proto.push_back(start + h * i);
    }
    return Proto;
}