A.1
a) Implement the above formulae for call and put option pricing using the data sets Batch 1 to Batch 4 . Check your answers, as you will need them when we discuss numerical methods for option pricing

Batch1: call:2,13337, put: 5.84628
Batch2: call:7.96557, put:7.96557
Batch3: call:0.204058, put:4.07326
Batch4: call:92.1757, put:1.2475

b) Apply the put-call parity relationship to compute call and put option prices. For example, given the call price, compute the put price based on this formula using Batches 1 to 4 . Check your answers with the prices from part a). Note that there are two useful ways to implement parity: As a mechanism to calculate the call (or put) price for a corresponding put (or call) price, or as a mechanism to check if a given set of put/call prices satisfy parity. The ideal submission will neatly implement both approaches.

The 4 batches passed the test, with the number exactly the same with the first question's result. I use diffent OptionElement with different namespace.

c) Say we wish to compute option prices for a monotonically increasing range of underlying values of S, for example $10,11,12, \ldots, 50$. To this end, the output will be a vector. This entails calling the option pricing formulae for each value $S$ and each computed option price will be stored in a std:: vector<double> object. It will be useful to write a global function that produces a mesh array of doubles separated by a mesh size $h$.

The 4 batches passed the test, with the number exactly the same with the first question's result. Declarations of functions with structs as argument are in OptionElement.h. Function bodies are at the bottom of main.cpp.

d) Now we wish to extend part $\mathbf{c}$ and compute option prices as a function of i) expiry time, ii) volatility, or iii) any of the option pricing parameters. Essentially, the purpose here is to be able to input a matrix (vector of vectors) of option parameters and receive a matrix of option prices as the result. Encapsulate this functionality in the most flexible/robust way you can think of.

Just see the consle for output


A.2
a) Implement the above formulae for gamma for call and put future option pricing using the data set: $K=100$, $\mathrm{S}=105, \mathrm{~T}=0.5, \mathrm{r}=0.1, \mathrm{~b}=0$ and $\mathrm{sig}=0.36$. (exact delta call $=0.5946$, delta put $=-0.3566$ ).
The exact number is call:0.594629, put:-0.356601. The differences in accuracy between these results and those in the homework are possibly because of the use of normal distribution pdf and cdf in boost math.

b/c) We now use the code in part a to compute call delta price for a monotonically increasing range of underlying values of $\mathrm{S}$, for example $10,11,12, \ldots, 50$. To this end, the output will be a vector and it entails calling the above formula for a call delta for each value $S$ and each computed option price will be store in a std: : vector<double $>$ object. It will be useful to reuse the above global function that produces a mesh array of double separated by a mesh size $h$./ Incorporate this into your above matrix pricer code, so you can input a matrix of option parameters and receive a matrix of either Delta or Gamma as the result.

Run the project and results are on the console.

d) We now use divided differences to approximate option sensitivities. In some cases, an exact formula may not
exist (or is difficult to find) and we resort to numerical methods. In general, we can approximate first and
second-order derivatives in S by 3-point second order approximations.

Run the project and results are on the console.