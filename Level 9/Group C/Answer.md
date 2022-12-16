b) The results are listed below.

In general, the outcome is more accurate the greater N and Nsim are. There is no assurance, nevertheless, that higher N and Nsim would invariably produce superior outcomes. On occasion, accuracy decreases when N or Nsim increases. Additionally, the accuracy does not significantly increase when N increases from 500 to 10,000. (see 5 and 7). Additionally, the accuracy remains same when Nsim is increased from 100000 to 5000000. (for call option, put option get 2 decimal places accuracy). Trials 5 and 8 with N=5000 and Nsim=100000 and N=500 and Nsim=5000000, respectively, both meet the criteria for accuracy. For call prices, the simulation outcome is typically more accurate. 10e7 trials weren't conducted since they would have taken too long. Actually, calling/putting on my pc for N=500, Nsim=5000000 takes too long per trial.


Batch 1:
Accurate result:call: 2,13337, put: 5.84628

1)N=100,Nsim=50000
Put=5.88104;
Call=2.12126; SD=4.41977; SE=0.0197658

2)N=100,Nsim=100000
Put=5.8726;
Call=2.13295; SD=4.4403; SE=0.0140415

3)N=500,Nsim=100000
Put=5.83729;
Call=2.14885; SD=4.46656; SE=0.0141245

4)N=500,Nsim=500000
Put=5.85758;Call=2.12824;

5)N=1000,Nsim=100000
Put=5.86757;Call=2.13874;

6)N=5000,Nsim=100000
Put=5.84083;Call=2.13611;
(This trial is accurate enough)

7)N=10000,Nsim=100000
Put=;Call=2.14927;
(goes exeption here)

8)N=500,Nsim=5000000
Put=5.84206; SD=5.9259;SE=0.00264996
Call=2.13419;SD=4.4276;SE=0.00198008;
(This trial is accurate enough)


Batch 2:
Accurate result:call:7.96557, put:7.96557

Compared to batch 1, this batch's results are more erratic, although overall trends are very similar. I twice completed steps 8) for put and 1)-3) for call (made adjustments to SD and SE functions). The odd thing was that the pricing from the two experiments were exactly the same. I'm unsure if this is the result of a roundabout issue or a specific RNG behavior trend. In addition, the call price trends in trials 2, 3, and 7 appear to be anomalous, and I was unable to come up with a plausible explanation for them. I ruled out the notion that this phenomena happened by coincidence because trials with identical conditions would produce equal results. As N increases, accuracy severely decreases. However, the tendency is different for put prices (normal trend). This implies that there can be several N and Nsim ideal combinations for put and call. Also, the movement of the put and call prices appears to be opposing (in a particular trial, if put price is larger than exact price, call price would be smaller than exact price, and vise versa.) For call prices, the simulation findings are typically more accurate.

1)N=100,Nsim=50000
Put=8.03004;
Call=7.92938; SD=13.1344; SE=0.0587386

2)N=100,Nsim=100000
Put=8.01715;
Call=7.96187; SD=13.183; SE=0.0416881

3)N=500,Nsim=100000
Put=7.95242;
Call=8.0094 ; SD=13.2491; SE=0.0418746

4)N=500,Nsim=500000
Put=7.98069;Call=7.94493 ;

5)N=1000,Nsim=100000
Put=7.99353;Call=7.9618 ;

6)N=5000,Nsim=100000
Put=;Call=7.98338;

7)N=10000,Nsim=100000
Put=7.93787;Call=8.02154;

8)N=500,Nsim=5000000
Put=7.95846;SD=10.3996;SE=0.00465086;
Call=7.96951;
(The call is accurate enough)

c) Stress Test

Results for put prices are typically more accurate.

From the first four findings, it appears that the simulations had more difficulty in Batch 4 than in Batches 1 and 2. The 5000000 times simulation is only accurate to one decimal point for the put option, while it is completely inaccurate for the call option (call price is more volatile). Additionally, batch 4 appears to have a slower rate of convergence than the other two batches (there is no significant improvement in accuracy from 100000 to 5000000 times of trial). It is feasible that increasing Nsim to 1e7 or even larger will result in accuracy for the put and call of two decimal places and the unit digit, respectively. N may have a greater impact on accuracy than Nsim because T=30 in batch 4, which is significantly larger than that of batches 1 and 2. By comparing 1)5) and 1)4) for the call option, the aforementioned is confirmed (although the validity is slightly impaired by the difference in the percentage at which N and Nsim increases in the two groups). Additionally, as N increases, there is a discernible decline in volatility for call options. However, there is no discernible improvement in the put price. It's very possible that trial 6 would produce one- or two-decimal-place precision for call, but if I ever tried to run the experiment, it would take too much time.

Batch 4:
Accurate result:call:92.1757, put:1.2475

1)N=500, Nsim=100000
Put=1.25552; SD=0.223297; SE=0.000706127
Call=93.0212; SD=31.6893; SE=0.10021

2)N=500,Nsim=500000
Put=1.25896; SD=0.223555; SE=0.000316154
Call=91.7952; SD=33.7117; SE=0.0476755

3)N=500,Nsim=1000000
Put=1.25418; SD=0.223289; SE=0.000223289
Call=91.9222; SD=34.6141; SE=0.0346141

4)N=500,Nsim=5000000
Put=1.2538; SD=0.223135; SE=9.97892e-005
Call=91.8413; SD=33.8539; SE=0.0151399

5)N=30000, Nsim=100000
Put=1.23709; SD=0.221494; SE=0.000700426;
Call=92.2201; SD=28.4112; SE=0.0898442
