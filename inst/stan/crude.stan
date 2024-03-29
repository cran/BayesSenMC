data {
  int<lower=0> a;
  int<lower=0> N1;
  int<lower=0> c;
  int<lower=0> N0;
  real mLogit_pi0;
  real<lower=0> sLogit_pi0;
  real mLOR_c;
  real<lower=0> sLOR_c;
}
parameters {
  // Parameter values that are too large will cause exponential to go to inf, causing nan
  real<lower=-200, upper=200> logit_pi0;
  real<lower=-200, upper=200> LOR_c;
}
transformed parameters {
  real<lower=0, upper=1> pi1;
  real<lower=0, upper=1> pi0;
  real<lower=0> ORadj;
  pi0 = exp(logit_pi0) / (exp(logit_pi0) + 1);
  pi1 = exp(logit_pi0 + LOR_c) / (exp(logit_pi0 + LOR_c) + 1);
  ORadj = exp(LOR_c);
}
model {
  logit_pi0 ~ normal(mLogit_pi0, sLogit_pi0);
  LOR_c ~ normal(mLOR_c, sLOR_c);
  a ~ binomial(N1, pi1);
  c ~ binomial(N0, pi0);
}
