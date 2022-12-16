B
a) Program the above formulae, and incorporate into your well-designed options pricing classes

The formulas are included in the PerpAmeOption class. `CallPrice()` and `PutPrice()` are two private functions that are programmed separately as needed. They are made private because calling distinct functions for various option types is not required by the user. Additionally, since type is one of an option's inherent parameters, calling `Price()` to get the price is natural.

b) Test the data with K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106)

result: call:18.5035, put: 3.03106. The results are consistent with the results from the previous question.

c) We now use the code in part a) to compute call and put option price for a monotonically increasing range of underlying values of S, for example 10, 11, 12, …, 50. To this end, the output will be a vector and this exercise entails calling the option pricing formulae in part a) for each value S and each computed option price will be stored in a std::vector<double> object. It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size h.

Run the programme and the results are on the console.

d) Incorporate this into your above matrix pricer code, so you can input a matrix of option parameters and receive a matrix of Perpetual American option prices.

Run the programme and the results are on the console.
