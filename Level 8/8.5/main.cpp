// this is a program for practicing using exponential and poisson distribution
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>

#include <iostream>
#include <vector>
using namespace std;

int main() {
    using namespace boost::math;

    exponential_distribution<> myExponential(0.5); // Default type is 'double'
    cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;
    cout << endl; // print a new line

    // Distributional properties
    double x = 10.25;
    cout << "x= " << x << endl;
    cout << "pdf: " << pdf(myExponential, x) << endl;
    cout << "cdf: " << cdf(myExponential, x) << endl;
    cout << endl; // print a new line

    // Choose another data type and now default setting
    exponential_distribution<float> myExponential2;
    cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << endl;

    cout << "x = " << x << endl;
    cout << "pdf: " << pdf(myExponential2, x) << endl;
    cout << "cdf: " << cdf(myExponential2, x) << endl;
    cout << endl;

    // Choose precision
    cout.precision(10); // Number of values behind the comma

    // Print properties
    cout << "\n***Exponential distribution: \n";
    cout << "mean: " << mean(myExponential) << endl;
    cout << "variance: " << variance(myExponential) << endl;
    cout << "median: " << median(myExponential) << endl;
    cout << "mode: " << mode(myExponential) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "kurtosis: " << kurtosis(myExponential) << endl;
    cout << "characteristic function: " << chf(myExponential, x) << endl;
    cout << "hazard: " << hazard(myExponential, x) << endl;
    cout << endl;

    // Poisson distribution
    double lambda = 3.0; // Shape parameter, lambda
    poisson_distribution<double> myPoisson(lambda);
    cout << "***Poisson Distribution" << endl;

    double val = 13.0;
    cout << "x = " << val << endl;
    cout << "pdf: " << pdf(myPoisson, val) << endl;
    cout << "cdf: " << cdf(myPoisson, val) << endl;
    cout << endl;

    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0.0;
    double end = 10.0;
    long N = 30; // Number of subdivisions

    val = 0.0;
    double h = (end - start) / double(N);
    // Input the pdfList and cdfList
    for (long j = 1; j <= N; ++j) {
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));

        val += h;
    }
    // Output the pdfList
    for (long j = 0; j != pdfList.size(); ++j) {
        cout << pdfList[j] << ", ";
    }
    cout << endl;
    cout << "***" << endl;
    // Output the cdfList
    for (long j = 0; j != cdfList.size(); ++j) {
        cout << cdfList[j] << ", ";
    }

    return 0;
}