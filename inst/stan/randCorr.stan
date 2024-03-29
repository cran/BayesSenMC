data {
  int<lower=0> a;
  int<lower=0> N1;
  int<lower=0> c;
  int<lower=0> N0;
  real mX0;
  real<lower=0> precX0;
  real mX1;
  real<lower=0> precX1;
  real mZ;
  real<lower=0> sZ;
  real mLogit_pi0;
  real<lower=0> sLogit_pi0;
  real mLOR_c;
  real<lower=0> sLOR_c;
}
parameters {
  // Parameter values that are too large will cause exponential to go to inf, causing nan
  real<lower=-200, upper=200> logit_pi0;
  real<lower=-200, upper=200> LOR_c;
  real<lower=-100, upper=100> Z;
  real<lower=-200, upper=200> X0;
  real<lower=-200, upper=200> X1;
}
transformed parameters {
  real<lower=0, upper=1> pi1;
  real<lower=0, upper=1> pi0;
  real<lower=0> ORadj;
  real<lower=0, upper=1> Se;
  real<lower=0, upper=1> Sp;
  real<lower=-1, upper=1> rhoSe; 
  real mcx1;
  real<lower=0> preccx1;
  real<lower=0, upper=1> p1;
  real<lower=0, upper=1> p0;
  rhoSe = (exp(2 * Z) - 1)/(1 + exp(2 * Z));
  mcx1 = mX1 + rhoSe * (X0 - mX0) * pow(precX1 / precX0, 0.5);
  preccx1 = precX1 / (1 - pow(rhoSe, 2) + 0.01); // offset by 0.01
  Se = (1 + exp(X0) / (1 + exp(X0))) / 2;
  Sp = (1 + exp(X1) / (1 + exp(X1))) / 2;
  pi0 = exp(logit_pi0) / (exp(logit_pi0) + 1);
  pi1 = exp(logit_pi0 + LOR_c) / (exp(logit_pi0 + LOR_c) + 1);
  p1 = pi1 * Se + (1 - pi1) * (1 - Sp);
  p0 = pi0 * Se + (1 - pi0) * (1 - Sp);
  ORadj = exp(LOR_c);
}
model {
  logit_pi0 ~ normal(mLogit_pi0, sLogit_pi0);
  LOR_c ~ normal(mLOR_c, sLOR_c);
  a ~ binomial(N1, p1);
  c ~ binomial(N0, p0);
  Z ~ normal(mZ, sZ);
  X0 ~ normal(mX0, (1/precX0)^0.5);
  X1 ~ normal(mcx1, (1/preccx1)^0.5);
}
