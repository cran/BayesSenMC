data {
  int<lower=0> a;
  int<lower=0> N1;
  int<lower=0> c;
  int<lower=0> N0;
  real mX;
  real mY;
  real sdX;
  real sdY;
  real mLogit_pi0;
  real<lower=0> sLogit_pi0;
  real mLOR_c;
  real<lower=0> sLOR_c;
}
parameters {
  // Parameter values that are too large will cause exponential to go to inf, causing nan
  real<lower=-200, upper=200> logit_pi0;
  real<lower=-200, upper=200> LOR_c;
  real<lower=-200, upper=200> X;
  real<lower=-200, upper=200> Y;
}
transformed parameters {
  real<lower=0, upper=1> pi1;
  real<lower=0, upper=1> pi0;
  real<lower=0> ORadj;
  real<lower=0, upper=1> p1;
  real<lower=0, upper=1> p0;
  real<lower=0, upper=1> Se;
  real<lower=0, upper=1> Sp;
  Se=(1 + exp(X)/(1 + exp(X))) / 2;
  Sp=(1 + exp(Y)/(1 + exp(Y))) / 2;
  pi0 = exp(logit_pi0) / (exp(logit_pi0) + 1);
  pi1 = exp(logit_pi0 + LOR_c) / (exp(logit_pi0 + LOR_c) + 1);
  p1 = pi1 * Se + (1 - pi1) * (1 - Sp);
  p0 = pi0 * Se + (1 - pi0) * (1 - Sp);
  ORadj = exp(LOR_c);
}
model {
  logit_pi0 ~ normal(mLogit_pi0, sLogit_pi0);
  LOR_c ~ normal(mLOR_c, sLOR_c);
  X ~ normal(mX, sdX);
  Y ~ normal(mY, sdY);
  a ~ binomial(N1, p1);
  c ~ binomial(N0, p0);
}
