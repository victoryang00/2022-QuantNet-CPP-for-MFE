#include "PerpAmeOption.h"
#include <vector>

//	global function declaration
std::vector<double> CutVec(const double &start, const double &h, const int &size);

//	main programme
int main() {
    //	required data set
    char call_type = 'C';
    char put_type = 'P';

    // Group B
    // b) Test the data with K=100, sig=0.1, r=0.1, b=0.02, S=110
    // result: C=18.5035, P=3.03106
    std::cout << "\nB b) Test Perpetual American Option pricing engine\n";
    PerpAmeOption american_option(0.1, 0.1, 100, 0.02, 110, call_type);
    american_option.Price(american_option.S);
    american_option.ShowPriceResult();
    american_option.toggle(); // put option
    american_option.Price(american_option.S);
    american_option.ShowPriceResult();

    auto rate = 0.0;
    std::vector<double> call_array;
    int kNumOptions = 20;

    // c) Plot the price of a call option with K=100, sig=0.1, r=0.1, b=0.02, S=110
    std::cout << "\nB c) Test for a range of underlying S\n";
    auto asset_price_array = CutVec(90, 1, 110);
    for (auto i : asset_price_array) {
        PerpAmeOption call_american_option(0.1, 0.1, 100, 0.02, i, call_type);
        call_array.push_back(call_american_option.Price(call_american_option.S));
    }
    for (auto i : call_array) {
        std::cout << i << "\n";
    }

    // d) test with number options
    std::cout << "\nB d) test with number options\n";

    std::vector<std::vector<double>> parameter_matrix2;
    parameter_matrix2.resize(kNumOptions); // allocates 20 empty row vectors
    asset_price_array = {105, 110, 115, 120};
    std::vector<double> volatility_array = {0.1, 0.2, 0.25, 0.15};
    std::vector<double> rate_array = {0.025, 0.05, 0.075, 0.1};
    std::vector<double> strike_price_array = {90, 92, 94, 96};

    // generate option parameters randomly from mesh array
    for (int i = 0; i < kNumOptions; i++) {
        rate = rate_array[std::rand() % rate_array.size()];
        parameter_matrix2[i].push_back(rate);
        parameter_matrix2[i].push_back(volatility_array[std::rand() % volatility_array.size()]);
        parameter_matrix2[i].push_back(strike_price_array[std::rand() % 4]);
        parameter_matrix2[i].push_back(rate / 5); // carry
        parameter_matrix2[i].push_back(asset_price_array[std::rand() % 4]);
    };

    PerpAmeOption american_option_matrix(parameter_matrix2, call_type);
    american_option_matrix.PriceWithMatrix();
    american_option_matrix.ShowMatrixPriceResult();
    american_option_matrix.toggle();
    american_option_matrix.PriceWithMatrix();
    american_option_matrix.ShowMatrixPriceResult();
}

//	global function body
std::vector<double> CutVec(const double &start, const double &h, const int &size) {
    std::vector<double> Proto; //	declare the std::vector to be returned
    Proto.reserve(size); //	reserve places for elements
    for (int i = 0; i != size; i++) { //	initialize elements according to requirement
        Proto.push_back(start + h * i);
    }
    return Proto;
}